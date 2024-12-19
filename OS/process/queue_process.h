#include "process.h"
#include "../memory/memory.h"
#include <stddef.h>

struct Stack {
    struct Process* first;
};

void init_Stack_Process();
struct Process* best_process();
struct Process* stack_pop();
void stack_put(struct Process*);
void Process_Charge();
void Print_Stack_Process();
void RunTestProcess(int);
