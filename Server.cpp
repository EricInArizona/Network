// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "Server.h"
#include "../CppBase/StIO.h"
#include "../WinApi/Signals.h"
// #include "../LinuxApi/Signals.h"



Server::Server( void )
{
mainSocket = SocketsApi::InvalSock;
}



Server::Server( const Server& in )
{
mainSocket = SocketsApi::InvalSock;

if( in.testForCopy )
  return;

const char* showS = "The Server copy"
         " constructor should not get called.";

throw showS;
}



Server::~Server( void )
{
}



bool Server::addNewClient( SrvClient* toAdd )
{
return sClientAr.addNewClient( toAdd );
}


bool Server::startServer( const char* address,
                          const char* port )
{
StIO::putS( "Starting server." );

// OpenCharArray portAr;
// port.copyToOpenArray( portAr );

// It can be "localhost".
// localhost might use an IPv6 address.
// Use "127.0.0.1" for IPv4 localhost.
mainSocket = SocketsApi::openServer(
                    address,  port, true );

if( mainSocket == SocketsApi::InvalSock )
  {
  StIO::putS( "Could not start the server." );
  return false;
  }

StIO::putS( "Server is listening." );
return true;
}



bool Server::oneLoop( void )
{
// CharBuf fromCBuf;

if( Signals::getControlCSignal())
  {
  StIO::putS( "Closing server on Ctrl-C." );

  SocketsApi::closeSocket( mainSocket );
  mainSocket = SocketsApi::InvalSock;
  sClientAr.closeAllSockets();

  StIO::putS( "Closed server." );
  return false;
  }

sClientAr.processData();

return true;
}
