#include <stdio.h>
#include <assert.h>
#include "process.h"
#include "memory.h"

// Función de prueba para verificar la creación de procesos
void test_create_process() {
    create_process(1, "Proceso 1");
    assert(process_queue != NULL);  // La cola debe contener el proceso creado
    printf("test_create_process PASSED\n");
}

// Función de prueba para verificar la destrucción de procesos
void test_destroy_process() {
    create_process(1, "Proceso 1");
    destroy_process(1);
    assert(process_queue == NULL);  // La cola debe estar vacía después de destruir el proceso
    printf("test_destroy_process PASSED\n");
}

