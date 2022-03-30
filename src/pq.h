
#include "graph.h"
#ifndef PQ_H
#define PQ_H

typedef struct hn{
  int v;
  int p;
  double dist;
} *hn;

typedef struct pq{
  hn *arr;
  int size;
} *pq;

int ispqempty(pq q);
pq createpq(Graph_t* graf);
void pqswap(pq q, int i, int j);
void fixup(pq q, int i);
void fixdown(pq q, int i);
void insertpq(pq q, hn k);
hn pqget(pq q);
void heapify(pq q);

#endif