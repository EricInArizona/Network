// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


// This can be used as a base class for
// other clients, or in the server with
// something like SrvClPass.  So it should
// be just a light, basic client.



#pragma once


#include "../CppBase/BasicTypes.h"
#include "../CppBase/Str.h"
#include "../CppBase/TimeApi.h"
#include "../Network/SocketsApi.h"



class NetClient
  {
  private:
  bool testForCopy = false;
  Int64 timeActive = 0;
  SocketCpp mainSocket = SocketsApi::InvalSock;

  public:
  NetClient( void );
  NetClient( const NetClient &in );
  ~NetClient( void );
  bool connect( Str& domain,
                Str& port );
  bool sendStr( Str toSend );
  void closeSocket( void );
  inline bool isConnected( void )
    {
    if( mainSocket == SocketsApi::InvalSock )
      return false;

    return true;
    }


  };
