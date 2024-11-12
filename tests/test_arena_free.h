#include "cutest.h"
#define ARENA_IMPLEMENTATION
#include "arena.h"
#include <stdio.h>

arena_t arena_free_ctx = {0};

// void arena_free(arena_t* ctx)

AFTER_TEST(after) {
    arena_free(&arena_free_ctx);
}

TEST(should_not_segfault_when_context_is_null) {
    arena_free(NULL);
}

TEST(should_not_segfault_when_context_is_empty) {
    arena_t test_ctx = {0};
    
    arena_free(&test_ctx);
}

TEST(should_not_segfault_when_context_has_data) {
    arena_t test_ctx = {0};
    arena_malloc(&test_ctx, 10);
    
    arena_free(&test_ctx);
}