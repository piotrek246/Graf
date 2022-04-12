#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"
#include "graph.h"

int color_test(Graph_t *graf, int s){
  int n = graf->k*graf->w;
  int *result = bfs(graf, s);
  for(int i = 0; i < n; i++)
    if(result[i] != BLACK)
      return 1;
  return 0;
}

int main(int argc, char**argv){
  struct Graph *graf = creategraph(40, 40, 1, 20);
  
  printf("\nBFS Test:");
  if(color_test(graf, 0))
    printf("\nColor test: FAILED\n");
  else
    printf("\nColor test: OK\n");

  return 0;
}