#include "queue_process.h"
struct Stack* stack;
int RR = 5;
#define NULL_PROCESS_CPU -1
int state_queue = 0;

void init_Stack_Process() {
    stack = (struct Stack*)OS_malloc(sizeof(struct Stack));
    stack->first = NULL;
}

struct Process* best_process() {
    struct Process* aux = stack->first;
    if (aux == NULL) return NULL;

    struct Process* best = aux;
    struct Process* prev = NULL;
    struct Process* prevBest = NULL;

    while (aux != NULL) {
        if (best->priority < aux->priority) {
            best = aux;
            prevBest = prev;
        }
        prev = aux;
        aux = aux->next_process;
    }

    if (prevBest == NULL) {
        stack->first = best->next_process;
    } else {
        prevBest->next_process = best->next_process;
    }

    best->next_process = NULL;
    return best;
}

struct Process* stack_pop() {
    if (stack->first == NULL) return NULL;
    return best_process();
}

void stack_put(struct Process* new_pro) {
    new_pro->state = 0;
    new_pro->next_process = NULL;

    if (stack->first == NULL) {
        stack->first = new_pro;
        return;
    }

    struct Process* aux = stack->first;
    while (aux->next_process != NULL) {
        aux = aux->next_process;
    }
    aux->next_process = new_pro;
}

void Process_Charge() {
    if (state_queue == NULL_PROCESS_CPU) return;

    struct Process* aux = stack_pop();
    if (aux == NULL) {
        state_queue = NULL_PROCESS_CPU;
        return;
    }

    int i = 0;
    while (i < RR) {
        if (aux->burst_time == 0) break;
        aux->burst_time -= 1;
        i++;
    }

    print_process(aux);
    if (aux->burst_time > 0) stack_put(aux);
    else Delete_Process(aux);
    Process_Charge();
}

void Print_Stack_Process() {
    struct Process* aux = stack->first;
    print("\nProcesos en la pila:\n");
    if( aux == NULL) {
        return;
    }
    while (aux != NULL) {
        print_process(aux);
        aux = aux->next_process;
    }
}

void RunTestProcess(int n_process) {
    int i = 1;
    print("\nInicializando Stack_Process\n");
    init_Stack_Process();
    while (i <= n_process) {
        stack_put(Create_Process(i, i * 5, 1));
        i++;
    }
    Process_Charge();
}
