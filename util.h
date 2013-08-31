#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

#define ROL(x,n) ((x)<<(n)|(x)>>(8*sizeof(x) - (n)))
#define ROR(x,n) ((x)>>(n)|(x)<<(8*sizeof(x) - (n)))

#define LOAD32LE(y, x) { (y) = (uint32_t)((x)[0]) << 0 | (uint32_t)((x)[1]) << 8 | (uint32_t)((x)[2]) << 16 | (uint32_t)((x)[3]) << 24; }
#define LOAD64LE(y, x) { (y) = (uint64_t)((x)[0]) << 0 | (uint64_t)((x)[1]) << 8 | (uint64_t)((x)[2]) << 16 | (uint64_t)((x)[3]) << 24 | (uint64_t)((x)[4]) << 32 | (uint64_t)((x)[5]) << 40 | (uint64_t)((x)[6]) << 48 | (uint64_t)((x)[7]) << 56; }

#define STOR32LE(x, y) { (y)[0] = (uint8_t)((x) >> 0); (y)[1] = (uint8_t)((x) >> 8); (y)[2] = (uint8_t)((x) >> 16); (y)[3] = (uint8_t)((x) >> 24); }
#define STOR64LE(x, y) { (y)[0] = (uint8_t)((x) >> 0); (y)[1] = (uint8_t)((x) >> 8); (y)[2] = (uint8_t)((x) >> 16); (y)[3] = (uint8_t)((x) >> 24); (y)[4] = (uint8_t)((x) >> 32); (y)[5] = (uint8_t)((x) >> 40); (y)[6] = (uint8_t)((x) >> 48); (y)[7] = (uint8_t)((x) >> 56); }

#define LOAD32BE(y, x) { (y) =                                                                                                             (uint32_t)((x)[0]) << 24 | (uint32_t)((x)[1]) << 16 | (uint32_t)((x)[2]) << 8 | (uint32_t)((x)[3]) << 0; }
#define LOAD64BE(y, x) { (y) = (uint64_t)((x)[0]) << 56 | (uint64_t)((x)[1]) << 48 | (uint64_t)((x)[2]) << 40 | (uint64_t)((x)[3]) << 32 | (uint64_t)((x)[4]) << 24 | (uint64_t)((x)[5]) << 16 | (uint64_t)((x)[6]) << 8 | (uint64_t)((x)[7]) << 0; }

#define STOR32BE(x, y) {                                                                                                                             (y)[0] = (uint8_t)((x) >> 24); (y)[1] = (uint8_t)((x) >> 16); (y)[2] = (uint8_t)((x) >> 8); (y)[3] = (uint8_t)((x) >> 0); }
#define STOR64BE(x, y) { (y)[0] = (uint8_t)((x) >> 56); (y)[1] = (uint8_t)((x) >> 48); (y)[2] = (uint8_t)((x) >> 40); (y)[3] = (uint8_t)((x) >> 32); (y)[4] = (uint8_t)((x) >> 24); (y)[5] = (uint8_t)((x) >> 16); (y)[6] = (uint8_t)((x) >> 8); (y)[7] = (uint8_t)((x) >> 0); }

ssize_t fill (void *x, ssize_t (*f) (void *, void *, size_t), void *t, size_t n);
