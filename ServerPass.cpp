// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "ServerPass.h"
#include "../CppBase/StIO.h"


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
while( true )
  {
  if( !server.oneLoop() )
    return;

  }
}


