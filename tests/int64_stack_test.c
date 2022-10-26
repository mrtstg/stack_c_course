#include "../unity/unity.h"
#include "../lib/int64_stack.h"
#include "../lib/random_gens.h"
#include <stdio.h>

void setUp() {
    init_srand();
}

void tearDown() {}

void test_stack_count_function(void) {
    int64_t stack_size = random_in_range(10, 100);
    int64_t stack_elems_amount = random_in_range(1, 9);
    struct Int64Stack stack = Int64Stack_create((size_t)stack_size);
    for (size_t i = 0; i < stack_elems_amount; i++) {
        int64_t random_num = random_in_range(0, 10000);
        TEST_ASSERT(Int64Stack_push(&stack, random_num));
    }
    TEST_ASSERT(Int64Stack_count(&stack) == stack_elems_amount);
}

void test_stack_full_function(void) {
    struct Int64Stack stack = Int64Stack_create(5);
    for (size_t i = 0; i < 5; i++) {
        int64_t random_num = random_in_range(0, 10000);
        TEST_ASSERT(Int64Stack_push(&stack, random_num));
    }
    TEST_ASSERT(Int64Stack_is_full(&stack));
}

void test_stack_empty_function_on_empty_stack(void) {
    struct Int64Stack stack = Int64Stack_create(5);
    TEST_ASSERT(Int64Stack_is_empty(&stack));
}

void test_stack_empty_function_on_used_stack(void) {
    int64_t stack_length = random_in_range(10, 100);
    int64_t fill_elements_amount = random_in_range(5, stack_length);
    struct Int64Stack stack = Int64Stack_create((size_t)stack_length);
    for (size_t i = 0; i < fill_elements_amount; i++) {
        int64_t random_num = random_in_range(0, 10000);
        TEST_ASSERT(Int64Stack_push(&stack, random_num));
    }
    TEST_ASSERT_FALSE(Int64Stack_is_empty(&stack));
    for (size_t i = 0; i < fill_elements_amount; i++) {
        struct Int64Result res = Int64Stack_pop(&stack);
        TEST_ASSERT(res.valid);
    }
    TEST_ASSERT(Int64Stack_is_empty(&stack));
}

void test_correct_values_pop(void) {
    int64_t nums_amount = random_in_range(10, 100);
    struct Int64Stack stack = Int64Stack_create(100);
    struct Int64Array random_nums_array = Int64Array_create(nums_amount);
    for (size_t i = 0; i < nums_amount; i++) {
        int64_t random_num = random_in_range(0, 10000);
        TEST_ASSERT(Int64Array_set(&random_nums_array, i, random_num));
        TEST_ASSERT(Int64Stack_push(&stack, random_num));
    }

    for (size_t i = 0; i < nums_amount; i++) {
        struct Int64Result res = Int64Stack_pop(&stack);
        struct Int64Result arr_res = Int64Array_get(&random_nums_array, nums_amount - i - 1);
        TEST_ASSERT(res.valid);
        TEST_ASSERT(arr_res.valid);
        TEST_ASSERT(arr_res.value == res.value);
    }

    TEST_ASSERT(Int64Stack_is_empty(&stack));
    struct Int64Result res = Int64Stack_pop(&stack);
    TEST_ASSERT(!res.valid);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_stack_count_function);
    RUN_TEST(test_stack_full_function);
    RUN_TEST(test_stack_empty_function_on_empty_stack);
    RUN_TEST(test_stack_empty_function_on_used_stack);
    RUN_TEST(test_correct_values_pop);
    return UNITY_END();
}
