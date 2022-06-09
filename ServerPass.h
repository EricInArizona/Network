// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
// #include "../CppBase/CharBuf.h"
#include "Server.h"
#include "SrvClPass.h"



class ServerPass
  {
  private:
  bool testForCopy = false;
  Server server;

  public:
  ServerPass( void );
  ServerPass( const ServerPass &in );
  ~ServerPass( void );
  bool startServer( const char* port );
  void mainLoop( void );

  };
