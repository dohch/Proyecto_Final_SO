void init_Stack_Process(){
  stack->first = NULL;
}
void init_Stack_Process(struct Process* aux){
  stack->first = aux;
}
struct Process* best_process(){
  struct Process* aux = first;
  stack->first = aux->next_process;
  struct Process* best = first;
  while(aux->next_process != NULL){
    if(best->priority <= aux->priority)
      best = aux;
    aux = aux->next_process;
  }
  return best;
}
struct Process* stack_pop(){
  if(stack->first == NULL)
    return NULL;
  return best_process();
}
void stack_put(struct Process* new_pro){
  new_pro->state = 0;
  struct Process* aux = first;
  while(aux->next_process != null)
    aux = aux->next_process;
  aux->next_process = new_pro;
}
void Process_Charge(){
  if(state_queue == NULL_PROCESS_CPU)
    return;
  struct Process* aux = stack_pop();
  if(aux == NULL)
    state_queue = NULL_PROCESS_CPU;
  i = 1;
  while(i < RR){
    if(aux->burst_time == 0)
      break;
    aux->burst_time = aux->burst_time -= 1;
    i++;
  }
  if(aux->burst_time != 0)
    stack_put(aux);
  print_process(aux);
  Process_Charge();
}
