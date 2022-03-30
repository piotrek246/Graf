#ifndef QUEUE_H
#define QUEUE_H

typedef struct Qnode{
    int data;
    struct Qnode* next;
} Qnode_t;

typedef struct queue{
    struct Qnode* front;
    struct Qnode* rear;
} Queue_t;

void initQueue(Queue_t *q);
int isempty(Queue_t *q);
void enqueue(Queue_t *q, int value);
int dequeue(Queue_t *q);
void printQueue(Queue_t *q);
int ifInQueue(Queue_t *q, int value);
#endif
