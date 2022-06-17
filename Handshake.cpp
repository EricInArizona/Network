// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "Handshake.h"



void Handshake::makeClientHello(
                            CharArray& msgAr )
{
const Int32 length = 50; // ??
msgAr.setSize( length );

msgAr.setC( 0, ClientHello );

// Big endian.
msgAr.setC( 1, Casting::i32ToByte(
                                 length >> 16 ));
msgAr.setC( 2, Casting::i32ToByte(
                                 length >> 8 ));
msgAr.setC( 3, Casting::i32ToByte(
                                 length ));

/*

    ToSendBuf[9] = 3;   // Version Major
    ToSendBuf[10] = 3;  // Version Minor

    // This part for Unix time is not in TLS 1.3 because there's no point in having it.
    // But it is here in TLS 1.2.
    ECTime RightNow = new ECTime();
    RightNow.SetToNow();
    ulong UnixTime = RightNow.ToUnixTime();
    ToSendBuf[11] = (byte)(UnixTime >> 24);
    ToSendBuf[12] = (byte)(UnixTime >> 16);
    ToSendBuf[13] = (byte)(UnixTime >> 8);
    ToSendBuf[14] = (byte)(UnixTime);

    // These bytes have to be cryptographically random.
    // These are used later in generating the master secret and keys, etc.
    byte[] RandomBytes = new byte[28];
    CryptoRand.GetBytes( RandomBytes );

    int Index = 15;
    for( int Count = 0; Count < 28; Count++ )
      {
      ToSendBuf[Index] = RandomBytes[Count];
      Index++;
      }

    // Index is 15 + 28 = 43.
    // StatusString += "Index at the end of Random bytes is: " + Index.ToString() + "\r\n";
    // Index at the end of Random bytes is: 43

    ToSendBuf[43] = 0; // Session ID Length is zero. It's not resuming a session here.

    // A browser sends a lot more cipher suites than this so this is
    // usually a lot longer.  The algorithm you prefer to use should
    // be listed first.  So they are listed in order of preference.
    ToSendBuf[44] = 0; // Cipher Suites Length high byte
    ToSendBuf[45] = 4; // Cipher Suites Length
    ToSendBuf[46] = 0;
    ToSendBuf[47] = 0x35; // TLS_RSA_WITH_AES_256_CBC_SHA    = { 0x00,0x35 };
    ToSendBuf[48] = 0;
    ToSendBuf[49] = 0x3D; // TLS_RSA_WITH_AES_256_CBC_SHA256 = { 0x00,0x3D };
    ToSendBuf[50] = 1; // Compression Methods Length
    ToSendBuf[51] = 0; // Compression Method is null.

    // This message has no extensions, so that's all there is to send.
    return CustomerTLS.SendBuffer( ToSendBuf );

    }
    catch( Exception Except )
      {
      StatusString += "Exception in SendCrudeClientHello()\r\n";
      StatusString += Except.Message + "\r\n";
      return false;
      }
    }
  */
}
