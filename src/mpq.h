#ifndef PQ_H
#define PQ_H

typedef struct hn{
  double data;
  int v;
} *hn;

typedef struct pq{
  hn *arr;
  int size;
} *pq;

int ispqempty(pq q);
pq initpq(int n);
void push(pq q, int heapplace[], hn new);
int pop(pq q, int heapplace[]);
void decrease_key(pq q, int heapplace[], int indx, double weight, double pw);

#endif