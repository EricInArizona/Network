// Copyright Eric Chauvin, 2021 - 2022.


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "../CppBase/StIO.h"
#include "../CppBase/Str.h"
// #include "../LinuxApi/SetStack.h"
#include "../CppBase/Casting.h"
#include "../CppBase/Threads.h"

#include "../WinApi/Signals.h"
// #include "../LinuxApi/Signals.h"



#include "MainApp.h"


// extern volatile Int32 gotSigFpe;

/*
void MainApp::checkSignals( void )
{
if( gotSigFpe > 0 )
  throw "gotSigFpe > 0";

}
*/



// int MainApp::mainLoop( int argc, char* argv[] )
int MainApp::mainLoop( void )
{
Int32 delay = 200; // milliseconds.
const char* outFile =
               "\\Eric\\Main\\NetSrv\\ExeOut.txt";

try
{
StIO::putS( "See output at:" );
StIO::putS( outFile );


// Throws an exception if things are not right.
BasicTypes::thingsAreRight();


mainIO.appendChars(
            "Programming by Eric Chauvin.\n" );

mainIO.appendChars( "Version date: " );
mainIO.appendChars( getVersionStr() );
mainIO.appendChars( "\n\n" );

// For Linux:
// Int32 stackSize = SetStack::getSize();
// Str showS( stackSize );
// mainIO.appendChars( "Stack size: " );
// mainIO.appendStr( showS );
// mainIO.appendChars( "\n\n" );

Signals::setupControlCSignal();
Signals::setupFpeSignal();
Signals::setupIllegalOpSignal();
Signals::setupBadMemSignal();


runServer();


mainIO.appendChars( "End of main app.\n" );

//             mainIO.readAll( fileName );
mainIO.writeAll( outFile );

Threads::sleep( delay );

return 0;
}
catch( const char* in )
  {
  mainIO.appendChars( "Exception in main loop.\n" );
  mainIO.appendChars( in );
  mainIO.appendChars( "\n" );
  mainIO.writeAll( outFile );

  Threads::sleep( delay );
  return 1;
  }

catch( ... )
  {
  const char* in = "An unknown exception"
                   " happened in the main loop.\n";

  mainIO.appendChars( in );
  mainIO.writeAll( outFile );

  Threads::sleep( delay );
  return 1;
  }
}


void MainApp::runServer( void )
{
CharBuf showBuf;

/*
Uint64 testSocket = SocketsApi::openClient(
                     "www.durangoherald.com",
                     "443", showBuf );
if( testSocket == 0 )
  {
  mainIO.appendCharBuf( showBuf );
  mainIO.appendChars(
              "openClient returned zero.\n" );

  return;
  }
*/


if( !server.startServer( "443" ))
  return;

}
