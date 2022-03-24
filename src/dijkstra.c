#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

void relax(pq q, Graph_t* graf, Node_t* v, hn u){
  if(q->arr[v->dest]->dist > u->dist + v->weight){
    q->arr[v->dest]->dist = u->dist + v->weight;
    q->arr[v->dest]->p = u->v;
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
  printf("p");
  pq q = createpq(graf);
  for(int i = 0; i < n; i++){
    hn k;
    k->dist = d[i];
    k->p = p[i];
    insertpq(q, k);
  }
  while(!ispqempty(q)){
    hn u = pqget(q); //oddaje node z najmniejszym dystansem
    Node_t* v = graf->adjlist[u->v];
    while(v != NULL){
      relax(q, graf, v, u);
      v = v->next;
    }
  }
  for(int i = 0; i < n; i++)
    printf("%lf\n", d[i]);
}

