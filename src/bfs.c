#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graf.h"
#include <stdbool.h> 

int bfs(struct Graph* graf, int start){
  int n = graf->k * graf->w;
  bool visited[n];

  for(int i = 0; i < n; i++){
    visited[i] = false;
  }

  Queue_t *q = malloc(sizeof(q)); 
  initQueue(q);
  enqueue(q, start);

  while(!isempty(q)){
    struct Node* node = graf->head[q->front->data];

    while(node != NULL){
      if(ifInQueue(q, node->dest))
        node = node->next;

      if(visited[node->dest] == true)
        node = node->next;

      else{
        enqueue(q, node->dest);
        node = node->next;
      }
    }
    visited[dequeue(q)] = true;
  }

  for(int i = 0; i < n; i++){
    if(visited[i] == false)
      return 1;
  }
  return 0;
}