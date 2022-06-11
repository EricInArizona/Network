// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "SrvClPass.h"
#include "../CppBase/StIO.h"



SrvClPass::SrvClPass( void )
{
setTimeActiveNow();

StIO::putS( "SrvClPass constructor called." );
}



SrvClPass::SrvClPass( SocketCpp useSocket,
                      const Str& address )
{
setTimeActiveNow();
mainSocket = useSocket;
clientAddress.copy( address );
StIO::putS( "SrvClPass useSocket constructor." );
}


// SrvClPass::SrvClPass( const SrvClPass& in )


SrvClPass::~SrvClPass( void )
{
StIO::putS( "SrvClPass destructor called." );
}


bool SrvClPass::processData( void )
{
if( mainSocket == SocketsApi::InvalSock )
  return false;

/*
if( !netClient.isConnected())
  {
  Str port( "443" );
  netClient.connect( clientAddress, port );
  }
*/

CharBuf recBuf;
if( !SocketsApi::receiveCharBuf(
                             mainSocket, recBuf ))
  {
  // Some error.  This socket will get closed.
  return false;
  }

// If it received nothing.
if( recBuf.getLast() == 0 )
  {
  if( !isActive())
    {
    StIO::putS( "Closing inactive socket." );
    SocketsApi::closeSocket( mainSocket );
    mainSocket = SocketsApi::InvalSock;
    return false;
    }

  // StIO::putS( "receiveBuf has nothing in it." );
  return true; // Not an error.
  }

// It received some data.
setTimeActiveNow();

StIO::putS( "Received data:" );
StIO::putCharBuf( recBuf );

// Send any data that needs to be sent.

// false will close down this socket.
return true;
}
