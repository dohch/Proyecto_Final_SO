CC = gcc
CFLAGS = -Wall -g -std=c99
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
OUT_DIR = out

# Archivos fuente del sistema operativo
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/scheduler.c $(SRC_DIR)/memory.c $(SRC_DIR)/io.c \
            $(SRC_DIR)/process.c $(SRC_DIR)/interrupt.c $(SRC_DIR)/utils.c

# Archivos de prueba
TEST_DIR = tests
TEST_FILES = $(TEST_DIR)/test_scheduler.c $(TEST_DIR)/test_memory.c \
             $(TEST_DIR)/test_io.c $(TEST_DIR)/test_process.c $(TEST_DIR)/test_main.c

# Archivos objeto del sistema operativo
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Archivos objeto de los tests
TEST_OBJ_FILES = $(TEST_FILES:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nombre del ejecutable principal
EXEC = $(OUT_DIR)/simple_os

# Ejecutable de las pruebas
TEST_EXEC = $(OUT_DIR)/test_exec

# Regla predeterminada para compilar el sistema operativo
all: $(EXEC)

# Regla para compilar el sistema operativo
$(EXEC): $(OBJ_FILES)
	@mkdir -p $(OUT_DIR)
	rm -f $(EXEC)  # Limpiar el ejecutable existente
	$(CC) $(OBJ_FILES) -o $(EXEC)

# Regla para compilar los archivos fuente del sistema operativo a archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regla para compilar los archivos de prueba a archivos objeto
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regla para compilar los archivos de prueba y generar el ejecutable de pruebas
tests: $(OBJ_FILES) $(TEST_OBJ_FILES)
	@mkdir -p $(OUT_DIR)
	rm -f $(TEST_EXEC)  # Limpiar el ejecutable de pruebas existente
	$(CC) $(OBJ_FILES) $(TEST_OBJ_FILES) -o $(TEST_EXEC) $(CFLAGS) -I$(INCLUDE_DIR)

# Regla para ejecutar las pruebas
run_tests: tests
	$(TEST_EXEC)

# Regla para limpiar los archivos generados
clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR) $(EXEC) $(TEST_EXEC)

# Regla para compilar sin ejecutar pruebas
build: $(EXEC)

# Regla para depuración (con gdb)
debug: $(EXEC)
	gdb $(EXEC)

.PHONY: all clean tests run_tests build debug
