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
  q->arr = malloc(sizeof(*(q->arr))*n);
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
  for(int i = 0; i <= q->size; i++){
    if(q->arr[i]->v == indx){
      return i;
    }
  }
  return -1;
}
void decrease_key(pq q, int indx, double weight, double pw){
  int i = heapsearch(q, indx);
  if(i == -1)
    return;
  if(weight + pw < q->arr[i]->data)
    q->arr[i]->data = pw + weight;

  while(i > 0 && q->arr[i]->data < q->arr[(i-1)/2]->data){
    swap(q, i, (i-1)/2);
    i = (i-1)/2;
  }
}

int extract(pq q){
  return q->arr[0]->v;
}

/*
void pop(pq q){
  int i = 0;
  int s;
  q->arr[0] = q->arr[q->size];
  q->size--;
  
  while(2*i+1 <= q->size){
    if(q->arr[2*i+1]->data < q->arr[2*i+2]->data)
      if(q->arr[i]->data > q->arr[2*i+1]->data)
        swap(q, 2*i+1, i);
    else
      if(q->arr[i]->data > q->arr[2*i+2]->data)
        swap(q, 2*i+2, i);

    i = 2*i+1;
  }
}*/
int pop(pq q){ // tu bład jakiś
  int i = 0;
  int l = (2*i)+1;
  int r = (2*i)+2;
  int s;
  int result = q->arr[0]->v;
  q->arr[0] = q->arr[q->size];
  q->size--;
  
  if(q->arr[l]->data < q->arr[r]->data)
    s = l;
  else
    s = r;

  while(s < q->size){
    if(q->arr[s]->data < q->arr[s+1]->data)
      s = s;
    else
      s = s+1;
    if(q->arr[i]->data > q->arr[s]->data)
      swap(q, s, i);
    i = s;
    s = 2*i+1;
  }
  return result;
}

