#ifndef RANDOM_GENS
#define RANDOM_GENS
#include <inttypes.h>

void init_srand();

int64_t random_in_range(int64_t begin, int64_t end);

#endif // !RANDOM_GENS
