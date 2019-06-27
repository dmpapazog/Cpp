#include <cstdlib>
#include <iostream>
#include <string>

#include "cryptopp/cryptlib.h"
#include "cryptopp/sha3.h"

using namespace CryptoPP;
using std::cout;

int main()
{
  std::string msg = "Yoda said, Do or do not. There is no try.";
  std::string digest;

  SHA3_256 hash;
  hash.Update((const byte*)msg.data(), msg.size());
  digest.resize(hash.DigestSize());
  hash.Final((byte*)&digest[0]);

  std::cout << "Message: " << msg << std::endl;

  std::cout << "Digest: ";
//   StringSource(digest, true, new Redirector(encoder));
  std::cout << digest << std::endl;

  return EXIT_SUCCESS;
}