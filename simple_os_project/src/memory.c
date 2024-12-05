    #include <stdio.h>
    #include <stdlib.h>
    #include "memory.h"

    #define MEMORY_SIZE 1024  // Tamaño total de la memoria disponible
    static char memory[MEMORY_SIZE];  // Bloque de memoria global
    static int memory_offset = 0;     // Indicador de la última posición libre

    // Inicializa la gestión de memoria
    void init_memory() {
        memory_offset = 0;  // Restablecer el puntero de memoria al inicio
        printf("Memoria inicializada.\n");
    }

    // Asigna un bloque de memoria de un tamaño específico
    void *allocate_memory(int size) {
        // Verificar si hay suficiente memoria disponible
        if (memory_offset + size <= MEMORY_SIZE) {
            void *ptr = &memory[memory_offset];  // Obtener un puntero al bloque de memoria libre
            memory_offset += size;  // Mover el puntero de memoria hacia adelante
            return ptr;
        } else {
            // Si no hay suficiente memoria, retornar NULL
            printf("Error: No hay suficiente memoria disponible.\n");
            return NULL;
        }
    }

    // Libera un bloque de memoria previamente asignado
    void free_memory(void *ptr) {
        // Para simplificar, no implementamos la liberación de memoria
        // En un sistema operativo real, esto sería más complejo
        printf("Liberación de memoria no implementada en esta versión.\n");
    }
