#include "process.h"
#include "../include/print.h"
#include "../memory/memory.h"
#include <stddef.h>

struct Process* Create_Process(int name, int burst_time, int priority) {
    struct Process* new_pro = (struct Process*)OS_malloc(sizeof(struct Process));
    new_pro->name = name;
    new_pro->priority = priority;
    new_pro->burst_time = burst_time;
    new_pro->state = 0;
    new_pro->next_process = NULL;
    return new_pro;
}

void Delete_Process (struct Process* p){
  OS_free(p);
}

void print_process(struct Process* p){
    if (p == NULL) {
         print("Error: El puntero al proceso es NULL.\n");
         return;
    }
    print("======================================\n");
    print("Size (KB): "); 
    print_num(p->burst_time);
    print("\nPDI: ");
    print_num(p->name);
    print("\nPriority: ");
    print_num(p->priority);
    print("\n");
    print("======================================\n");
}
