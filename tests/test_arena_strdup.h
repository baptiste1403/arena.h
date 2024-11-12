#include "cutest.h"
#define ARENA_IMPLEMENTATION
#include "arena.h"
#include <stdio.h>
#include <string.h>

arena_t arena_strdup_ctx = {0};

// char* arena_strdup(arena_t* ctx, const char* s)

AFTER_TEST(after) {
    arena_free(&arena_strdup_ctx);
}

TEST(should_return_null_when_context_is_null) {
    char* res = arena_strdup(NULL, "test");

    cute_assert(res == NULL);
}

TEST(should_return_null_when_string_is_null) {
    char* res = arena_strdup(&arena_strdup_ctx, NULL);

    cute_assert(res == NULL);
}

TEST(should_return_string_equal_to_string_parameter) {
    const char* test_string = "This is a test string !";
    char* res = arena_strdup(&arena_strdup_ctx, test_string);

    cute_assert(res != NULL);
    cute_assert(strcmp(res, test_string) == 0);
}