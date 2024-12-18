#define RR 5
#define PROCESS_CPU 1
#define NULL_PROCESS_CPU 2

#include "process.h"

struct Stack_Process{
    struct Process* first
}stack;

static int state_queue = NULL_PROCESS_CPU;

init_Stack_Process();
init_Stack_Process(struct Process*);
struct Process* stack_pop();
void stack_put(struct Process* new_pro);
void Process_Charge();


