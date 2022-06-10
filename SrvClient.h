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
  Int64 timeActive = 0;

  protected:
  SrvClient( void );
  SocketCpp mainSocket = SocketsApi::InvalSock;

  public:
  SrvClient( SocketCpp useSocket );
  SrvClient( const SrvClient &in );
  virtual ~SrvClient( void );
  // virtual void pureVirtualFunction() = 0;
  // virtual void pureVirtualFunction() const = 0;

  virtual bool processData( void );

  inline Int64 getTimeActive( void ) const
    {
    return timeActive;
    }

  inline void setTimeActiveNow( void )
    {
    timeActive = TimeApi::getSecondsNow();
    }

  inline bool isActive( void )
    {
    if( mainSocket == SocketsApi::InvalSock )
      return false;

    Int64 diff = TimeApi::getSecondsNow() -
                 timeActive;

    if( diff < 30 )
      return true;

    return false;
    }

  };
