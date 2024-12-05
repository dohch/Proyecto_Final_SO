#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "memory.h"
#include "io.h"
#include "process.h"
#include "interrupt.h"

int main() {
    // 1. Inicialización de módulos
    write_data("Inicializando el sistema operativo...\n");

    // Inicializar el planificador de procesos
    init_scheduler();

    // Inicializar memoria
    init_memory();

    // Inicializar operaciones de entrada/salida (I/O)
    init_io();

    // Inicializar interrupciones
    init_interrupts();

    // 2. Crear algunos procesos para prueba
    write_data("Creando procesos...\n");
    create_process(1, "Proceso 1");  // Ahora pasamos ambos argumentos
    create_process(2, "Proceso 2");

    // 3. Asignar memoria a los procesos (esto es un ejemplo básico)
    write_data("Asignando memoria a los procesos...\n");
    void *mem1 = allocate_memory(128);  // 128 bytes para el Proceso 1
    void *mem2 = allocate_memory(128);  // 128 bytes para el Proceso 2

    // Verificar si la memoria fue asignada correctamente
    if (mem1 != NULL && mem2 != NULL) {
        write_data("Memoria asignada correctamente a los procesos.\n");
    } else {
        write_data("Error en la asignación de memoria.\n");
    }

    // 4. Añadir los procesos al planificador
    add_process_to_queue(1, "Proceso 1");  // Asegúrate de pasar el nombre
    add_process_to_queue(2, "Proceso 2");  // Asegúrate de pasar el nombre

    // 5. Ejecutar el planificador de procesos
    write_data("Ejecutando el planificador...\n");
    schedule_processes();  // El planificador empezará a ejecutar los procesos

    // 6. Simulación de una interrupción
    simulate_interrupt();  // Simula la llegada de una interrupción

    // 7. Manejo de I/O: Simulando alguna operación de salida
    write_data("Sistema operativo en ejecución. Todos los procesos han sido ejecutados.\n");

    // Finalización
    return 0;
}
