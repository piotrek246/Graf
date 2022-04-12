#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int enqueue_test(Queue_t *q, int n, int m, int k){

  enqueue(q, n);
  if(q->front->data != n)
    return 1;
  enqueue(q, m);
  if(q->rear->data != m)
    return 1;
  enqueue(q, k);
  if(q->rear->data != k)
    return 1;

  return 0;
}

int dequeue_test(Queue_t *q, int n){
  if(dequeue(q) != n)
    return 1;

  return 0;
}

int main(int argc, char** argv){
  Queue_t *q = malloc(sizeof(*q)); 
  initQueue(q);
  printf("\nFIFO Tests:");

  //------enqueue_test------
  if(enqueue_test(q, 4, 5, 6) != 0)
    printf("\nenqueue_test: FAILED\n");
  else
    printf("\nenqueue_test: OK\n");
  
  //------dequeue_test------
  if(dequeue_test(q, 4) != 0)
    printf("dequeue_test: FAILED\n");
  else
    printf("dequeue_test: OK\n");



  return 0;
}