# Arena.h
Arena.h is header-only simple memory allocator based on memory context. 
It is widely inspired by the work of https://github.com/tsoding with his project https://github.com/tsoding/arena

## Installation

Include arena.h and define ARENA_IMPLEMENTATION
```c
#define ARENA_IMPLEMENTATION
#include "arena.h"

int main(int argc, char** argv) {
    ...
}
```

## Usage

You create a context :
```c
arena_t context = {0};
```

Then you can allocate memory and use it :
```c
char* data = (char*)arena_malloc(&context, 100);

for(size_t i = 0; i < 100; i++) {
    data[i] = i;
}
```

And free everything at once :
```c
arena_free(&context);
```

Available functions are :
```c
void arena_free(arena_t* ctx);
void* arena_malloc(arena_t* ctx, size_t size);
void* arena_calloc(arena_t* ctx, size_t nmemb, size_t size);
void* arena_realloc(arena_t* ctx, void* ptr, size_t oldsize, size_t size);
char* arena_strdup(arena_t* ctx, const char* s);
```

## License

[MIT](LICENSE)