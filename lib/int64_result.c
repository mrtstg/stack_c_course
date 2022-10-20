#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

struct Int64Result {
    bool valid;
    int64_t value;
};

struct Int64Result some_int64(int64_t number) {
    return (struct Int64Result) { true, number };
}

void Int64Result_print(const struct Int64Result * p) {
    if (p->valid) {
        printf("%" PRId64 "\n", p->value);
        return;
    }
    printf("None\n");
}
