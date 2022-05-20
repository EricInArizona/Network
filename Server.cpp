// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "Server.h"
#include "../Sockets/SocketsApiWin.h"
// #include "SocketsApiLinux.h"
#include "../CppBase/StIO.h"
#include "../CppBase/Threads.h"
#include "../WinApi/Signals.h"
// #include "../LinuxApi/Signals.h"



Server::Server( void )
{
mainSocket = 0;
}



Server::Server( const Server& in )
{
mainSocket = 0;

// Make the compiler think the in value is
// being used.
if( in.testForCopy == 123 )
  return;

const char* showS = "The Server copy"
         " constructor should not get called.";

throw showS;
}



Server::~Server( void )
{
}



bool Server::startServer( const char* port )
{
StIO::putS( "Starting server." );

mainSocket = SocketsApi::openServer(
                            port, showBuf );

if( mainSocket == 0 )
  {
  StIO::putCharBuf( showBuf );
  showBuf.clear();
  return false;
  }

StIO::putCharBuf( showBuf );
showBuf.clear();

StIO::putS( "Server is listening." );
return true;
}


bool Server::oneLoop( void )
{
CharBuf fromCBuf;

// StartLoopTime = something

for( Int32 count = 0; count < 3; count++ )
  {
  if( Signals::getControlCSignal())
    {
    StIO::putS( "Closing server on Ctrl-C." );

    sClientAr.closeAllSockets();

    SocketsApi::closeSocket( mainSocket );
    StIO::putS( "Closed server." );
    return false;
    }

  fromCBuf.clear();
  SocketCpp acceptedSock =
                 SocketsApi::acceptConnect(
                                  mainSocket,
                                  fromCBuf,
                                  showBuf );

  if( acceptedSock != 0 )
    sClientAr.addNewSocket( acceptedSock );

  }

sClientAr.processData();

// FinishLoopTime = something
// Do this dynamically and adjust it to sleep
// more or less or none if it's busy.
//  Int32 milliSec = 100;
//  Threads::sleep( milliSec );

return true;
}
