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

void dijkstra(Graph_t* graf, int s, int e){
  int n = graf->k*graf->w;
  int p[n];
  double d[n];
  int u;
  int visited[n];
  Node_t* v;
  for(int i = 0; i < n; i++){
    d[i] = INF;
    p[i] = -1;
    visited[i] = 0;
  }
  d[s] = 0;
  pq q = initpq(n);
  /*
  for(int i = 0; i < n; i++){
    hn k = malloc(sizeof(*k));
    k->data = d[i];
    k->v = i;
    k->p = p[i];
    push(q, k);
  }
  while(!isempty(q)){
    u = pop(q);
    v = graf->adjlist[u];
    while(v != NULL){
      if(d[v->dest] > d[u] + v->weight){
        d[v->dest] = d[u] + v->weight;
        p[v->dest] = u;
        decrease_key(q, v->dest, v->weight, d[u]);
      }
      v = v->next;
    }
  }
  printf("\n\n%g", d[e]);
  printf("\n");
  printPath(p, e);
  */
  
  
  hn k = malloc(sizeof(*k));
  k->data = 0;
  k->v = s;
  k->p = -1;
  push(q, k);

  while(!isempty(q)){
    u = extract(q);
    v = graf->adjlist[u];
    while(v != NULL){
      hn k = malloc(sizeof(*k));
      if(visited[v->dest] == 0 && ifinpq(q, v->dest) == 0){
        k->data = v->weight + d[u];
        k->v = v->dest;
        k->p = u;
        push(q, k);
      }
      if((d[v->dest]) > (d[u] + v->weight) && (visited[v->dest] == 0)){
        d[v->dest] = d[u] + v->weight;
        p[v->dest] = u;
        decrease_key(q, v->dest, v->weight, d[u]);
      }
      v = v->next;
    }
        visited[u] = 1;
    pop(q);
  }
  printf("\n\n%g", d[e]);
  
}


