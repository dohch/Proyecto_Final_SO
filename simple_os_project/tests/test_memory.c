#include <stdio.h>
#include <assert.h>
#include "memory.h"

void test_allocate_memory() {
    void *mem1 = allocate_memory(128);
    void *mem2 = allocate_memory(256);

    // Verificar que la memoria se haya asignado correctamente
    assert(mem1 != NULL);
    assert(mem2 != NULL);
    printf("Test de asignación de memoria exitoso.\n");
}

void test_out_of_memory() {
    // Intentar asignar más memoria de la que está disponible
    void *mem = allocate_memory(2048);  // Esto debería fallar si se ha agotado la memoria
    assert(mem == NULL);
    printf("Test de memoria agotada exitoso.\n");
}

int main() {
    // Inicialización de memoria
    init_memory();

    // Ejecutar pruebas
    test_allocate_memory();
    test_out_of_memory();

    return 0;
}
