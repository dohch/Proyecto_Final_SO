#include <stdio.h>
#include <assert.h>
#include "memory.h"

// Función de prueba para verificar la asignación de memoria
void test_allocate_memory() {
    init_memory();
    void *mem1 = allocate_memory(128);
    assert(mem1 != NULL);  // Verificar que se asigna correctamente
    printf("test_allocate_memory PASSED\n");

    // Intentar asignar memoria mayor a la disponible
    void *mem2 = allocate_memory(1000);  // Esto debe fallar
    assert(mem2 == NULL);  // No debe asignarse la memoria
    printf("test_allocate_memory (overflow) PASSED\n");
}

