#include <stdio.h>
#include "interrupt.h"
#include "scheduler.h"  // Asegúrate de incluir scheduler.h para poder acceder a process_queue
#include "process.h"

// Inicialización de interrupciones
void init_interrupts() {
    // Aquí podríamos inicializar recursos de interrupciones si es necesario
    printf("Interrupciones inicializadas.\n");
}

// Maneja la interrupción, por ejemplo, de un temporizador
void handle_interrupt() {
    // Aquí podríamos manejar la interrupción, como pausar o reanudar procesos
    printf("Interrupción manejada: pausando o reanudando procesos.\n");

    // Acceder a process_queue que está declarada en scheduler.c
    extern Process *process_queue;  // Usamos 'extern' para decirle al compilador que process_queue está definida en otro archivo

    Process *current = process_queue;
    if (current != NULL) {
        // Simular que el primer proceso en la cola es interrumpido
        printf("Interrumpiendo el proceso %d: %s\n", current->pid, current->name);
        // Aquí podríamos realizar más acciones relacionadas con la interrupción
    }
}

// Simula la ocurrencia de una interrupción (como un temporizador)
void simulate_interrupt() {
    printf("Simulando una interrupción...\n");
    handle_interrupt();  // Llama al manejador de interrupciones
}
