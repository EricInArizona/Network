// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "NetClient.h"
#include "../CppBase/Casting.h"
#include "../CppBase/TimeApi.h"



NetClient::NetClient( void )
{
}



NetClient::NetClient( const NetClient &in )
{
if( in.testForCopy )
  return;

const char* showS = "The NetClient copy constructor"
         " should not be getting called.";

throw showS;
}



NetClient::~NetClient( void )
{
closeSocket();
}



bool NetClient::connect( Str& domain,
                         Str& port )
{
mainSocket = SocketsApi::connectClient(
                    domain, // "www.example.com",
                    port ); // "443"

if( mainSocket == SocketsApi::InvalSock )
  return false;

timeActive = TimeApi::getSecondsNow();
return true;
}



bool NetClient::sendStr( Str toSend )
{
if( mainSocket == SocketsApi::InvalSock )
  return false;

return SocketsApi::sendStr( mainSocket, toSend );
}


void NetClient::closeSocket( void )
{
if( mainSocket == SocketsApi::InvalSock )
  return;

SocketsApi::closeSocket( mainSocket );
}
