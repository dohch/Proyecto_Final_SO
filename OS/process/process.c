#include "process.h"
#include <stddef.h>

#include "../include/print.h"
#include "../memory/memory.h"

struct Process* create_process (char* name, int time, int priority){
  struct Process *p = (struct Process*)OS_malloc(sizeof(struct Process));
  p->name = name;
  p->burst_time = time;
  return p;
}
void delete_process (struct Process* p){
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
    print("\nName: ");
    print(p->name);
    print("\nPriority: ");
    print_num(p->priority);
    print("\n");
    print("======================================\n");
    delete_process(p);
}
