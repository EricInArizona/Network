// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


// This can be used as a base class for
// other clients, or in the server with
// something like SrvClPass.  So it should
// be just a light, basic client.



#pragma once


#include "../CppBase/BasicTypes.h"
#include "../CppBase/Str.h"
#include "../CppBase/TimeApi.h"



class NetClient
  {
  private:
  bool testForCopy = false;
  Int64 timeActive = 0;

  public:
  NetClient( void );
  NetClient( const NetClient &in );
  ~NetClient( void );
  SocketCpp connect( Str& domain,
                     Str& port );

  inline void setTimeActiveNow( void )
    {
    // The oonstructor sets it to now.
    TimeApi tm;

    // Str showS = tm.timeStr();

    timeActive = tm.getSeconds();
    }

  };

