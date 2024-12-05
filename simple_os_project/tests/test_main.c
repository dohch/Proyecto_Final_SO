#include <stdio.h>

// Declaración de las funciones de prueba
void test_write_data();
void test_read_data();
void test_allocate_memory();
void test_init_scheduler();
void test_schedule_processes();
void test_create_process();
void test_destroy_process();

// Renombramos la función main a run_tests
void run_tests() {
    printf("Running tests...\n");

    test_write_data();
    test_read_data();
    test_allocate_memory();
    test_init_scheduler();
    test_schedule_processes();
    test_create_process();
    test_destroy_process();

    printf("All tests passed!\n");
}
