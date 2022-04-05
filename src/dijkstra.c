#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"
#include "graph.h"

#define INF 10000000

void printPath(int p[], int e){
  if (p[e] == -1){
    printf("%d ", e);
    return;
  }
  printPath(p, p[e]);
  printf("%d ", e);
}

double *dijkstra(Graph_t* graf, int s){
  int n = graf->k*graf->w;
  int u;
  int *p = malloc(sizeof(int)*n);
  double *d = malloc(sizeof(double)*n);
  int *heapplace = malloc(sizeof(int)*n);
  Node_t* v;
  for(int i = 0; i < n; i++){
    d[i] = INF;
    p[i] = -1;
    heapplace[i] = i;
  }
  d[s] = 0;
  pq q = initpq(n);
  
  for(int i = 0; i < n; i++){
    hn k = malloc(sizeof(*k));
    k->data = d[i];
    k->v = i;
    push(q, heapplace, k);
  }
  
  while(!isempty(q)){
    u = pop(q, heapplace);
    v = graf->adjlist[u];
    if(v->weight < 0){
      printf("Graf z wartościami ujemnymi\n");
      return NULL;
    }
    while(v != NULL){
      if(d[v->dest] > d[u] + v->weight){
        d[v->dest] = d[u] + v->weight;
        p[v->dest] = u;
        decrease_key(q, heapplace, v->dest, v->weight, d[u]);
      }
      v = v->next;
    }
  }
  //if(d[e] == INF){
  //  return -1;
  //}

  //int end = d[e];
  //printf("\n%lf", d[e]);
  //printPath(p, e);
  //printf("\n");
  free(p);
  free(heapplace);
  free(q->arr);
  free(q);
  return d;
}


