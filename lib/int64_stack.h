#ifndef INT64_STACK
#define INT64_STACK
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "int64_result.h"
#include "int64_array.h"

struct Int64Stack {
    size_t count;
    struct Int64Array data;
};

struct Int64Stack Int64Stack_create(size_t size);

void Int64Stack_free(const struct Int64Stack * p);

size_t Int64Stack_count(const struct Int64Stack * p);

bool Int64Stack_is_full(const struct Int64Stack * p);

bool Int64Stack_is_empty(const struct Int64Stack * p);

bool Int64Stack_push(struct Int64Stack * p, int64_t value);

struct Int64Result Int64Stack_pop(struct Int64Stack * p);

#endif // !INT64_STACK
