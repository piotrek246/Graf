#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"

int isempty(pq q){
  return (q->size < 0);
}

pq initpq(int n){
  pq q = malloc(sizeof(*q));
  q->size = -1;
  q->arr = malloc(n*sizeof(hn));
  return q;
}

void swap(pq q, int i, int p){
  hn tmp = q->arr[p];
  q->arr[p] = q->arr[i];
  q->arr[i] = tmp;
}

void swaparr(int hp[], int i, int j){
  int tmp = hp[i];
  hp[i] = hp[j];
  hp[j] = tmp;
}

void push(pq q, int heapplace[], hn new){
  q->size++;
  int i = q->size;
  q->arr[i] = new;
  
  while(i > 0 && q->arr[i]->data < q->arr[(i-1)/2]->data){
    swaparr(heapplace, q->arr[i]->v, q->arr[(i-1)/2]->v);
    swap(q, i, (i-1)/2);
    i = (i-1)/2;
  }
}

void decrease_key(pq q, int heapplace[], int indx, double weight, double pw){
  if(heapplace[indx] != -1){
    int i = heapplace[indx];
    if(q->arr[i]->data > pw + weight)
      q->arr[i]->data = pw + weight;
    while(i > 0 && q->arr[i]->data < q->arr[(i-1)/2]->data){
      swaparr(heapplace, q->arr[i]->v, q->arr[(i-1)/2]->v);
      swap(q, i, (i-1)/2);
      i = (i-1)/2;
    }
  }
}

int pop(pq q, int heapplace[]){
  int i = 0;
  int s = 2*i+1;
  int result = q->arr[0]->v;
  hn tmp = q->arr[0];
  heapplace[q->arr[q->size]->v] = 0;
  heapplace[q->arr[0]->v] = -1;
  q->arr[0] = q->arr[q->size];
  q->size--;
  
  if(q->size >= 2 && q->arr[s]->data < q->arr[s+1]->data)
    ;
  else
    s += 1;

  while(s <= q->size){
    if( q->size >= 2 && q->arr[s]->data < q->arr[s+1]->data)
      ;
    else
      s += 1;

    if(q->arr[i]->data > q->arr[s]->data){
      swaparr(heapplace, q->arr[i]->v, q->arr[s]->v);
      swap(q, s, i);
    }
    i = s;
    s = 2*i+1;
  }
  free(tmp);
  return result;
}

