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
// arraySize = 1024 * 2;
// cArray = new char[Casting::i32ToU64( arraySize )];
}



NetClient::NetClient( const NetClient &in )
{
// Make the compiler think the in value is
// being used.
if( in.testForCopy == 123 )
  return;

const char* showS = "The NetClient copy constructor"
         " should not be getting called.";

throw showS;
}



NetClient::~NetClient( void )
{
// delete[] cArray;
}



SocketCpp NetClient::connect( const char* domain,
                              const char* port )
{
SocketCpp sock = SocketsApi::connectClient(
                    domain, // "www.example.com",
                    port ); // "443"

if( sock == SocketsApi::InvalSock )
  {
  activeSec = 0;
  return sock;
  }

// The oonstructor sets it to now.
TimeApi tm;

// Str showS = tm.timeStr();

activeSec = tm.getSeconds();
return sock;
}
