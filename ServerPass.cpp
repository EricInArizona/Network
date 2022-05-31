// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "ServerPass.h"
#include "../CppBase/StIO.h"
#include "../CppBase/Threads.h"


ServerPass::ServerPass( void )
{
}



ServerPass::ServerPass( const ServerPass& in )
{
// Make the compiler think the in value is
// being used.
if( in.testForCopy == 123 )
  return;

const char* showS = "The ServerPass copy"
         " constructor should not get called.";

throw showS;
}



ServerPass::~ServerPass( void )
{
}



bool ServerPass::startServer( const char* port )
{
return server.startServer( port );
}


void ServerPass::mainLoop( void )
{
CharBuf fromCBuf;

while( true )
  {
  // StartLoopTime = something

  StIO::putS( "Top of mainLoop()." );

  if( !server.oneLoop() )
    return;

  // accept() until there are no more sockets
  // to accept.
  for( Int32 count = 0; count < 100; count++ )
    {
    fromCBuf.clear();
    SocketCpp acceptedSock =
                 SocketsApi::acceptConnect(
                          server.getMainSocket(),
                          fromCBuf );

    // No more sockets to accept.
    if( acceptedSock == SocketsApi::InvalSock )
      break;

    // Add the kind of SrvClient socket I
    // want to add.
    server.addNewClient( new SrvClPass(
                                 acceptedSock ));

    StIO::putS( "Added new SrvClPass:" );
    StIO::putCharBuf( fromCBuf );
    StIO::putS( "\n" );
    }

  // FinishLoopTime = something
  // Do this dynamically and adjust it to sleep
  // more or less or none if it's busy.
  Int32 milliSec = 1000;
  Threads::sleep( milliSec );
  }
}
