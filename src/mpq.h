#ifndef PQ_H
#define PQ_H

typedef struct hn{
  long double data;
  long int v;
  long int p;
} *hn;

typedef struct pq{
  hn *arr;
  long int size;
} *pq;

hn createheapnode(double w, int v, int p);
int isempty(pq q);
pq initpq(int n);
void push(pq q, hn newnode);
int pop(pq q);
int extract(pq q);
int heapsearch(pq q, int indx);
void decrease_key(pq q, int indx, double weight, double pw);
int ifinpq(pq q, int indx);
//void decrease_key(pq q, int indx, double weight);

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