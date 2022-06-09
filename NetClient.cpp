// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "NetClient.h"
#include "../CppBase/Casting.h"
#include "../CppBase/TimeApi.h"
#include "../Network/SocketsApi.h"



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
}



SocketCpp NetClient::connect(
                     Str& domain,
                     Str& port )
{
SocketCpp sock = SocketsApi::connectClient(
                    domain, // "www.example.com",
                    port ); // "443"

if( sock == SocketsApi::InvalSock )
  {
  timeActive = 0;
  return sock;
  }

setTimeActiveNow();
return sock;
}

