#include <stdio.h>
#include <assert.h>
#include "scheduler.h"
#include "process.h"
#include "memory.h"

// Función de prueba para verificar la inicialización del planificador
void test_init_scheduler() {
    init_scheduler();
    assert(process_queue == NULL);  // La cola debe estar vacía después de la inicialización
    printf("test_init_scheduler PASSED\n");
}

// Función de prueba para verificar la creación y ejecución de procesos
void test_schedule_processes() {
    init_scheduler();
    create_process(1, "Proceso 1");
    create_process(2, "Proceso 2");
    schedule_processes();  // Se debe imprimir la ejecución de los procesos
    printf("test_schedule_processes PASSED\n");
}


