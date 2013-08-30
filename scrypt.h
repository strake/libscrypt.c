typedef struct {
	char *name;
	size_t size, blocksize, worksize;
	int nRound;
	void (*go) (int nRound, void *h, void *m);
	void (*pad) (uint8_t *m, size_t length);
	void (*end) (void *h);
	void *h0;
} Hash;

ssize_t hash (Hash hash, void *h, void *rx, ssize_t (*rf) (void *, void *, size_t));
