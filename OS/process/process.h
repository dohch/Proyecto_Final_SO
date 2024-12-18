#ifndef PROCESS_H
#define PROCESS_H

struct Process{
    int process_id;
    char* name;
    int burst_time;     // En ms
    int state;
    int quantum_time;
    int priority;
};

struct Process* create_process(char* name, int time, int priority);
void print_process(struct Process*);

#endif
