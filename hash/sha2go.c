static void NAMEpad (uint8_t *m, size_t l) {
	size_t n = sizeof (WORD) << 4, k = n - (l & (n - 1));
	
	memset (m + n - k, 0, k);
	m[n - k] = 0x80;
	for (int ii = 0; ii < MIN(sizeof (WORD) << 1, sizeof (size_t)); ii++) m[n - 1 - ii] = (l << 3) >> (ii << 3);
}

static void NAMEgo (int nRound, WORD *h, uint8_t *m) {
	WORD z[8], w[16], s, t;
	int ii, jj;
	
	for (jj = 0; jj < 16; jj++) LOADNBE(w[jj], m + sizeof (WORD)*jj);
	
	for (jj = 0; jj <  8; jj++) z[jj] = h[jj];
	
	for (ii = 0; ii < nRound; ii++) {
		if (ii && !(ii & 0xF)) for (jj = 0; jj < 16; jj++) w[jj] += SSIG1(w[(jj + 14) & 0xF]) + w[(jj + 9) & 0xF] + SSIG0(w[(jj + 1) & 0xF]);
		s = z[7] + BSIG1(z[4]) + CH(z[4],z[5],z[6]) + (k[ii] >> (sizeof (uint64_t) - sizeof (WORD) << 3)) + w[ii & 0xF];
		t = BSIG0(z[0]) + MAJ(z[0],z[1],z[2]);
		for (jj = 7; jj > 0; jj--) z[jj] = z[jj - 1];
		z[4] += s;
		z[0]  = s + t;
	}
	
	s = t = 0;
	
	for (jj = 0; jj <  8; jj++) {
		h[jj] += z[jj];
		z[jj] = 0;
	}
}

static void NAMEend (WORD *h) {
	int ii;
	for (ii = 0; ii < 8; ii++) {
		WORD t = h[ii];
		STORNBE(t, (uint8_t *)(&h[ii]));
	}
}
