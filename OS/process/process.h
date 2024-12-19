#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int name;
    int priority;
    int burst_time;
    int state;
    struct Process* next_process;
};

struct Process* Create_Process(int, int, int);
void Delete_Process(struct Process*); 
void print_process(struct Process*);

#endif
