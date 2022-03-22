#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

enum colors{WHITE, GRAY, BLACK};

int bfs(Graph_t* graf, int s){

  int n = graf->k * graf->w;
  int color[n];
  int distance[n];
  int parent[n];
  Queue_t *q = malloc(sizeof(*q)); 
  initQueue(q);

  for(int i = 0; i < n; i++){
    color[i] = WHITE;
    distance[i] = -1;
    parent[i] = 0;
  }
  color[s] = GRAY;
  distance[s] = 0;
  parent[s] = 0;
  enqueue(q, s);
  
  while(!isempty(q)){
    int w = dequeue(q);
    Node_t* node = graf->adjlist[w];
    while(node != NULL){
      int v = node->dest;
      if(color[v] == WHITE){
        color[v] = GRAY;
        distance[v] = distance[w] + 1;
        parent[v] = w;
        enqueue(q, v);
      }
      node = node->next;
    }
    color[w] = BLACK;
  }
  for(int i = 0; i < n; i++){
    if(color[i] != BLACK)
      return 1;
  }
  return 0;
}