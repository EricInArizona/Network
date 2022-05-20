// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "SrvClPass.h"
#include "../CppBase/StIO.h"



SrvClPass::SrvClPass( void )
{
StIO::putS( "SrvClPass constructor called." );

}


// SrvClPass::SrvClPass( const SrvClPass& in )


SrvClPass::~SrvClPass( void )
{
StIO::putS( "SrvClPass destructor called." );
}


bool SrvClPass::processData( void )
{
if( mainSocket == 0 )
  return false;

// false will close down this socket
// in the destructor.
return false;
}
