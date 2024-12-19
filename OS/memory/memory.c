#include "../include/print.h"
#include "memory.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MEMORY_SIZE 1024 // Tamaño total de la memoria simulada en bytes
#define PAGE_SIZE 64     // Tamaño de cada página en bytes
#define NUM_PAGES (MEMORY_SIZE / PAGE_SIZE)

static uint8_t memory[MEMORY_SIZE]; // Memoria simulada
static bool page_table[NUM_PAGES];  // Tabla de páginas (true = usada, false = libre)

// Inicializa la tabla de páginas
void init_memory() {
    size_t i;
    for (i = 0; i < NUM_PAGES; i++) {
        page_table[i] = false; // Todas las páginas están libres al inicio
    }
}

// Encuentra un bloque contiguo de páginas libres
static int find_free_pages(size_t num_pages) {
    size_t i;
    size_t free_count = 0;
    for (i = 0; i < NUM_PAGES; i++) {
        if (!page_table[i]) {
            free_count++;
            if (free_count == num_pages) {
                return i - num_pages + 1; // Inicio del bloque
            }
        } else {
            free_count = 0; // Reinicia la cuenta si encuentras una página ocupada
        }
    }
    return -1; // No hay suficiente espacio
}

// Asigna memoria simulando la paginación
void* OS_malloc(size_t size) {
    size_t i;
    print("Asignando memoria\n");

    size_t num_pages = (size + PAGE_SIZE - 1) / PAGE_SIZE; // Cálculo del número de páginas necesarias

    int start_page = find_free_pages(num_pages);
    if (start_page == -1) {
        print("Error: No hay suficiente memoria\n");
        return NULL; // No hay suficiente memoria
    }

    // Marca las páginas como usadas
    for (i = 0; i < num_pages; i++) {
        page_table[start_page + i] = true;
    }

    // Retorna la dirección base del bloque asignado
    return &memory[start_page * PAGE_SIZE];
}

// Libera memoria simulando la paginación
void OS_free(void* ptr) {
    size_t i;
    print("Liberando memoria\n");

    uintptr_t offset = (uintptr_t)ptr - (uintptr_t)memory;
    if (offset >= MEMORY_SIZE) {
        print("Error: Puntero fuera de los límites\n");
        return; // Puntero fuera de la memoria simulada
    }

    size_t start_page = offset / PAGE_SIZE;

    // Marca las páginas como libres hasta encontrar una página no usada
    for (i = start_page; i < NUM_PAGES && page_table[i]; i++) {
        page_table[i] = false;
    }
}

// Funciones de prueba
void print_memory_state() {
    size_t i;
    print("Estado de la tabla de páginas:\n");
    for (i = 0; i < NUM_PAGES; i++) {
        print(page_table[i] ? "[X]" : "[ ]");
        if ((i + 1) % 8 == 0) {
            print("\n");
        }
    }
    print("\n");
}
