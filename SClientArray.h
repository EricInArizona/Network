// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "SrvClient.h"
#include "SrvClPoint.h"


// This is oversimplified for a small server.
// I would need indexes into something.



class SClientArray
  {
  private:
  Int32 testForCopy = 123;
  // A pointer to the starting point of the array.
  SrvClPoint* sClPointAr;

  // This will not grow on purpose.
  const Int32 arraySize = 5;

  // Make a stats object.
  Int64 tooManyConnections = 0;

  public:
  SClientArray( void );
  SClientArray( const SClientArray& in );
  ~SClientArray( void );
  bool addNewSocket( SocketCpp newSocket );
  void closeAllSockets( void );
  Int32 needsNewClient( void );
  void addNewClientAt( Int32 where,
                       SrvClient& newClient );
  void processData( void );

  };
