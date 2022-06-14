// Programming by Eric Chauvin.
// Notes on this source code are at:
// http://eric7apps.blogspot.com/

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;


namespace ExampleServer
{
  class X509ObjectID
  {
  private string StatusString = "";
  private string StringValue = "";



  internal string GetStatusString()
    {
    string Result = StatusString;
    StatusString = "";
    return Result;
    }


  internal string GetStringValue()
    {
    return StringValue;
    }



  internal bool MakeFromBytes( byte[] CodedBytes )
    {
    try
    {
    if( CodedBytes == null )
      {
      StatusString += "CodedBytes is null.\r\n";
      return false;
      }

    if( CodedBytes.Length < 2 )
      {
      StatusString += "The Length can't be right for this OID.\r\n";
      return false;
      }

    int FirstOIDByte = CodedBytes[0];

    // 1.2.840.113549
    // The first two numbers (like 1.2) are put in the first byte.
    // Part1 can only be 1, 2 or 3.
    int Part1 = FirstOIDByte / 40;
    int Part2 = FirstOIDByte % 40;
    // StatusString += "Part1: " + Part1.ToString() + "\r\n";
    // StatusString += "Part2: " + Part2.ToString() + "\r\n";

    string NumberS = Part1.ToString() + "." + Part2.ToString() + ".";

    int Index = 1;
    byte[] HoldOneBuf = new byte[8];
    // while( don't do this forever )
    for( int CountWhile = 0; CountWhile < 1000; CountWhile++ )
      {
      int HowMany = 0;
      for( int Count = 0; Count < 8; Count++ )
        {
        byte OneByte = CodedBytes[Index];
        Index++;

        HoldOneBuf[Count] = (byte)(OneByte & 0x7F);
        HowMany++;
        // The high bit marks it for continuing or not.
        if( (OneByte & 0x80) == 0 )
          break;

        if( Index >= CodedBytes.Length )
          {
          // The high bit was checked above this point.
          // Not that a server or man-in-the-middle will always send you correct data.
          StatusString += "This should never happen if it's marked correctly.\r\n";
          StatusString += "Index >= CodedBytes.Length.\r\n";
          return false;
          }
        }

      ulong OneNumber = GetOneNumber( HoldOneBuf, HowMany );
      NumberS += OneNumber.ToString() + ".";
      if( Index >= CodedBytes.Length )
        break;

      }

    // Get rid of that last period.
    NumberS = Utility.TruncateString( NumberS, NumberS.Length - 1 );
    StringValue = NumberS;
    return true;

    }
    catch( Exception Except )
      {
      // Probably over-ran the buffer.
      StatusString += "Exception in X509ObjectID.MakeFromBytes().\r\n";
      StatusString += Except.Message + "\r\n";
      return false;
      }
    }



  private ulong GetOneNumber( byte[] CodedBytes, int HowMany )
    {
    try
    {
    if( CodedBytes == null )
      {
      StatusString += "This is a bug. CodedBytes == null.\r\n";
      return 0;
      }

    if( CodedBytes.Length != 8 )
      {
      StatusString += "This is a bug. CodedBytes.Length != 8.\r\n";
      return 0;
      }

    if( HowMany >= 8 )
      {
      StatusString += "This is a bug. HowMany >= 8.\r\n";
      return 0;
      }

    // How long can these values be in practice?  More than a ulong?
    ulong NextValueParts = 0;
    for( int Count = 0; Count < HowMany; Count++ )
      {
      NextValueParts <<= 8; // It starts out with a value of zero so shifting zero left...
      NextValueParts |= CodedBytes[Count];
      }

    // Now I have the parts of the number in base-128 form.
    ulong Base = 1;
    ulong TheNumber = 0;
    for( int Count = 0; Count < HowMany; Count++ )
      {
      // StatusString += "Base: " + Base.ToString() + "\r\n";
      TheNumber += Base * (NextValueParts & 0xFF);
      // StatusString += "TheNumber: " + TheNumber.ToString() + "\r\n";
      Base = Base * 128;
      NextValueParts >>= 8;
      }

    // StatusString += "TheNumber at the end: " + TheNumber.ToString() + "\r\n";
    return TheNumber;

    }
    catch( Exception Except )
      {
      // Probably over-ran the buffer.
      StatusString += "Exception in X509ObjectID.GetOneNumber().\r\n";
      StatusString += Except.Message + "\r\n";
      return 0;
      }
    }



  }
}

