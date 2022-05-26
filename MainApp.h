// Copyright Eric Chauvin 2021 - 2022.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


// See https://ericinarizona.github.io/
// For more information.


#pragma once



#include "../CppBase/BasicTypes.h"
// #include "../CppBase/FileIO.h"

// #include "Server.h"
#include "ServerPass.h"

// Don't need this for Linux.
#include "../Sockets/SocketsApiWin.h"



class MainApp
  {
  private:
  // FileIO mainIO;

  // The constructor does WSAStartup() and
  // the destructor does WSACleanup(). So the
  // Windows dlls stay going for the life of
  // this app.  Also statistical and other data
  // is kept for the life of the app.

  SocketsApi socketsApi;
  ServerPass server;
  public:
  inline static const char* getVersionStr( void )
    {
    return "5/24/2022";
    }

  // Int32 mainLoop( Int32 argc, char* argv[] );
  Int32 mainLoop( void );
  void runServer( void );

  };
