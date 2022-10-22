#include "../unity/unity.h"
#include "../lib/int64_array.h"
#include "../lib/random_gens.h"
#include <stdbool.h>

void setUp() {
    init_srand();
}

void tearDown() {}

void test_invalid_index_update(void) {
    struct Int64Array array = Int64Array_create(5);
    TEST_ASSERT_FALSE(Int64Array_set(&array, 5, 10));
    TEST_ASSERT_FALSE(Int64Array_set(&array, random_in_range(10, 100), 1));
    TEST_ASSERT_FALSE(Int64Array_set(&array, -1, 5));
}

void test_invalid_index_get(void) {
    struct Int64Array array = Int64Array_create(5);
    TEST_ASSERT_FALSE(Int64Array_get(&array, 5).valid);
    TEST_ASSERT_FALSE(Int64Array_get(&array, random_in_range(10, 100)).valid);
    TEST_ASSERT_FALSE(Int64Array_get(&array, -1).valid);
}

void test_valid_index_get(void) {
    struct Int64Array array = Int64Array_create(10);
    for (size_t i = 0; i < 10; i++) {
        int64_t random_num = random_in_range(0, 10000);
        array.data[i] = random_num;
        struct Int64Result res = Int64Array_get(&array, i);
        TEST_ASSERT(res.valid && res.value == random_num);
    }
}

void test_valid_index_update(void) {
    struct Int64Array array = Int64Array_create(10);
    for (size_t i = 0; i < 10; i++) {
        int64_t random_num = random_in_range(0, 10000);
        bool res = Int64Array_set(&array, i, random_num);
        TEST_ASSERT(res && array.data[i] == random_num);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_invalid_index_get);
    RUN_TEST(test_invalid_index_update);
    RUN_TEST(test_valid_index_get);
    RUN_TEST(test_valid_index_update);
    return UNITY_END();
}
