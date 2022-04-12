#ifndef PQ_H
#define PQ_H

typedef struct hn{
  double data;
  int v;
} *hn;

typedef struct pq{
  hn *arr;
  int *heapplace;
  int size;
} *pq;

int ispqempty(pq q);
pq initpq(int n);
void push(pq q, hn new);
int pop(pq q);
void decrease_key(pq q, int indx, double weight, double pw);
void freepq(pq q);

#endif