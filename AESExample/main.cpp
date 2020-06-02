#include <aes.h>
#include <ccm.h>
#include <osrng.h>
#include <cstring>

typedef uint8_t byte;

int main(void)
{

    CryptoPP::AutoSeededRandomPool prng;

	byte key[CryptoPP::AES::DEFAULT_KEYLENGTH];
	prng.GenerateBlock(key, sizeof(key));

	byte iv[CryptoPP::AES::BLOCKSIZE];
	prng.GenerateBlock(iv, sizeof(iv));

	byte plainText[] = "Hello! How are you.";
    size_t messageLen = std::strlen((char*)plainText) + 1;
	byte encoded[] = "";

    CryptoPP::CBC_Mode< CryptoPP::AES >::Encryption e;
    e.SetKeyWithIV(key, sizeof(key), iv);

    e.ProcessData(encoded, plainText, messageLen);

    std::cout << encoded << std::endl;


    return 0;
}