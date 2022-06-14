// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


class TlsOuterRec
  {
  private:
  CharArray HeaderAr;

  // The types of outer messages.
  static const Uint8 ChangeCipherSpec = 20;
  static const Uint8 Alert = 21;
  static const Uint8 Handshake = 22;
  static const Uint8 ApplicationData = 23;

  static const Uint8 AlertTypeWarning = 1;
  static const Uint8 AlertTypeFatal = 2;

  // Alert description:
  static const Uint8 AlertCloseNotify = 0;
  static const Uint8 AlertUnexpectedMessage = 10;
  static const Uint8 AlertBadRecordMac = 20;
  static const Uint8 AlertDecompressionFailure = 30;
  static const Uint8 AlertHandshakeFailure = 40;
  static const Uint8 AlertNoCertificate = 41;
  static const Uint8 AlertBadCertificate = 42;
  static const Uint8
                  AlertUnsupportedCertificate = 43;
  static const Uint8 AlertCertificateRevoked = 44;
  static const Uint8 AlertCertificateExpired = 45;
  static const Uint8 AlertCertificateUnknown = 46;
  static const Uint8 AlertIllegalParameter = 47;



/*

Change Cipher Spec message is just one byte.
No length or version.

        struct {
            AlertLevel level;
            AlertDescription description;
        } Alert;



Handshake messages are sent in a PlainText
structure:


// Compression is obsolete in later versions
// and it is not used here.

// CompressionMethod.null is no compression.

The MAC is used with the encrypted blocks.

       stream-ciphered struct {
            opaque content[SSLCompressed.length];
            opaque MAC[CipherSpec.hash_size];
        } GenericStreamCipher;


 the MAC is computed before encryption

The cipher encrypts the entire block, including
the MAC.

*/



  inline void setupHeader( Uint8 recType,
                           Int32 length )
    {
    // Can't be bigger than 2^14.
    if( length > 0x4000 )  //  0x8000 is 2^15.
                           // 0x10000 is 2^16.
      throw "TLSOuterRec length too big.";

    headerAr.setSize( 5 );
    headerAr.setC( 0, recType );

    // The version historically comes from SSL
    // and so SSL version 3.1 is the same as
    // TLS version 1.0.  So TLS version 1.2 is
    // the like SSL version 3.3.  But from there
    // it is legacy code and it just stays at
    // 3.3 for later versions of TLS.

    headerAr.setC( 1, 3 );  // Version Major
    headerAr.setC( 2, 3 );  // Version Minor

    // Do the big end first.  Big endian.
    headerAr.setC( 3, Casting::i32ToByte(
                                 length >> 8 ));
    headerAr.setC( 4, Casting::i32ToByte(
                                 length ));

    }

  };
