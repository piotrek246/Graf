#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

int ispqempty(pq q){
  if(q->size < 0)
    return 1;
  return 0;
}
pq createpq(Graph_t* graf){
  int n = graf->w*graf->k;
  pq q = malloc(sizeof(*q));
  q->size = -1;
  q->arr = malloc(sizeof(*(q->arr))*n);
  return q;
}
void pqswap(pq q, int i, int j){
  hn t = q->arr[i];
  q->arr[i] = q->arr[j];
  q->arr[j] = t;
}
void fixup(pq q, int i){
  while(i > 1 && q->arr[i] < q->arr[(i-1)/2]){
    pqswap(q, (i-1)/2, i);
    i /= 2;
  }
}
void fixdown(pq q, int i){
  while((2*i)+1 <= q->size){
    int j = (2*i)+1;
    if(j < q->size && q->arr[j+1] < q->arr[j])
      j++;
    if(q->arr[i] <= q->arr[j])
      break;
    pqswap(q, i, j);
    i = j;
  }
}
void insertpq(pq q, hn k){
  q->size += 1;
  q->arr[q->size] = k;
  fixup(q, q->size);
}
hn pqget(pq q){
  hn result = q->arr[0];
  q->arr[0] = q->arr[q->size];
  heapify(q);

  return result;
}
void heapify(pq q){
  for(int i = 0; i < q->size; i++)
    fixdown(q, i);
}

