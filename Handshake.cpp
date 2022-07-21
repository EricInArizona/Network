// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "Handshake.h"
#include "../CryptoBase/Randomish.h"



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

/*
// Cipher suites listed in the order you want
// to use first.

// Cipher Suites in Appendix A.5 of RFC 4346.
// And also in...

TLS_NULL_WITH_NULL_NULL  = { 0x00,0x00 };

CipherSuite TLS_RSA_WITH_NULL_MD5                  = { 0x00,0x01 };
CipherSuite TLS_RSA_WITH_NULL_SHA                  = { 0x00,0x02 };
CipherSuite TLS_RSA_WITH_RC4_128_MD5               = { 0x00,0x04 };
CipherSuite TLS_RSA_WITH_RC4_128_SHA               = { 0x00,0x05 };
CipherSuite TLS_RSA_WITH_IDEA_CBC_SHA              = { 0x00,0x07 };
CipherSuite TLS_RSA_WITH_DES_CBC_SHA               = { 0x00,0x09 };
CipherSuite TLS_RSA_WITH_3DES_EDE_CBC_SHA          = { 0x00,0x0A };

TLS_DH_DSS_WITH_DES_CBC_SHA            = { 0x00,0x0C };
TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA       = { 0x00,0x0D };
TLS_DH_RSA_WITH_DES_CBC_SHA            = { 0x00,0x0F };
TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA       = { 0x00,0x10 };
TLS_DHE_DSS_WITH_DES_CBC_SHA           = { 0x00,0x12 };
TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA      = { 0x00,0x13 };
TLS_DHE_RSA_WITH_DES_CBC_SHA           = { 0x00,0x15 };
TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA      = { 0x00,0x16 };

TLS_DH_anon_WITH_RC4_128_MD5           = { 0x00,0x18 };
TLS_DH_anon_WITH_DES_CBC_SHA           = { 0x00,0x1A };
TLS_DH_anon_WITH_3DES_EDE_CBC_SHA      = { 0x00,0x1B };

// Don't ever let it do one of these export
// versions.
TLS_RSA_EXPORT_WITH_RC4_40_MD5         = { 0x00,0x03 };
TLS_RSA_EXPORT_WITH_RC2_CBC_40_MD5     = { 0x00,0x06 };
TLS_RSA_EXPORT_WITH_DES40_CBC_SHA      = { 0x00,0x08 };
TLS_DH_DSS_EXPORT_WITH_DES40_CBC_SHA   = { 0x00,0x0B };
TLS_DH_RSA_EXPORT_WITH_DES40_CBC_SHA   = { 0x00,0x0E };
TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA  = { 0x00,0x11 };
TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA  = { 0x00,0x14 };
TLS_DH_anon_EXPORT_WITH_RC4_40_MD5     = { 0x00,0x17 };
TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA  = { 0x00,0x19 };

cipher suite values { 0x00, 0x1C } and
                    { 0x00, 0x1D } are reserved
 to avoid collision with Fortezza-based
 cipher suites in SSL 3.

TLS_KRB5_WITH_DES_CBC_SHA           = { 0x00,0x1E }:
TLS_KRB5_WITH_3DES_EDE_CBC_SHA      = { 0x00,0x1F };
TLS_KRB5_WITH_RC4_128_SHA           = { 0x00,0x20 };
TLS_KRB5_WITH_IDEA_CBC_SHA          = { 0x00,0x21 };
TLS_KRB5_WITH_DES_CBC_MD5           = { 0x00,0x22 };
TLS_KRB5_WITH_3DES_EDE_CBC_MD5      = { 0x00,0x23 };
TLS_KRB5_WITH_RC4_128_MD5           = { 0x00,0x24 };
TLS_KRB5_WITH_IDEA_CBC_MD5          = { 0x00,0x25 };

TLS_KRB5_EXPORT_WITH_DES_CBC_40_SHA    = { 0x00,0x26};
TLS_KRB5_EXPORT_WITH_RC2_CBC_40_SHA    = { 0x00,0x27};
TLS_KRB5_EXPORT_WITH_RC4_40_SHA        = { 0x00,0x28};
TLS_KRB5_EXPORT_WITH_DES_CBC_40_MD5    = { 0x00,0x29};
TLS_KRB5_EXPORT_WITH_RC2_CBC_40_MD5    = { 0x00,0x2A};
TLS_KRB5_EXPORT_WITH_RC4_40_MD5        = { 0x00,0x2B};

TLS_RSA_WITH_AES_128_CBC_SHA      = { 0x00, 0x2F };
TLS_DH_DSS_WITH_AES_128_CBC_SHA   = { 0x00, 0x30 };
TLS_DH_RSA_WITH_AES_128_CBC_SHA   = { 0x00, 0x31 };
TLS_DHE_DSS_WITH_AES_128_CBC_SHA  = { 0x00, 0x32 };
TLS_DHE_RSA_WITH_AES_128_CBC_SHA  = { 0x00, 0x33 };
TLS_DH_anon_WITH_AES_128_CBC_SHA  = { 0x00, 0x34 };

TLS_RSA_WITH_AES_256_CBC_SHA      = { 0x00, 0x35 };
TLS_DH_DSS_WITH_AES_256_CBC_SHA   = { 0x00, 0x36 };
TLS_DH_RSA_WITH_AES_256_CBC_SHA   = { 0x00, 0x37 };
TLS_DHE_DSS_WITH_AES_256_CBC_SHA  = { 0x00, 0x38 };
TLS_DHE_RSA_WITH_AES_256_CBC_SHA  = { 0x00, 0x39 };
TLS_DH_anon_WITH_AES_256_CBC_SHA  = { 0x00, 0x3A };




==== Send this in an extension?


msgAr.setU8( 39, 0 ); // Length high byte.
msgAr.setU8( 40, 4 ); // Low byte.

======
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
