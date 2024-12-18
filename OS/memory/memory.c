#include "../include/print.h"
#include "memory.h"

#define MEMORY_SIZE 1024

static uint8_t memory[MEMORY_SIZE];
static size_t memory_offset = 0;

void* OS_malloc(size_t size) {
  print("Asignando memoria");
    // if (memory_offset + size > MEMORY_SIZE) {
    //     return NULL; // No hay suficiente memoria
    // }
    // void* ptr = &memory[memory_offset];
    // memory_offset += size;
    // return ptr;
}

void OS_free(void* ptr) {
  print("Se libero la memoria");
}

