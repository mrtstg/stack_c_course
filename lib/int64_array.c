#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "int64_result.h"

struct Int64Array {
    size_t size;
    int64_t* data;
};

struct Int64Array Int64Array_create(size_t size) {
    int64_t* array = malloc(sizeof(int64_t) * size);
    if (!array) {
        exit(1);
    }
    return (struct Int64Array) { size, array };
}

void Int64Array_print(const struct Int64Array * p) {
    int64_t* array_pointer = p -> data;
    for (size_t i = 0; i < p -> size; i++) {
        printf("%" PRId64, array_pointer[i]);
        if (i != p -> size - 1) {
            printf(" ");
        }
    }
}

struct Int64Result Int64Array_get(const struct Int64Array * p, size_t index) {
    int64_t* array_pointer = p -> data;
    if (index < 0 || index >= p -> size) {
        return NONE_INT64;
    }
    return some_int64(array_pointer[index]);
}

bool Int64Array_set(const struct Int64Array * p, size_t index, int64_t value) {
    if (index < 0 || index >= p -> size) {
        return false;
    }
    (p -> data)[index] = value;
    return true;
}

void Int64Array_free(const struct Int64Array * p) {
    free(p -> data);
}
