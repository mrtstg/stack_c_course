#ifndef INT64_RESULT
#define INT64_RESULT
#include <inttypes.h>

#define NONE_INT64 (struct Int64Result) { .valid = false }

struct Int64Result {
    bool valid;
    int64_t value;
};

struct Int64Result some_int64(int64_t number);
void Int64Result_print(const struct Int64Result * p);

#endif // !INT64_RESULT
