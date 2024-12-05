#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "memory.h"

// Cola de procesos (FIFO) - Definición e inicialización
Process *process_queue = NULL;  // Cola de procesos, inicializada a NULL

// Crear un nuevo proceso
void create_process(int pid, char *name) {
    printf("Creando proceso %d: %s\n", pid, name);
    add_process_to_queue(pid, name);  // Añadir el proceso a la cola del planificador
}

// Añadir un proceso a la cola de procesos
void add_process_to_queue(int pid, char *name) {
    Process *new_process = (Process *)malloc(sizeof(Process));
    if (new_process == NULL) {
        printf("Error al asignar memoria para el proceso.\n");
        return;
    }

    new_process->pid = pid;
    new_process->name = name;
    new_process->memory = allocate_memory(128);  // Asignar memoria de 128 bytes al proceso
    new_process->next = NULL;

    // Si la cola está vacía, el nuevo proceso es el primero
    if (process_queue == NULL) {
        process_queue = new_process;
    } else {
        // Si la cola no está vacía, añadir el proceso al final de la cola
        Process *temp = process_queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_process;
    }

    printf("Proceso %d añadido a la cola.\n", pid);
}

// Función para destruir un proceso
void destroy_process(int pid) {
    Process *current = process_queue;
    Process *previous = NULL;

    // Buscar el proceso en la cola
    while (current != NULL) {
        if (current->pid == pid) {
            if (previous == NULL) {
                // Si el proceso a eliminar es el primero
                process_queue = current->next;
            } else {
                // El proceso está en el medio o al final
                previous->next = current->next;
            }
            // Liberar la memoria asignada al proceso
            free(current->memory);  // Liberar la memoria asignada al proceso
            free(current);  // Liberar la estructura del proceso
            printf("Proceso %d destruido.\n", pid);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Proceso %d no encontrado.\n", pid);
}

// Función auxiliar para imprimir la cola de procesos
void print_process_queue() {
    Process *current = process_queue;
    printf("Cola de procesos:\n");
    while (current != NULL) {
        printf("Proceso %d: %s\n", current->pid, current->name);
        current = current->next;
    }
}
