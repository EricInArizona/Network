// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


// A good tutorial:
// https://beej.us/guide/bgnet/html/

// DNS over HTTPS
// https://en.wikipedia.org/wiki/DNS_over_HTTPS


// The SocketCpp type is in BasicTypes.h

#include "../CppBase/BasicTypes.h"
#include "../CppBase/CharBuf.h"
// #include "../CppBase/CircleBuf.h"
#include "../CppBase/Str.h"
// #include "../CppBase/RangeC.h"

// This can't include things like SrvClient.h
// because they have to include this.
// This is only to encapsulate the Sockets API.




class SocketsApi
  {
  private:
  Int32 testForCopy = 123;

  public:
  static const SocketCpp InvalSock =
                      ~static_cast<Uint64>( 0 );


  SocketsApi( void );
  SocketsApi( const SocketsApi &in );
  ~SocketsApi( void );

  static void closeSocket( SocketCpp toClose );
  static void shutdownRead( SocketCpp toClose );

  static bool setNonBlocking(
                           const SocketCpp toSet );

  static SocketCpp connectClient(
                             const char* domain,
                             const char* port );

  static SocketCpp openServer(
                      const char* ipAddress,
                      const char* port,
                      const bool useIPv4Only );

  static SocketCpp acceptConnect(
                         SocketCpp servSock,
                         Str& fromAddress );

  static Int32 sendCharBuf(
                     const SocketCpp sendToSock,
                     const CharBuf& sendBuf );

  static bool receiveCharBuf(
                     const SocketCpp recSock,
                     CharBuf& recvBuf );

  };
