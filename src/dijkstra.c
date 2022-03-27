#include <stdio.h>
#include <stdlib.h>
#include "mpq.h"
#include "graph.h"

#define INF 10000000

void relax(pq q, Node_t* v, int u, double d[], int p[]){
  if(q->arr[heapsearch(q, v->dest)]->data > q->arr[heapsearch(q, u)]->data + v->weight){
    q->arr[heapsearch(q, v->dest)]->data = q->arr[heapsearch(q, u)]->data + v->weight;
    q->arr[heapsearch(q, v->dest)]->p = u;
  } 
}
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
  int visited[n];
  int u;
  Node_t* v;
  for(int i = 0; i < n; i++){
    d[i] = INF;
    p[i] = -1;
    visited[i] = 0;
  }
  d[s] = 0;
  p[s] = -1;
  pq q = initpq(n);
  
  for(int i = 0; i < n; i++){
    hn k = malloc(sizeof(*k));
    k->data = d[i];
    k->v = i;
    k->p = p[i];
    push(q, k);
  }
  while(!isempty(q)){
    u = extract(q); pop(q);
    v = graf->adjlist[u];
    while(v != NULL){
      if(d[v->dest] > d[u] + v->weight){
        d[v->dest] = d[u] + v->weight;
        p[v->dest] = u;
        decrease_key(q, v->dest, v->weight);
      }
      v = v->next;
    }
  }
  for(int i=0; i< n; i++)
    printf("%g, ", d[i]);
  printPath(p, e);
  printf("\n\n%g", d[e]);
  
  /*
  hn k = malloc(sizeof(*k));
  k->data = d[s];
  k->v = s;
  k->p = p[s];
  push(q, k);

  while(!isempty(q)){
    u = extract(q);
    Node_t* v = graf->adjlist[u];
    while(v != NULL){
      if(d[v->dest] > d[u] + v->weight ){
        d[v->dest] = d[u] + v->weight;
        p[v->dest] = u;
      }
      if(visited[v->dest] == 0){
        k->data = v->weight;
        k->v = v->dest;
        k->p = u;
        push(q, k);
        v = v->next;
      }
      v = v->next;
    }
    visited[u] = 1;
    pop(q);
  }
  */
}


