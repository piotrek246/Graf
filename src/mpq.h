#ifndef PQ_H
#define PQ_H

typedef struct hn{
  int v;
  int p;
  double data;
} *hn;

typedef struct pq{
  hn *arr;
  int size;
} *pq;

int isempty(pq q);
pq initpq(int n);
pq push(pq q, hn newnode);
hn pop(pq q);
/*
int ispqempty(pq q);
pq createpq(int n);
void pqswap(pq q, int i, int j);
void fixup(pq q, int i);
void fixdown(pq q, int i);
void insertpq(pq q, hn k);
hn pqget(pq q);
void heapify(pq q);
*/
#endif