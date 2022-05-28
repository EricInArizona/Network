// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "SrvClient.h"
#include "../CppBase/StIO.h"
#include "SocketsApi.h"
#include "../WinApi/TimeApiWin.h"



SrvClient::SrvClient( void )
{
// All base class constructors are always called.

TimeApi now;
timeActive = now.getSeconds();

StIO::putS( "SrvClient constructor called." );
}


SrvClient::SrvClient( SocketCpp useSocket )
{
mainSocket = useSocket;
StIO::putS( "SrvClient useSocket constructor." );
}



SrvClient::SrvClient( const SrvClient& in )
{

// Make the compiler think the in value is
// being used.
if( in.testForCopy == 123 )
  return;

// You don't want to slice an object to a
// sub class.  Always pass a pointer or a
// reference.  Not a copy of the object itself.

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
return true;
}
