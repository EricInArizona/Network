// Programming by Eric Chauvin.
// Notes on this source code are at:
// http://eric7apps.blogspot.com/


// Look them up on:  http://www.oid-info.com/


using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace ExampleServer
{
  class X509ObjectIDNames
  {
  // A dictionary of Object IDs and their names.
  private SortedDictionary<string, string> NamesDictionary;
  private string StatusString = "";


  internal X509ObjectIDNames()
    {
    NamesDictionary = new SortedDictionary<string, string>();
    SetupNamesDictionary();
    }



  internal string GetStatusString()
    {
    string Result = StatusString;
    StatusString = "";
    return Result;
    }


  internal string GetNameFromDictionary( string ObjectID )
    {
    try
    {
    if( NamesDictionary == null )
      return "No dictionary";

    if( NamesDictionary.ContainsKey( ObjectID ))
      return NamesDictionary[ObjectID];
    else
      return "Not found.";

    }
    catch( Exception Except )
      {
      StatusString += "Exception in DomainX509Record.GetNameFromDictionary().\r\n";
      StatusString += Except.Message + "\r\n";
      return "Exception in DomainX509Record.GetNameFromDictionary().";
      }
    }



  private void SetupNamesDictionary()
    {
    try
    {
    // I got most of these from Microsoft help.  It's in the CRYPT_ALGORITHM_IDENTIFIER
    // structure.  But I've added more as I had to look them up.
    // You can look them up on:  http://www.oid-info.com/
    // Fortunately a string like "1.2.840.113549" is easy to find with a Google
    // search, so you can find out more about a particular Object ID.

    NamesDictionary["1.2.840.113549"] = "RSA";
    NamesDictionary["1.2.840.113549.1"] = "PKCS";
    NamesDictionary["1.2.840.113549.2"] = "RSA HASH";
    NamesDictionary["1.2.840.113549.3"] = "RSA ENCRYPT";
    NamesDictionary["1.2.840.113549.1.1"] = "PKCS 1";
    NamesDictionary["1.2.840.113549.1.2"] = "PKCS 2";
    NamesDictionary["1.2.840.113549.1.3"] = "PKCS 3";
    NamesDictionary["1.2.840.113549.1.4"] = "PKCS 4";
    NamesDictionary["1.2.840.113549.1.5"] = "PKCS 5";
    NamesDictionary["1.2.840.113549.1.6"] = "PKCS 6";
    NamesDictionary["1.2.840.113549.1.7"] = "PKCS 7";
    NamesDictionary["1.2.840.113549.1.8"] = "PKCS 8";
    NamesDictionary["1.2.840.113549.1.9"] = "PKCS 9";
    NamesDictionary["1.2.840.113549.1.10"] = "PKCS 10";
    NamesDictionary["1.2.840.113549.1.12"] = "PKCS 12";
    NamesDictionary["1.2.840.113549.1.1.2"] = "RSA_MD2";
    NamesDictionary["1.2.840.113549.1.1.3"] = "RSA_MD4";
    NamesDictionary["1.2.840.113549.1.1.4"] = "RSA_MD5";
    // PKCS 1:

    NamesDictionary["1.2.840.113549.1.1.1"] = "RSA_RSA RSA Encryption. RFC 2313, 2437, 3370.";
    NamesDictionary["1.2.840.113549.1.1.2"] = "RSA_MD2RSA";
    NamesDictionary["1.2.840.113549.1.1.3"] = "RSA_MD4RSA";
    NamesDictionary["1.2.840.113549.1.1.4"] = "RSA_MD5RSA";
    NamesDictionary["1.2.840.113549.1.1.5"] = "SHA1 with RSA. RSA_SHA1RSA RFC 2437, 3370";


    NamesDictionary["1.2.840.113549.1.1.6"] = "rsaOAEPEncryptionSET";
    NamesDictionary["1.2.840.113549.1.1.7"] = "id-RSAES-OAEP";

    NamesDictionary["1.2.840.113549.1.1.11"] = "SHA256 with RSA";
    NamesDictionary["1.2.840.113549.1.1.12"] = "SHA384 with RSA";

    NamesDictionary["1.2.840.113549.1.3.1"] = "RSA_DH";
    NamesDictionary["1.2.840.113549.1.7.1"] = "RSA_data";
    NamesDictionary["1.2.840.113549.1.7.2"] = "RSA_signedData";
    NamesDictionary["1.2.840.113549.1.7.3"] = "RSA_envelopedData";
    NamesDictionary["1.2.840.113549.1.7.4"] = "RSA_signEnvData";
    NamesDictionary["1.2.840.113549.1.7.5"] = "RSA_digestedData";
    NamesDictionary["1.2.840.113549.1.7.5"] = "RSA_hashedData";
    NamesDictionary["1.2.840.113549.1.7.6"] = "RSA_encryptedData";
    NamesDictionary["1.2.840.113549.1.9.1"] = "RSA_emailAddr";
    NamesDictionary["1.2.840.113549.1.9.2"] = "RSA_unstructName";
    NamesDictionary["1.2.840.113549.1.9.3"] = "RSA_contentType";
    NamesDictionary["1.2.840.113549.1.9.4"] = "RSA_messageDigest";
    NamesDictionary["1.2.840.113549.1.9.5"] = "RSA_signingTime";
    NamesDictionary["1.2.840.113549.1.9.6"] = "RSA_counterSign";
    NamesDictionary["1.2.840.113549.1.9.7"] = "RSA_challengePwd";
    NamesDictionary["1.2.840.113549.1.9.8"] = "RSA_unstructAddr";
    NamesDictionary["1.2.840.113549.1.9.9"] = "RSA_extCertAttrs";
    NamesDictionary["1.2.840.113549.1.9.15"] = "RSA_SMIMECapabilities";
    NamesDictionary["1.2.840.113549.1.9.15.1"] = "RSA_preferSignedData";
    NamesDictionary["1.2.840.113549.3.2"] = "RSA_RC2CBC";
    NamesDictionary["1.2.840.113549.3.4"] = "RSA_RC4";
    NamesDictionary["1.2.840.113549.3.7"] = "RSA_DES_EDE3_CBC";
    NamesDictionary["1.2.840.113549.3.9"] = "RSA_RC5_CBCPad";
    NamesDictionary["1.2.840.10046"] = "ANSI_x942";
    NamesDictionary["1.2.840.10046.2.1"] = "ANSI_x942_DH";
    NamesDictionary["1.2.840.10040"] = "X957";
    NamesDictionary["1.2.840.10040.4.1"] = "X957_DSA";
    NamesDictionary["1.2.840.10040.4.3"] = "DATA STRUCTURE";

    // https://msdn.microsoft.com/en-us/library/windows/desktop/aa379367%28v=vs.85%29.aspx

    NamesDictionary["1.3.6.1.5.5.7.1.1"] = "Authority Info Access \"The authority information access extension identifies how to access CA information and services. The extension value contains a sequence of URIs.\"";

    NamesDictionary["2.5"] = "DS";

    // "Enables identification of the CA public key that corresponds to the CA
    // private key that signed an issued certificate. It is used by certificate
    // path building software on a Windows server to find the CA certificate.
    // When a CA issues a certificate, the extension value is set equal to the
    // SubjectKeyIdentifier extension in the CA signing certificate. The value
    // is typically a SHA-1 hash of the public key."
    NamesDictionary["2.5.29.1"] = "Authority key identifier";

    NamesDictionary["2.5.29.10"] = "Basic Constraints";
    NamesDictionary["2.5.29.14"] = "Subject key identifier";
    NamesDictionary["2.5.29.15"] = "Key Usage";

    NamesDictionary["2.5.29.17"] = "Subject Alt Name";

    NamesDictionary["2.5.29.19"] = "Basic Constraints";
    NamesDictionary["2.5.29.25"] = "CRL Distribution Points";
    NamesDictionary["2.5.29.31"] = "CRL Distribution Points";
    NamesDictionary["2.5.29.32"] = "Certificate Policies";
    NamesDictionary["2.5.29.35"] = "Authority key identifier";
    NamesDictionary["2.5.29.37"] = "Certificate Extension key usage";

    NamesDictionary["2.5.4.1"] = "Aliased Entry Name";
    NamesDictionary["2.5.4.2"] = "Knowledge Information";
    NamesDictionary["2.5.4.3"] = "Common Name";
    NamesDictionary["2.5.4.6"] = "Country Name";
    NamesDictionary["2.5.4.7"] = "Locality Name";
    NamesDictionary["2.5.4.8"] = "State or Province Name";
    NamesDictionary["2.5.4.9"] = "Street Address";
    NamesDictionary["2.5.4.10"] = "Organization Name";
    NamesDictionary["2.5.4.11"] = "Organization Unit Name";
    NamesDictionary["2.5.8"] = "DSALG";
    NamesDictionary["2.5.8.1"] = "DSALG_CRPT";
    NamesDictionary["2.5.8.2"] = "DSALG_HASH";
    NamesDictionary["2.5.8.3"] = "DSALG_SIGN";
    NamesDictionary["2.5.8.1.1"] = "DSALG_RSA";
    NamesDictionary["1.3.14"] = "OIW";
    NamesDictionary["1.3.14.3.2"] = "OIWSEC";
    NamesDictionary["1.3.14.3.2.2"] = "OIWSEC_md4RSA";
    NamesDictionary["1.3.14.3.2.3"] = "OIWSEC_md5RSA";
    NamesDictionary["1.3.14.3.2.4"] = "OIWSEC_md4RSA2";
    NamesDictionary["1.3.14.3.2.6"] = "OIWSEC_desECB";
    NamesDictionary["1.3.14.3.2.7"] = "OIWSEC_desCBC";
    NamesDictionary["1.3.14.3.2.8"] = "OIWSEC_desOFB";
    NamesDictionary["1.3.14.3.2.9"] = "OIWSEC_desCFB";
    NamesDictionary["1.3.14.3.2.10"] = "OIWSEC_desMAC";
    NamesDictionary["1.3.14.3.2.11"] = "OIWSEC_rsaSign";
    NamesDictionary["1.3.14.3.2.12"] = "OIWSEC_dsa";
    NamesDictionary["1.3.14.3.2.13"] = "OIWSEC_shaDSA";
    NamesDictionary["1.3.14.3.2.14"] = "OIWSEC_mdc2RSA";
    NamesDictionary["1.3.14.3.2.15"] = "OIWSEC_shaRSA";
    NamesDictionary["1.3.14.3.2.16"] = "OIWSEC_dhCommMod";
    NamesDictionary["1.3.14.3.2.17"] = "OIWSEC_desEDE";
    NamesDictionary["1.3.14.3.2.18"] = "OIWSEC_sha";
    NamesDictionary["1.3.14.3.2.19"] = "OIWSEC_mdc2";
    NamesDictionary["1.3.14.3.2.20"] = "OIWSEC_dsaComm";
    NamesDictionary["1.3.14.3.2.21"] = "OIWSEC_dsaCommSHA";
    NamesDictionary["1.3.14.3.2.22"] = "OIWSEC_rsaXchg";
    NamesDictionary["1.3.14.3.2.23"] = "OIWSEC_keyHashSeal";
    NamesDictionary["1.3.14.3.2.24"] = "OIWSEC_md2RSASign";
    NamesDictionary["1.3.14.3.2.25"] = "OIWSEC_md5RSASign";
    NamesDictionary["1.3.14.3.2.26"] = "OIWSEC_sha1";
    NamesDictionary["1.3.14.3.2.27"] = "OIWSEC_dsaSHA1";
    NamesDictionary["1.3.14.3.2.28"] = "OIWSEC_dsaCommSHA1";
    NamesDictionary["1.3.14.3.2.29"] = "OIWSEC_sha1RSASign";
    NamesDictionary["1.3.14.7.2"] = "OIWDIR";
    NamesDictionary["1.3.14.7.2.1"] = "OIWDIR_CRPT";
    NamesDictionary["1.3.14.7.2.2"] = "OIWDIR_HASH";
    NamesDictionary["1.3.14.7.2.3"] = "OIWDIR_SIGN";
    NamesDictionary["1.3.14.7.2.2.1"] = "OIWDIR_md2";
    NamesDictionary["1.3.14.7.2.3.1"] = "OIWDIR_md2RSA";
    NamesDictionary["2.16.840.1.101.2.1"] = "INFOSEC";
    NamesDictionary["2.16.840.1.101.2.1.1.1"] = "INFOSEC_sdnsSignature";
    NamesDictionary["2.16.840.1.101.2.1.1.2"] = "INFOSEC_mosaicSignature";
    NamesDictionary["2.16.840.1.101.2.1.1.3"] = "INFOSEC_sdnsConfidentiality";
    NamesDictionary["2.16.840.1.101.2.1.1.4"] = "INFOSEC_mosaicConfidentiality";
    NamesDictionary["2.16.840.1.101.2.1.1.5"] = "INFOSEC_sdnsIntegrity";
    NamesDictionary["2.16.840.1.101.2.1.1.6"] = "INFOSEC_mosaicIntegrity";
    NamesDictionary["2.16.840.1.101.2.1.1.7"] = "INFOSEC_sdnsTokenProtection";
    NamesDictionary["2.16.840.1.101.2.1.1.8"] = "INFOSEC_mosaicTokenProtection";
    NamesDictionary["2.16.840.1.101.2.1.1.9"] = "INFOSEC_sdnsKeyManagement";
    NamesDictionary["2.16.840.1.101.2.1.1.10"] = "INFOSEC_mosaicKeyManagement";
    NamesDictionary["2.16.840.1.101.2.1.1.11"] = "INFOSEC_sdnsKMandSig";
    NamesDictionary["2.16.840.1.101.2.1.1.12"] = "INFOSEC_mosaicKMandSig";
    NamesDictionary["2.16.840.1.101.2.1.1.13"] = "INFOSEC_SuiteASignature";
    NamesDictionary["2.16.840.1.101.2.1.1.14"] = "INFOSEC_SuiteAConfidentiality";
    NamesDictionary["2.16.840.1.101.2.1.1.15"] = "INFOSEC_SuiteAIntegrity";
    NamesDictionary["2.16.840.1.101.2.1.1.16"] = "INFOSEC_SuiteATokenProtection";
    NamesDictionary["2.16.840.1.101.2.1.1.17"] = "INFOSEC_SuiteAKeyManagement";
    NamesDictionary["2.16.840.1.101.2.1.1.18"] = "INFOSEC_SuiteAKMandSig";
    NamesDictionary["2.16.840.1.101.2.1.1.19"] = "INFOSEC_mosaicUpdatedSig";
    NamesDictionary["2.16.840.1.101.2.1.1.20"] = "INFOSEC_mosaicKMandUpdSig";
    NamesDictionary["2.16.840.1.101.2.1.1.21"] = "INFOSEC_mosaicUpdatedInteg";
    }
    catch( Exception Except )
      {
      StatusString += "Exception in DomainX509Record.SetupNamesDictionary().\r\n";
      StatusString += Except.Message + "\r\n";
      }
    }



  }
}
