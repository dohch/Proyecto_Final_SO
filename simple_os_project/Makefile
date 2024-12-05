# Definición de variables
CC = gcc
CFLAGS = -Wall -g -std=c99
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
OUT_DIR = out

# Archivos fuente
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/scheduler.c $(SRC_DIR)/memory.c $(SRC_DIR)/io.c \
            $(SRC_DIR)/process.c $(SRC_DIR)/interrupt.c $(SRC_DIR)/utils.c

# Archivos objeto
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nombre del ejecutable
EXEC = $(OUT_DIR)/simple_os

# Regla predeterminada
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJ_FILES)
	@mkdir -p $(OUT_DIR)
	rm -f $(EXEC)  # Limpiar el ejecutable existente
	$(CC) $(OBJ_FILES) -o $(EXEC)

# Regla para compilar archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR) $(EXEC)

# Regla para realizar pruebas
tests: 
	@mkdir -p $(OUT_DIR)
	$(CC) $(SRC_DIR)/test_scheduler.c -o $(OUT_DIR)/test_scheduler $(CFLAGS) -I$(INCLUDE_DIR)
	$(CC) $(SRC_DIR)/test_memory.c -o $(OUT_DIR)/test_memory $(CFLAGS) -I$(INCLUDE_DIR)
	$(CC) $(SRC_DIR)/test_io.c -o $(OUT_DIR)/test_io $(CFLAGS) -I$(INCLUDE_DIR)
	$(CC) $(SRC_DIR)/test_process.c -o $(OUT_DIR)/test_process $(CFLAGS) -I$(INCLUDE_DIR)

# Regla para ejecutar las pruebas
run_tests:
	$(OUT_DIR)/test_scheduler
	$(OUT_DIR)/test_memory
	$(OUT_DIR)/test_io
	$(OUT_DIR)/test_process

# Regla para compilar sin ejecutar pruebas
build: $(EXEC)

# Regla para depuración (con gdb)
debug: $(EXEC)
	gdb $(EXEC)

.PHONY: all clean tests run_tests build debug
