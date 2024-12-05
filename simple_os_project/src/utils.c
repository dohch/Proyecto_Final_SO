#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Maneja errores imprimiendo un mensaje y terminando la ejecución del programa
void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Imprime mensajes de depuración en la consola
void log_message(const char *message) {
    printf("Log: %s\n", message);
}
