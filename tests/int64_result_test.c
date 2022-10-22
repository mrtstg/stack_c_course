#include "../unity/unity.h"
#include "../lib/int64_result.h"
#include "../lib/random_gens.h"
#include "stdbool.h"
#include <time.h>
#include <stdlib.h>


void setUp() {
    init_srand();
}

void tearDown() {}

void test_valid_value_dispatch(void) {
    int64_t some_random_int = random();
    struct Int64Result test_res = some_int64(some_random_int);
    TEST_ASSERT(test_res.valid && test_res.value == some_random_int);
}

void test_defined_null_value(void) {
    struct Int64Result null_res = NONE_INT64;
    TEST_ASSERT(!null_res.valid);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_valid_value_dispatch);
    RUN_TEST(test_defined_null_value);
    return UNITY_END();
}
