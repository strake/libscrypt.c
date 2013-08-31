#include <inttypes.h>
#include <memory.h>
#include <sys/types.h>
#include "scrypt.h"

ssize_t hash (Hash thehash, void *h1, void *rx, ssize_t (*rf) (void *, void *, size_t)) {
	uint8_t m[thehash.blocksize], h[thehash.worksize];
	ssize_t k, l = 0;
	
	memcpy (h, thehash.h0, thehash.worksize);
	
	do {
		size_t n = 0;
		while (n < thehash.blocksize) {
			k = rf (rx, m + n, thehash.blocksize - n);
			if (k  < 0) goto end;
			if (k == 0) break;
			n += k;
		}
		l += n;
		if (k == 0) thehash.pad (m, l);
		thehash.go (thehash.nRound, h, m);
	} while (k);
	
	thehash.end (h);
	
	memcpy (h1, h, thehash.size);
	
end:	memset (h, 0, thehash.worksize);
	return k;
}
