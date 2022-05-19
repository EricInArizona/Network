// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "../Sockets/SrvClient.h"


class SClientArray
  {
  private:
  Int32 testForCopy = 123;
  // An array of pointers to the base class.
  SrvClient* sClientAr;
  Int32 arraySize = 0;
  // Int32 last = 0;


  public:
  SClientArray( void );
  SClientArray( const SClientArray& in );
  ~SClientArray( void );

  };
