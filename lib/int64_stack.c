#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include "int64_result.h"
#include "int64_array.h"
#include <stdlib.h>

struct Int64Stack {
    size_t count;
    struct Int64Array data;
};

struct Int64Stack Int64Stack_create(size_t size) {
    struct Int64Array array = Int64Array_create(size);
    return (struct Int64Stack) { 0, array };
}

void Int64Stack_free(const struct Int64Stack * p) {
    struct Int64Array array = p -> data;
    free((void*)array.data);
}

size_t Int64Stack_count(const struct Int64Stack * p) {
    return p -> count;
}

bool Int64Stack_is_full(const struct Int64Stack * p) {
    return p -> count == (p -> data).size;
}

bool Int64Stack_is_empty(const struct Int64Stack * p) {
    return p -> count == 0;
}

bool Int64Stack_push(struct Int64Stack * p, int64_t value) {
    if (Int64Stack_is_full(p)) {
        return false;
    }

    (p -> data).data[p -> count] = value;
    (p -> count) += 1;
    return true;
}

struct Int64Result Int64Stack_pop(struct Int64Stack * p) {
    if (Int64Stack_is_empty(p)) {
        return NONE_INT64;
    }

    (p -> count) -= 1;
    return some_int64((p -> data).data[p -> count]);
}
