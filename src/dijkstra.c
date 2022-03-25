#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"
#include "graph.h"

void relax(pq q, Node_t* v, hn u, double d[], int p[]){
  if(d[v->dest] > d[u->v] + v->weight){
    d[v->dest] = d[u->v] + v->weight;
    p[v->dest] = u->v; 
  }
  if(q->arr[v->dest]->data > q->arr[u->v]->data + v->weight){
    q->arr[v->dest]->data = q->arr[u->v]->data + v->weight;
    q->arr[v->dest]->data = u->v; 
  }
}
void dijkstra(Graph_t* graf, int s){
  int n = graf->k*graf->w;
  int p[n];
  double d[n];
  for(int i = 0; i < n; i++){
    d[i] = 10000000;
    p[i] = 0;
  }
  d[s] = 0;
  pq q = initpq(n);
  for(int i = 0; i < n; i++){
    hn k = malloc(sizeof*k);
    k->data = d[i];
    k->p = p[i];
    k->v = i;
    push(q, k);
  }
  while(!isempty(q)){
    hn u = pop(q);
    Node_t* v = graf->adjlist[u->v];
    while(v != NULL){
      relax(q, v, u, d, p);
      v = v->next;
    }
  }
  for(int i = 0; i < n; i++){
    printf("%lf ", d[i]);
  }
}

