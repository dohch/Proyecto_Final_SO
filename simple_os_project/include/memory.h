#ifndef MEMORY_H
#define MEMORY_H

// Inicializa el sistema de gestión de memoria
void init_memory();

// Asigna un bloque de memoria de un tamaño específico
void *allocate_memory(int size);

// Libera un bloque de memoria previamente asignado
void free_memory(void *ptr);

#endif
