#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "dijkstra.h"
#include "mpq.h"

#define N 40

int distance_test(Graph_t *graf, int s){
  int n = graf->k*graf->w;
  distance_parents result = dijkstra(graf, s);
  for(int i = 0; i < n; i++){
    if(result.d[i] == INF)
      return 1;
  }
  return 0;
}

int parents_test(Graph_t *graf, int s){
  int n = graf->k*graf->w;
  distance_parents result = dijkstra(graf, s);
  for(int i = 0; i < n; i++){
    if(result.p[s] != -1 && result.p[i] == -1)
      return 1;
  }
  return 0;
}

int main(int argc, char** argv){
  struct Graph *graf = creategraph(N, N, 1, 20);

  printf("\nDijkstra Test:");
  if(distance_test(graf, 0) != 0)
    printf("\ndistance_test: FAILED\n");
  else
    printf("\ndijkstra_test: OK\n");

  if(parents_test(graf, 0) != 0)
    printf("parents_test: FAILED\n");
  else
    printf("parents_test: OK\n");
  return 0;
}