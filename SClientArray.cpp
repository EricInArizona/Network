// Copyright Eric Chauvin 2021 - 2022.


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "SClientArray.h"
#include "../CppBase/Casting.h"
#include "../Sockets/SocketsApiWin.h"
// #include "SocketsApiLinux.h"


SClientArray::SClientArray( void )
{
// This calls the constructor for each SrvClPoint
// in the array.

sClPointAr = new SrvClPoint[Casting::i32ToU64(
                                  arraySize )];
}


SClientArray::SClientArray(
                          const SClientArray& in )
{
sClPointAr = new SrvClPoint[Casting::i32ToU64(
                                  arraySize )];

// Make the compiler think in is being used.
if( in.testForCopy == 7 )
  return;

throw "Copy constructor for SClientArray.";
}


SClientArray::~SClientArray( void )
{
delete[] sClPointAr;
}



bool SClientArray::addNewSocket(
                          SocketCpp newSocket )
{
// Something could just make a whole lot of
// connections to your server and if you keep
// allocating new space for more client objects
// then it will kill your server.

// Use the first available one.
for( Int32 count = 0; count < arraySize;
                                   count++ )
  {
  if( sClPointAr[count].mainSocket == 0 )
    {
    sClPointAr[count].mainSocket = newSocket;
    return true;
    }
  }

// I would rather set this to have a million
// small objects in the array and then I know
// I can have up to a million socket connections.
// If I get a million connections then I have
// a problem like Disttibuted Denial of Service,
// or I have a lot of customers.
// If I have that many customers I need to
// have a more advanced, distributed server.
// And I need something more than just a
// simple small array.

tooManyConnections++;
return false;
}


void SClientArray::closeAllSockets( void )
{
for( Int32 count = 0; count < arraySize;
                                   count++ )
  {
  sClPointAr[count].mainSocket = 0;
  if( sClPointAr[count].srvClientP != nullptr )
    {
    // The destructor closes the socket.
    delete sClPointAr[count].srvClientP;
    sClPointAr[count].srvClientP = nullptr;
    }
  }
}



Int32 SClientArray::needsNewClient( void )
{
for( Int32 count = 0; count < arraySize; count++ )
  {
  if( sClPointAr[count].mainSocket != 0 )
    {
    // A good socket has not been assigned a
    // client object yet.
    if( sClPointAr[count].srvClientP == nullptr )
      return count;

    }
  }

return -1;
}




void SClientArray::addNewClientAt( Int32 where,
                         SrvClient& newClient )
{
// This takes ownership of the object, so it
// is responsible for freeing it.

if( sClPointAr[where].srvClientP != nullptr )
  throw "Assigning a client to one that's there.";

// Set the address of the new client.
sClPointAr[where].srvClientP = &newClient;
sClPointAr[where].srvClientP->setSocket(
                 sClPointAr[where].mainSocket );
}



void SClientArray::processData( void )
{
for( Int32 count = 0; count < arraySize;
                                   count++ )
  {
  if( sClPointAr[count].srvClientP != nullptr )
    {
    if( sClPointAr[count].
           srvClientP->processData())
      continue;

    // Shut it down.  Closing the socket is
    // done in the destructor.
    sClPointAr[count].mainSocket = 0;
    if( sClPointAr[count].srvClientP != nullptr )
      delete sClPointAr[count].srvClientP;

    sClPointAr[count].srvClientP = nullptr;
    }
  }
}
