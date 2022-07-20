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

  // This would be like a state machine,
  // where it is expecting the next state
  // for the handshake.

  // Sent by the server at any time.
  // The client should ignore it.  This is not
  // in later versions.  Reserved.
  static const Uint8 HelloRequest = 0;

  static const Uint8 ClientHello = 1;
  static const Uint8 ServerHello = 2;

  // hello_verify_request_RESERVED(3),

  static const Uint8 NewSessionTicket = 4;
  static const Uint8 EndOfEarlyData = 5;

  // hello_retry_request_RESERVED(6),

  static const Uint8 EncryptedExtensions = 8;
  static const Uint8 Certificate = 11;
  static const Uint8 ServerKeyExchange = 12;
  static const Uint8 CertificateRequest = 13;

  // Not used in 1.3.
  static const Uint8 ServerHelloDone = 14;
  static const Uint8 CertificateVerify = 15;

  // Not used in 1.3.
  static const Uint8 ClientKeyExchange = 16;

  static const Uint8 Finished = 20;

  // Not used in 1.3.
  // certificate_url(21)
  // certificate_status(22)
  // supplemental_data_RESERVED(23),

  static const Uint8 KeyUpdate = 24;

  // When the handshake is done, you get
  // the hash of everything.
  static const Uint8 MessageHash = 254;

  // Null for no compression.
  // CompressionMethod.null
  static const Uint8 CompressionMethod = 0;

/*
Extension type numbers.

        server_name(0),  RFC 6066
        max_fragment_length(1), RFC 6066
        status_request(5),  RFC 6066
        supported_groups(10), RFC 8422
        signature_algorithms(13),  RFC 8446
        use_srtp(14),  RFC 5764

// Heartbeat as in the HeartBleed bug.  It was a
// bug in OpenSSL.  A buffer over-read.  No
// bounds check.
        heartbeat(15),  RFC 6520

        application_layer_protocol_negotiation(16),
                      RFC 7301
        signed_certificate_timestamp(18), RFC 6962
        client_certificate_type(19), RFC 7250
        server_certificate_type(20), RFC 7250
        padding(21),  RFC 7685
        pre_shared_key(41),   RFC 8446
        early_data(42),       RFC 8446

// You have to always have this in the ClientHello.
// To say it's TLS 1.3.  0x0304
        supported_versions(43),  RFC 8446

        cookie(44),    RFC 8446
        psk_key_exchange_modes(45), RFC 8446
        certificate_authorities(47), RFC 8446
        oid_filters(48),          RFC 8446
        post_handshake_auth(49), RFC 8446
        signature_algorithms_cert(50), RFC 8446
        key_share(51),     RFC 8446
        (65535)
    } ExtensionType;


// The kind of signature you want to get in
// a certificate.  List them in order of preference.

      enum {
          // RSASSA-PKCS1-v1_5 algorithms
          rsa_pkcs1_sha256(0x0401),
          rsa_pkcs1_sha384(0x0501),
          rsa_pkcs1_sha512(0x0601),

          // ECDSA algorithms
          ecdsa_secp256r1_sha256(0x0403),
          ecdsa_secp384r1_sha384(0x0503),
          ecdsa_secp521r1_sha512(0x0603),

          // RSASSA-PSS algorithms with public
          // key OID rsaEncryption
          rsa_pss_rsae_sha256(0x0804),
          rsa_pss_rsae_sha384(0x0805),
          rsa_pss_rsae_sha512(0x0806),

          // EdDSA algorithms
          ed25519(0x0807),
          ed448(0x0808),

          // RSASSA-PSS algorithms with public
          // key OID RSASSA-PSS
          rsa_pss_pss_sha256(0x0809),
          rsa_pss_pss_sha384(0x080a),
          rsa_pss_pss_sha512(0x080b),

          // Legacy algorithms
          rsa_pkcs1_sha1(0x0201),
          ecdsa_sha1(0x0203),

          // Reserved Code Points
          private_use(0xFE00..0xFFFF),
          (0xFFFF)
      } SignatureScheme;


*/

  public:
  void makeClientHello( CharArray& msgAr );

  };
