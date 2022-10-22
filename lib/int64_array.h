#ifndef INT64_ARRAY
#define INT64_ARRAY
#include <inttypes.h>
#include <stdbool.h>
#include "int64_result.h"

struct Int64Array {
    size_t size;
    int64_t* data;
};

struct Int64Array Int64Array_create(size_t size);

struct Int64Result Int64Array_get(const struct Int64Array * p, size_t index);

bool Int64Array_set(const struct Int64Array * p, size_t index, int64_t value);

void Int64Array_print(const struct Int64Array * p);

void Int64Array_free(const struct Int64Array * p);

#endif // INT64_ARRAY
