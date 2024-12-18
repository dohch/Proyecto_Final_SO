#include "../include/print.h"

#include "memory.h"

void malloc(size_t size) {
  print("Asignando memoria");
    // if (memory_offset + size > MEMORY_SIZE) {
    //     return NULL; // No hay suficiente memoria
    // }
    // void* ptr = &memory[memory_offset];
    // memory_offset += size;
    // return ptr;
}

void free(void* ptr) {
  print("Se libero la memoria");
}

