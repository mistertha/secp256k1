#include <windows.h>
#include <secp256k1.h>
#include "secp256k1_dll.h"

int __stdcall EC_Verify(const unsigned char *msg, int msglen,
	const unsigned char *sig, int siglen,
	const unsigned char *pubkey, int pubkeylen)
{
	return secp256k1_ecdsa_verify(msg, msglen, sig, siglen, pubkey, pubkeylen);
}

//BOOL APIENTRY DllMain(HANDLE a, DWORD b, LPVOID c)
BOOL APIENTRY DllMain()
{
	secp256k1_start();
}
