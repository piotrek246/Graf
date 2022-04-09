#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue_t *q){
    q->front = NULL;
    q->rear = NULL;
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
void printQueue(Queue_t *q){
  Qnode_t *tmp = q->front;
  while(tmp != NULL){
    printf("[%d] ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int ifInQueue(Queue_t *q, int value){
  Qnode_t* tmp = q->front;
  while(tmp != NULL){
    if(tmp->data == value)
      return 1;
    tmp = tmp->next;
  }
  return 0;
}
