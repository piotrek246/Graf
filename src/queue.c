#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue_t *initQueue(){
  Queue_t *q = malloc(sizeof(*q)); 
  q->front = NULL;
  q->rear = NULL;
  return q;
}

int isempty(Queue_t *q){
    return (q->rear == NULL);
}

void enqueue(Queue_t *q, int value){
  Qnode_t* tmp = malloc(sizeof(*tmp));
  tmp->data = value;

  if(!isempty(q)){
    q->rear->next = tmp;
    q->rear = tmp;
  }
  else
    q->front = q->rear = tmp;
}
int dequeue(Queue_t *q){
  Qnode_t* tmp = q->front;
  int n = q->front->data;
  tmp = q->front;
  
  if(tmp == q->rear){
    q->front = NULL;
    q->rear = NULL;
    free(tmp);
    return n;
  }
  q->front = q->front->next;
  free(tmp);
  return n;
}