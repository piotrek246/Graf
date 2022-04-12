#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"

int push_test(pq q){
  for(int i = 0; i < 7; i++){
    hn k = malloc(sizeof(*k));
    k->data = i*4;
    k->v = i;
    push(q, k);
  }

  hn k = malloc(sizeof(*k));
  k->data = -12;
  k->v = 14;
  push(q, k);
  
  if(q->arr[0]->data != -12)
    return 1;

  return 0;
}

int pop_test(pq q){
  int result = pop(q);
  if(result != 14)
    return 1;
  return 0;
}

int main(int argc, char** argv){
  pq q = initpq(10);

  printf("\nPriority Queue Tests:");
  //------push_test------
  if(push_test(q) != 0)
    printf("\npush_test: FAILED\n");
  else
    printf("\npush_test: OK\n");
  
  //------pop_test-------
  if(pop_test(q) != 0)
    printf("pop_test: FAILED\n");
  else
    printf("pop_test: OK\n");
    
  freepq(q);
  return 0;
}