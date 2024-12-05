#ifndef PROCESS_H
#define PROCESS_H

typedef struct Process {
    int pid;
    char *name;
    void *memory;
    struct Process *next;
} Process;

// Cola de procesos global (declarada extern para uso en otros archivos)
extern Process *process_queue;

void create_process(int pid, char *name);
void add_process_to_queue(int pid, char *name);
void destroy_process(int pid);
void print_process_queue();

#endif
