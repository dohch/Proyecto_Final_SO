#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "scheduler.h"  // Asegúrate de incluir scheduler.h para acceder a process_queue

// Inicializa el sistema de interrupciones (si es necesario)
void init_interrupts();

// Maneja una interrupción (como la del temporizador)
void handle_interrupt();

// Funciones auxiliares
void simulate_interrupt();  // Simula la ocurrencia de una interrupción

#endif
