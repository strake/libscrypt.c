#include <sys/types.h>
#include "../util.h"

ssize_t fill (void *x, ssize_t (*f) (void *, void *, size_t), void *t, size_t n) {
	ssize_t m = 0;
	while (m < n) {
		size_t k = f (x, t + m, n - m);
		if (k  < 0) return k;
		if (k == 0) break;
		m += k;
	}
	return m;
}
