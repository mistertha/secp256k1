#include <windows.h>
#include <secp256k1.h>
#include "secp256k1_dll.h"

int __stdcall EC_Verify(const unsigned char *msg, int msglen,
	const unsigned char *sig, int siglen,
	const unsigned char *pubkey, int pubkeylen)
{
	return secp256k1_ecdsa_verify(msg, msglen, sig, siglen, pubkey, pubkeylen);
}

extern "C" BOOL APIENTRY DllMain(HANDLE, DWORD, LPVOID)
{
	secp256k1_start();
}
