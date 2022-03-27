#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"

hn createheapnode(double w, int v, int p){
  hn k = malloc(sizeof(*k));
  k->data = w;
  k->v = v;
  k->p = p;
  return k;
}

int isempty(pq q){
  return (q->size < 0);
}

pq initpq(int n){
  pq q = malloc(sizeof(*q));
  q->size = -1;
  q->arr = malloc(sizeof(*(q->arr))*n*n);
  return q;
}

void swap(pq q, int i, int p){
  hn tmp = q->arr[p];
  q->arr[p] = q->arr[i];
  q->arr[i] = tmp;
  //free(tmp);
}

void push(pq q, hn newnode){
  q->size++;
  int i = q->size;
  q->arr[i] = newnode;
  while(i > 0 && newnode->data < q->arr[(i-1)/2]->data){
    swap(q, i, (i-1)/2);
    i = (i-1)/2;
  }
  //return q;
}

int heapsearch(pq q, int indx){
  for(int i = 0; i < q->size; i++){
    if(q->arr[i]->v == indx){
      return i;
    }
  }
  return -1;
}
void decrease_key(pq q, int indx, double weight){
  int i, tmp;
  tmp = heapsearch(q, indx);
  i = (tmp-1)/2;
  while(i > 0 && weight < q->arr[(i-1)/2]->data){
    swap(q, tmp, (i-1)/2);
    i = (i-1)/2;
  }
}

int extract(pq q){
  return q->arr[0]->v;
}

void pop(pq q){
  int i = 0;
  int l = (2*i)+1;
  int r = (2*i)+2;
  int s;
  //int result = q->arr[0];
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
  //return result;
}

