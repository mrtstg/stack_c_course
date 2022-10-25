#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

void init_srand() {
    srand(time(NULL));
}

int64_t random_in_range(int64_t begin, int64_t end) {
    return (rand() % (end - begin + 1)) + begin;
}
