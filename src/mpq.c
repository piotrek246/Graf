#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"

int isempty(pq q){
  return (q->size < 0);
}

pq initpq(int n){
  pq q = malloc(sizeof(*q));
  q->size = -1;
  q->arr = malloc(sizeof(*(q->arr))*n);
  return q;
}

void swap(pq q, int i, int p){
  hn tmp = q->arr[p];
  q->arr[p] = q->arr[i];
  q->arr[i] = tmp;
  //free(tmp);
}

pq push(pq q, hn newnode){
  q->size+=1;
  int i = q->size;
  int p = (i-1)/2;
  int l = (2*p)+1;
  q->arr[i] = newnode;
  while(i > 1 && newnode->data <= q->arr[(i-1)/2]->data){
    swap(q, i, (i-1)/2);
    i = (i-1)/2;
  }
  return q;
}

hn pop(pq q){
  int i = 0;
  int l = (2*i)+1;
  int r = (2*i)+2;
  int s;
  hn result = q->arr[0];
  q->arr[0] = q->arr[q->size];
  q->size--;
  
  if(q->arr[l]->data < q->arr[r]->data)
    s = l;
  else
    s = r;

  while(s <= q->size && q->arr[i]->data > q->arr[s]->data){
    swap(q, s, i);
    i = s;
  }
  return result;
}

