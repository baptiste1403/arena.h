#include "cutest.h"
#define ARENA_IMPLEMENTATION
#include "arena.h"
#include <stdio.h>

arena_t arena_malloc_ctx = {0};

AFTER_TEST(after) {
    arena_free(&arena_malloc_ctx);
}

TEST(should_return_null_when_size_is_zero) {
    void* res = arena_malloc(&arena_malloc_ctx, 0);
    cute_assert(res == NULL);
}

TEST(should_return_null_when_context_is_null) {
    void* res = arena_malloc(NULL, 10);
    cute_assert(res == NULL);
}

TEST(should_return_not_null_when_size_is_not_zero_and_context_is_not_null) {
    void* res = arena_malloc(&arena_malloc_ctx, 10);
    cute_assert(res != NULL);
}