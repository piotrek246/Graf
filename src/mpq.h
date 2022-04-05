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

int isempty(pq q);
pq initpq(int n);
void push(pq q, int heapplace[], hn new);
int pop(pq q, int heapplace[]);
hn extract(pq q);
int heapsearch(pq q, int indx);
//void decrease_key(pq q, int indx, double weight, double pw);
void decrease_key(pq q, int heapplace[], int indx, double weight, double pw);
int ifinpq(pq q, int indx);

#endif