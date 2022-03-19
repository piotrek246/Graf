#include <stdio.h>
#include <stdlib.h>

typedef struct qnode{
    int data;
    struct qnode *next;
} qNode_t;

typedef struct queue{
    int count;
    qNode_t *front;
    qNode_t *rear;
} Queue_t;

void initQueue(Queue_t *q);
int isempty(Queue_t *q);
void enqueue(Queue_t *q, int value);
int dequeue(Queue_t *q);void display(qNode_t *head);
void printQueue(Queue_t *q);
int ifInQueue(Queue_t *q, int value);

