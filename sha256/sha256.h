#ifndef __SHA256__
#define __SHA256__

/**
 * Implementation largely taken from:
 *     https://github.com/B-Con/crypto-algorithms
 * which in turn seems to largely be taken from:
 *     https://en.wikipedia.org/wiki/SHA-2
 */

#include <stddef.h>

#define uint8_t unsigned char
#define uint32_t unsigned int

typedef struct sha256_context {
    uint8_t data[64];
    size_t data_length;
    size_t bit_length;
    uint32_t state[8];
} sha256_context;

void sha256_initialize(sha256_context* context);
void sha256_update(sha256_context* context, uint8_t* data, size_t length);
void sha256_finish(sha256_context* context, uint8_t* hash);
void sha256_clean_context(sha256_context* context);

#endif