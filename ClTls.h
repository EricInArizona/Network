// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


// This is the client for Transport Layer
// Security.
// TLS version 1.3.



#include "../CppBase/BasicTypes.h"
#include "NetClient.h"


class ClTls: public NetClient
  {
  private:
  bool testForCopy = false;

  public:
  ClTls( void );
  ClTls( const ClTls &in );
  ~ClTls( void );

  };
