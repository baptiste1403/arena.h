#include "cutest.h"
#define ARENA_IMPLEMENTATION
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

arena_t arena_calloc_ctx = {0};

AFTER_TEST(after) {
    arena_free(&arena_calloc_ctx);
}

TEST(should_return_null_when_size_is_zero) {
    void* res = arena_calloc(&arena_calloc_ctx, 10, 0);
    cute_assert(res == NULL);
}

TEST(should_return_null_when_nmemb_is_zero) {
    void* res = arena_calloc(&arena_calloc_ctx, 0, 10);
    cute_assert(res == NULL);
}

TEST(should_return_null_when_context_is_null) {
    void* res = arena_calloc(NULL, 10, 10);
    cute_assert(res == NULL);
}

TEST(should_return_not_null_when_size_is_not_zero_and_nmemb_is_not_zero_and_context_is_not_null) {
    void* res = arena_calloc(&arena_calloc_ctx, 10, 10);
    cute_assert(res != NULL);
}

TEST(should_return_ptr_to_data_of_size_nmemb_x_size_filled_with_zero) {
    char* res = (char*)arena_calloc(&arena_calloc_ctx, sizeof(char), 10);
    for(size_t i = 0; i < sizeof(char)*10; i++) {
        cute_assert(res[i] == 0);
    }
}