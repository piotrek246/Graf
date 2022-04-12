#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"
#include "graph.h"
#include "dijkstra.h"

#define INF 10000000

void printPath(int p[], int e){
  if (p[e] == -1){
    printf("%d ", e);
    return;
  }
  printPath(p, p[e]);
  printf("%d ", e);
}

distance_parents dijkstra(Graph_t* graf, int s){
  int n = graf->k*graf->w;
  int u;
  int *p = malloc(sizeof(*p)*n);
  double *d = malloc(sizeof(*d)*n);
  distance_parents error;
  error.exit = 1;
  Node_t* v;
  for(int i = 0; i < n; i++){
    d[i] = INF;
    p[i] = -1;
  }
  d[s] = 0;
  pq q = initpq(n);
  
  for(int i = 0; i < n; i++){
    hn k = malloc(sizeof(*k));
    k->data = d[i];
    k->v = i;
    q->heapplace[i] = i;
    push(q, k);
  }

  while(!ispqempty(q)){
    u = pop(q);
    v = graf->adjlist[u];
    if(v->weight < 0){
      printf("Graf z wartościami ujemnymi\n");
      free(p);
      free(d);
      free(q->heapplace);
      free(q->arr);
      free(q);
      return error;
    }
    while(v != NULL){
      if(d[v->dest] > d[u] + v->weight){
        d[v->dest] = d[u] + v->weight;
        p[v->dest] = u;
        decrease_key(q, v->dest, v->weight, d[u]);
      }
      v = v->next;
    }
  }

  distance_parents result;
  result.d = d;
  result.p = p;
  result.exit = 0;

  free(q->heapplace);
  free(q->arr);
  free(q);
  return result;
}

