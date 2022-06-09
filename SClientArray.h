// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "SrvClient.h"
#include "SrvClPoint.h"


class SClientArray
  {
  private:
  bool testForCopy = false;
  SrvClPoint* sClPointAr;

  // This will not grow.  On purpose.
  const Int32 arraySize = 5;

  // Make a stats object.
  Int64 tooManyConnections = 0;

  public:
  SClientArray( void );
  SClientArray( const SClientArray& in );
  ~SClientArray( void );
  bool addNewClient( SrvClient* toAdd );
  void closeAllSockets( void );
  void processData( void );

  };
