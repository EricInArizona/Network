// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
// #include "../CppBase/CharBuf.h"
#include "SocketsApi.h"
#include "SrvClient.h"
#include "SClientArray.h"
#include "../CppBase/Str.h"


class Server
  {
  private:
  bool testForCopy = false;
  // There is one main server socket.
  SocketCpp mainSocket = SocketsApi::InvalSock;
  SClientArray sClientAr;

  public:
  Server( void );
  Server( const Server &in );
  ~Server( void );

  inline SocketCpp getMainSocket( void )
    {
    return mainSocket;
    }

  bool addNewClient( SrvClient* toAdd );
  bool startServer( const char* port );
  bool oneLoop( void );

  };
