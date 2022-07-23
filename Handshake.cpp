// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "Handshake.h"
#include "../CryptoBase/Randomish.h"



/*
   A TLS-compliant application MUST implement
 the TLS_AES_128_GCM_SHA256

TLS_AES_128_GCM_SHA256       | {0x13,0x01} |
TLS_AES_256_GCM_SHA384       | {0x13,0x02} |
TLS_CHACHA20_POLY1305_SHA256 | {0x13,0x03} |
TLS_AES_128_CCM_SHA256       | {0x13,0x04} |
TLS_AES_128_CCM_8_SHA256     | {0x13,0x05} |

RFC 5116 - An Interface and Algorithms for
 Authenticated Encryption

*/



void Handshake::makeClientHello(
                            CharArray& msgAr )
{
const Int32 length = 50; // ??
msgAr.setSize( length );

msgAr.setU8( 0, ClientHello );

// Big endian.
msgAr.setU8( 1, Casting::i32ToU8(
                                 length >> 16 ));
msgAr.setU8( 2, Casting::i32ToU8(
                                 length >> 8 ));
msgAr.setU8( 3, Casting::i32ToU8(
                                 length ));

// Above this point it is always the same
// structure.

// Version 3.3 is legacy from TLS 1.2.
msgAr.setU8( 4, 3 );
msgAr.setU8( 5, 3 );

// The part for Unix time is not in TLS 1.3.
// These bytes have to be cryptographically random.
// These are used later in generating the master
// secret and keys, etc.

CharBuf randBytes;
Randomish::makeRandomBytes( randBytes, 32 + 10 );

Int32 index = 6;
for( Int32 count = 0; count < 32; count++ )
  {
  msgAr.setU8( index, randBytes.getU8( count ));
  index++;
  }

if( index != 38 )
  throw "Handshake index != 38.";

msgAr.setU8( 38, 0 ); // Legacy session ID length
                      // is zero.

// Cipher suites listed in the order you want
// to use first.

TLS_AES_128_GCM_SHA256       | {0x13,0x01} |




msgAr.setU8( 39, 0 ); // Length high byte.
msgAr.setU8( 40, 4 ); // Low byte.



======
This extensiono tells the server what signature
algorithms the client understands.  Like what
kind of certificate that it is able to verify.

Signature Algorithm Extension
          rsa_pkcs1_sha256(0x0401),
          rsa_pkcs1_sha384(0x0501),
          rsa_pkcs1_sha512(0x0601),

          // ECDSA algorithms
          ecdsa_secp256r1_sha256(0x0403),
          ecdsa_secp384r1_sha384(0x0503),
          ecdsa_secp521r1_sha512(0x0603),

          // RSASSA-PSS algorithms with public
 key OID rsaEncryption
          rsa_pss_rsae_sha256(0x0804),
          rsa_pss_rsae_sha384(0x0805),
          rsa_pss_rsae_sha512(0x0806),

          // EdDSA algorithms
          ed25519(0x0807),
          ed448(0x0808),

          // RSASSA-PSS algorithms with public
 key OID RSASSA-PSS
          rsa_pss_pss_sha256(0x0809),
          rsa_pss_pss_sha384(0x080a),
          rsa_pss_pss_sha512(0x080b),

          // Legacy algorithms
          rsa_pkcs1_sha1(0x0201),
          ecdsa_sha1(0x0203),

          // Reserved Code Points
          obsolete_RESERVED(0x0000..0x0200),
          dsa_sha1_RESERVED(0x0202),
          obsolete_RESERVED(0x0204..0x0400),
          dsa_sha256_RESERVED(0x0402),
          obsolete_RESERVED(0x0404..0x0500),
          dsa_sha384_RESERVED(0x0502),
          obsolete_RESERVED(0x0504..0x0600),
          dsa_sha512_RESERVED(0x0602),
          obsolete_RESERVED(0x0604..0x06FF),
          private_use(0xFE00..0xFFFF),
          (0xFFFF)
      } SignatureScheme;

      struct {
          SignatureScheme supported_signature_algorithms&lt;2..2^16-2&gt;;
      } SignatureSchemeList;



 Supported Groups Extension

      enum {
          unallocated_RESERVED(0x0000),

          // Elliptic Curve Groups (ECDHE)
          obsolete_RESERVED(0x0001..0x0016),
          secp256r1(0x0017), secp384r1(0x0018), secp521r1(0x0019),
          obsolete_RESERVED(0x001A..0x001C),
          x25519(0x001D), x448(0x001E),

          // Finite Field Groups (DHE)
          ffdhe2048(0x0100), ffdhe3072(0x0101), ffdhe4096(0x0102),
          ffdhe6144(0x0103), ffdhe8192(0x0104),

          ffdhe_private_use(0x01FC..0x01FF),
          ecdhe_private_use(0xFE00..0xFEFF),
          obsolete_RESERVED(0xFF01..0xFF02),
          (0xFFFF)
      } NamedGroup;



    ToSendBuf[47] = 0x35; // TLS_RSA_WITH_AES_256_CBC_SHA    = { 0x00,0x35 };
    ToSendBuf[48] = 0;
    ToSendBuf[49] = 0x3D; // TLS_RSA_WITH_AES_256_CBC_SHA256 = { 0x00,0x3D };
    ToSendBuf[50] = 1; // Compression Methods Length
    ToSendBuf[51] = 0; // Compression Method is null.

    // Extensions go here.
    // There are always extensions in TLS 1.3.

    // On the server side it has to allow unknown
    // extensions to be sent so it can ignore them
    // If they are a reasonable length.

      Extension types.  Two bytes.
      enum {
          server_name(0), max_fragment_length(1),
          client_certificate_url(2),
          trusted_ca_keys(3),
          truncated_hmac(4), status_request(5),
         (65535)
      } ExtensionType;

*/

}
