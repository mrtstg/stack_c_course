#include "../unity/unity.h"
#include "../lib/int64_stack.h"
#include "../lib/random_gens.h"

void setUp() {
    init_srand();
}

void tearDown() {}

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_stack_full_function);
    return UNITY_END();
}
