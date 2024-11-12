#define CUTEST_IMPLEMENTATION
#include "cutest.h"
#include "test_arena_malloc.h"
#include "test_arena_calloc.h"
#include "test_arena_realloc.h"
#include "test_arena_free.h"
#include "test_arena_strdup.h"

int main(int argc, char** argv) {
    run_all_tests();
    return 0;
}