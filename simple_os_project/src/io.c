#include <stdio.h>
#include "io.h"

// Inicialización de la I/O (no es estrictamente necesaria en este caso, pero se deja por si se expande el sistema)
void init_io() {
    // Aquí podríamos inicializar recursos de I/O si fuera necesario en el futuro
    printf("Sistema de I/O inicializado.\n");
}

// Simula la escritura de datos en la consola
void write_data(const char *data) {
    printf("%s", data);  // Escribe el dato en la consola (salida estándar)
}

// Simula la lectura de datos desde la entrada estándar (por ejemplo, desde el teclado)
char* read_data() {
    static char input_buffer[256];  // Buffer estático para almacenar la entrada
    printf("Introduce datos: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);  // Lee una línea de texto
    return input_buffer;  // Devuelve la entrada
}
