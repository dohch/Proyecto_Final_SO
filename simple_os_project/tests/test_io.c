#include <stdio.h>
#include <assert.h>
#include "io.h"

// Función de prueba para verificar la escritura en consola
void test_write_data() {
    init_io();
    write_data("Hola Mundo\n");  // Verificar que no cause errores
    printf("test_write_data PASSED\n");
}

// Función de prueba para verificar la lectura de datos
void test_read_data() {
    init_io();
    char *input = read_data();  // Introducir datos manualmente al ejecutar
    assert(input != NULL);  // Verificar que se lee correctamente
    printf("test_read_data PASSED\n");
}


