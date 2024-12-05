#include <stdio.h>
#include "scheduler.h"
#include "process.h"  // Asegúrate de incluir el archivo process.h para acceder a las funciones de procesos

// Cola de procesos (FIFO) - Solo declaración sin inicialización
extern Process *process_queue;  // Cola de procesos, definida en process.c

// Inicialización del planificador
void init_scheduler() {
    process_queue = NULL;  // Inicializa la cola vacía
    printf("Planificador inicializado.\n");
}

// Función para planificar y ejecutar los procesos
void schedule_processes() {
    if (process_queue == NULL) {
        printf("No hay procesos para ejecutar.\n");
        return;
    }

    printf("Ejecutando procesos...\n");
    Process *current = process_queue;
    while (current != NULL) {
        // Simular ejecución del proceso (imprimir su ID y nombre)
        printf("Ejecutando proceso %d: %s\n", current->pid, current->name);
        current = current->next;  // Avanzar al siguiente proceso
    }
    printf("Todos los procesos ejecutados.\n");
}
