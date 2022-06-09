// Copyright Eric Chauvin 2022


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "SocketsApi.h"
#include "../CppBase/TimeApi.h"


// This is the server's view of one client
// socket.



class SrvClient
  {
  private:
  bool testForCopy = false;

  protected:
  SrvClient( void );
  SocketCpp mainSocket = SocketsApi::InvalSock;
  Int64 timeActive = 0;

  public:
  SrvClient( SocketCpp useSocket );
  SrvClient( const SrvClient &in );
  virtual ~SrvClient( void );
  // virtual void pureVirtualFunction() = 0;
  // virtual void pureVirtualFunction() const = 0;

  virtual bool processData( void );

  inline void setTimeActiveNow( void )
    {
    // The oonstructor sets it to now.
    TimeApi tm;

    // Str showS = tm.timeStr();

    timeActive = tm.getSeconds();
    }

  };
