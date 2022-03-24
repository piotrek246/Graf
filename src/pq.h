
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
/*
void swap(int *a, int *b);
int leftchild(int i);
int rightchild(int i);
int parent(int i);
void shiftup(int h[], int i);
void shiftdown(int h[], int i);
void insert(int h[], int p);
int extractmin(int h[]);
void changepriority(int h[], int i, int p);
int pqget(int h[]);
void removenode(int h[], int i);
int ispqempty();
int *priorityq(Graph_t* graf, int d[]);*/
#endif