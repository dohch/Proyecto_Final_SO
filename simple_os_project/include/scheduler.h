#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"  // Asegúrate de incluir process.h para acceder a la estructura Process

// Funciones del planificador
void init_scheduler();                  // Inicializa el planificador
void schedule_processes();              // Planifica y ejecuta los procesos

#endif
