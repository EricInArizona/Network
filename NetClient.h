// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


// This can be used as a base class for
// other clients, or in the server with
// something like SrvClPass.  So it should
// be just a light, basic client.



#pragma once


#include "../CppBase/BasicTypes.h"
#include "../CppBase/Str.h"
// #include "../CppBase/FileIO.h"



class NetClient
  {
  private:
  Int32 testForCopy = 123;
  // FileIO mainIO;
  // Int32 arraySize = 0;
  // char* cArray;  // Uint8?
  Int64 activeSec = 0; // When it was active.




  public:
  NetClient( void );
  NetClient( const NetClient &in );
  ~NetClient( void );
  SocketCpp connect( Str& domain,
                     Str& port );

  };
