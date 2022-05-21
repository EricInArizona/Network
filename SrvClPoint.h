// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "SrvClient.h"


// I don't care about being compatible with
// C++ 98.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"


class SrvClPoint
  {
  private:

  protected:

  public:
  // This is 16 bytes.
  SrvClient* srvClientP = nullptr;
  SocketCpp mainSocket = 0; // Zero is disconnected.

  };

#pragma clang diagnostic pop
