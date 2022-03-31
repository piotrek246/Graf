#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"

int isempty(pq q){
  return (q->size < 0);
}

pq initpq(int n){
  pq q = malloc(sizeof(*q));
  q->size = -1;
  q->arr = calloc(n, sizeof(hn));
  return q;
}

void swap(pq q, int i, int p){
  hn tmp = q->arr[p];
  q->arr[p] = q->arr[i];
  q->arr[i] = tmp;
}

int ifinpq(pq q, int indx){
  for(int i = q->size; i >= 0; i--)
    if(q->arr[i]->v == indx)
      return 1;
  return 0;
}

void push(pq q, hn new){
  q->size++;
  int i = q->size;
  q->arr[i] = new;
  
  while(i > 0 && q->arr[i]->data < q->arr[(i-1)/2]->data){
    swap(q, i, (i-1)/2);
    i = (i-1)/2;
  }
}

int heapsearch(pq q, int indx){
  int i;
  for(i = q->size; i >= 0; i--)
    if(q->arr[i]->v == indx)
      return i;
  return -1;
}
void decrease_key(pq q, int indx, double weight, double pw){
  int i = heapsearch(q, indx);
  if(i == -1){
    return;
  } 
  q->arr[i]->data = pw + weight;
  while(i > 0 && q->arr[i]->data < q->arr[(i-1)/2]->data){
    swap(q, i, (i-1)/2);
    i = (i-1)/2;
  }
}
int extract(pq q){
  return q->arr[0]->v;
}

int pop(pq q){
  int i = 0;
  int s = 2*i+1;
  int result = q->arr[0]->v;
  q->arr[0] = q->arr[q->size];
  q->size--;
  
  if(q->size >= 2 && q->arr[s]->data < q->arr[s+1]->data)
    ;
  else
    s += 1;

  while(s <= q->size && q->arr[i]->data > q->arr[s]->data){
    if( q->size >= 2 && q->arr[s]->data < q->arr[s+1]->data)
      ;
    else
      s += 1;

    //if(q->arr[i]->data > q->arr[s]->data)
    swap(q, s, i);
    i = s;
    s = 2*i+1;
  }
  return result;
}

