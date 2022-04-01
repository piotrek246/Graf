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
  if(d[e] == INF){
    printf("Nie ma połączenia z %d do %d\n", s, e);
    return;
  }
*/   

  //---------------UCS---------------
  
  hn k = malloc(sizeof(hn));
  k->data = 0;
  k->v = s;
  push(q, k);
  
  while(!isempty(q)){
    u = pop(q);
    v = graf->adjlist[u];
    while(v != NULL){
      if(visited[v->dest] == 0 ){
        hn m = malloc(sizeof(*m));
        m->data = v->weight + d[u];
        m->v = v->dest;
        push(q, m);

      }
      if(d[v->dest] > v->weight + d[u]){
        d[v->dest] = v->weight + d[u];
        p[v->dest] = u;
      }
      v = v->next;
    }
    visited[u] = 1;
  }
  if(visited[e] != 1){
    printf("Nie ma połączenia z %d do %d\n", s, e);
    return;
  }
  //free(k);

  
  printf("\n%g\n", d[e]);
  printPath(p, e);
  printf("\n");
  
  //free(q->arr);
  //free(q);
}


