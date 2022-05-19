// Copyright Eric Chauvin 2021 - 2022.


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "SClientArray.h"
#include "../CppBase/Casting.h"


SClientArray::SClientArray( void )
{
arraySize = 1;

sClientAr = new SrvClient[Casting::i32ToU64(
                                  arraySize )];
// sClientAr[0].setConnected( false );

}


SClientArray::SClientArray(
                          const SClientArray& in )
{
sClientAr = new SrvClient[Casting::i32ToU64(
                                  arraySize )];

// Make the compiler think in is being used.
if( in.testForCopy == 7 )
  return;

throw
   "Don't use copy constructor for SClientArray.";
}


SClientArray::~SClientArray( void )
{
// Notice that override destructors will be called.
delete[] sClientAr;
}
