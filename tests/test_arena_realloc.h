#include "cutest.h"
#define ARENA_IMPLEMENTATION
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

arena_t arena_realloc_ctx = {0};

// void* arena_realloc(arena_t* ctx, void* oldptr, size_t oldsize, size_t size)

AFTER_TEST(after) {
    arena_free(&arena_realloc_ctx);
}

TEST(should_return_null_when_context_is_null) {
    void* oldptr = arena_malloc(&arena_realloc_ctx, 10);

    void* ptr = arena_realloc(NULL, oldptr, 10, 20);

    cute_assert(ptr == NULL);
}

TEST(should_return_null_when_size_is_zero) {
    void* oldptr = arena_malloc(&arena_realloc_ctx, 10);
    
    void* ptr = arena_realloc(&arena_realloc_ctx, oldptr, 10, 0);

    cute_assert(ptr == NULL);
}

TEST(should_return_ptr_when_oldsize_is_zero) {
    void* oldptr = arena_malloc(&arena_realloc_ctx, 10);
    
    void* ptr = arena_realloc(&arena_realloc_ctx, oldptr, 0, 20);

    cute_assert(ptr != NULL);
}

TEST(should_return_null_when_oldptr_is_null) {
    void* ptr = arena_realloc(&arena_realloc_ctx, NULL, 10, 20);

    cute_assert(ptr == NULL);
}

TEST(should_return_ptr_when_oldsize_is_bigger_than_size) {
    void* oldptr = arena_malloc(&arena_realloc_ctx, 10);
    
    void* ptr = arena_realloc(&arena_realloc_ctx, oldptr, 30, 20);

    cute_assert(ptr != NULL);
}

TEST(should_return_ptr_when_oldsize_is_smaller_than_size) {
    void* oldptr = arena_malloc(&arena_realloc_ctx, 10);
    
    void* ptr = arena_realloc(&arena_realloc_ctx, oldptr, 10, 20);

    cute_assert(ptr != NULL);
}

TEST(should_return_ptr_to_data_equal_to_oldptr_data) {
    const char* test_string = "this string need to be bigger !";
    char* oldptr = arena_strdup(&arena_realloc_ctx, test_string);

    char* ptr = arena_realloc(&arena_realloc_ctx, oldptr, strlen(test_string)+1, strlen(test_string)*2);

    cute_assert(strcmp(test_string, ptr) == 0);
}