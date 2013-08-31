#include <inttypes.h>
#include <memory.h>
#include <sys/types.h>
#include "scrypt.h"

ssize_t hash (Hash thehash, void *h1, void *rx, ssize_t (*rf) (void *, void *, size_t)) {
	uint8_t m[thehash.blocksize], h[thehash.worksize];
	ssize_t l = 0, n;
	
	memcpy (h, thehash.h0, thehash.worksize);
	
	do {
		n = fill (rx, rf, m, thehash.blocksize);
		if (n < 0) goto end;
		l += n;
		if (n < thehash.blocksize) thehash.pad (m, l);
		thehash.go (thehash.nRound, h, m);
	} while (n >= thehash.blocksize);
	
	thehash.end (h);
	
	memcpy (h1, h, thehash.size);
	
end:	memset (h, 0, thehash.worksize);
	memset (m, 0, thehash.blocksize);
	return n;
}
