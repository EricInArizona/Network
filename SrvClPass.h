// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "../Sockets/SrvClient.h"


// A pass-through SrvClient.


class SrvClPass: public SrvClient
  {
  private:

  public:
  SrvClPass( void );
  ~SrvClPass( void ) override;
  bool processData( void ) override;

  };

