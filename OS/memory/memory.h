
#include <stddef.h>
#include <stdint.h>

#define MEMORY_SIZE 1024 * 1024

static uint8_t memory[MEMORY_SIZE];
static size_t memory_offset = 0;

void* simple_malloc(size_t size);
void simple_free(void* ptr);
