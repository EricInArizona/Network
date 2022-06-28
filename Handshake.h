// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "../CppBase/BasicTypes.h"
#include "../CppBase/CharArray.h"


class Handshake
  {
  private:

  // The types of handshake messages.
  // These are in the order they have to be sent.
  // Sent by the server at any time:
  // The client should ignore it?  In later
  // versions?
  static const Uint8 HelloRequest = 0;

  static const Uint8 ClientHello = 1;
  static const Uint8 ServerHello = 2;
  static const Uint8 Certificate = 11;
  static const Uint8 ServerKeyExchange = 12;
  static const Uint8 CertificateRequest = 13;
  static const Uint8 ServerHelloDone = 14;
  static const Uint8 CertificateVerify = 15;
  static const Uint8 ClientKeyExchange = 16;
  static const Uint8 Finished = 20;

/*
      enum {
          hello_request(0), client_hello(1), server_hello(2),
          certificate(11), server_key_exchange (12),
          certificate_request(13), server_hello_done(14),
          certificate_verify(15), client_key_exchange(16),
          finished(20), certificate_url(21), certificate_status(22),
          (255)


   enum {
       hello_request(0), client_hello(1), server_hello(2),
       certificate(11), server_key_exchange (12),
       certificate_request(13), server_hello_done(14),
       certificate_verify(15), client_key_exchange(16),
       finished(20), certificate_url(21), certificate_status(22),
       (255)
   } HandshakeType;

*/
  // Null for no compression.
  // CompressionMethod.null
  static const Uint8 CompressionMethod = 0;


  public:
  void makeClientHello( CharArray& msgAr );

  };



/*
What state is the handshake in?
Like a state machine.
What is the next message it expects to get?

        struct {
            ProtocolVersion client_version;
            Random random;
            SessionID session_id;
            CipherSuite cipher_suites&lt;2..2^16-1&gt;;
            CompressionMethod compression_methods&lt;1..2^8-1&gt;;
        } ClientHello;

It is permitted to include extra data after the
compression method for forward compatibility.




In later versions this is just 32 bytes of
random data.  The unix time is deprecated.
The random data has to be cryptographically
random.

      struct {
          uint32 gmt_unix_time;
          opaque random_bytes[28];
      } Random;

DH is not ephemeral

DHE denotes ephemeral Diffie-Hellman, where
 the Diffie-Hellman
   parameters are signed by a DSS or RSA
 certificate, which has been
   signed by the CA.


*/
