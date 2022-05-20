// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"


// This is the server's view of one client
// socket.


class SrvClient
  {
  private:
  Int32 testForCopy = 123;

  protected:
  SocketCpp mainSocket = 0; // Zero is disconnected.
  Int64 timeActive = 0;

  public:
  SrvClient( void );
  SrvClient( const SrvClient &in );
  virtual ~SrvClient( void );

  // An Interface would have nothing but pure
  // virtual functions in the class.
  // virtual void pureVirtualFunction() = 0;
  // virtual void pureVirtualFunction() const = 0;

  void setSocket( const SocketCpp toSet );
  virtual bool processData( void );

  inline void setTimeActive( Int64 setTo )
    {
    timeActive = setTo;
    }

  };
