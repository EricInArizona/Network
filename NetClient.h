// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "../CppBase/BasicTypes.h"
// #include "../CppBase/FileIO.h"


class NetClient
  {
  private:
  Int32 testForCopy = 123;
  // FileIO mainIO;
  // Int32 arraySize = 0;
  // char* cArray;  // Uint8?



  public:
  NetClient( void );
  NetClient( const NetClient &in );
  ~NetClient( void );
  SocketCpp connect( const char* domain,
                     const char* port );

  };
