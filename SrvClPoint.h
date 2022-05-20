// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "SrvClient.h"


class SrvClPoint
  {
  private:

  protected:

  public:
  SrvClient* srvClClientP = nullptr;
  SocketCpp mainSocket = 0; // Zero is disconnected.
  // Int64 timeActive = 0;

  };
