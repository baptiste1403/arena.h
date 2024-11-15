#include "cutest.h"
#include <stdlib.h>
#define ARENA_IMPLEMENTATION
#include "arena.h"

arena_t arena_da_append_ctx = {0};

typedef struct {
    size_t count;
    size_t capacity;
    int* items;
} array_t;

AFTER_TEST(after) {
    arena_free(&arena_da_append_ctx);
}

TEST(should_add_item_when_called_with_one_item_to_add) {
    array_t array = {0};

    arena_da_append(&arena_da_append_ctx, &array, 10);

    cute_assert(array.count == 1);
    cute_assert(array.items[0] == 10);
}

TEST(should_add_all_items_when_called_100_times) {
    array_t array = {0};

    for(size_t i = 0; i < 100; i++) {
        arena_da_append(&arena_da_append_ctx, &array, i);
    }

    cute_assert(array.count == 100);

    for(size_t i = 0; i < 100; i++) {
        cute_assert(array.items[i] == i);
    }
}