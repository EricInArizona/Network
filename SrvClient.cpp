// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "SrvClient.h"
#include "../CppBase/StIO.h"
#include "SocketsApi.h"



SrvClient::SrvClient( void )
{
setTimeActiveNow();

StIO::putS( "SrvClient constructor called." );
}


SrvClient::SrvClient( SocketCpp useSocket )
{
mainSocket = useSocket;
StIO::putS( "SrvClient useSocket constructor." );
}



SrvClient::SrvClient( const SrvClient& in )
{
if( in.testForCopy )
  return;

const char* showS = "The SrvClient copy"
         " constructor should not get called.";

throw showS;
}



SrvClient::~SrvClient( void )
{
if( mainSocket != SocketsApi::InvalSock )
  {
  SocketsApi::closeSocket( mainSocket );
  mainSocket = SocketsApi::InvalSock;
  }

StIO::putS( "SrvClient destructor called." );
}



bool SrvClient::processData( void )
{
// This should not get called.
return false;
}
