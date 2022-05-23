// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
// #include "../CppBase/CharBuf.h"
#include "SrvClient.h"
#include "SClientArray.h"
#include "../Sockets/SocketsApiWin.h"
// #include "SocketsApiLinux.h"


class Server
  {
  private:
  Int32 testForCopy = 123;
  // There is one main server socket.
  SocketCpp mainSocket = SocketsApi::InvalSock;
  // CharBuf showBuf;
  SClientArray sClientAr;

  public:
  Server( void );
  Server( const Server &in );
  ~Server( void );
  bool startServer( const char* port );
  bool oneLoop( void );

  };
