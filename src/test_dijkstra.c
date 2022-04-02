#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mpq.h"
#include "dijkstra.h"
#include "time.h"

#define N 40

int shortestpath(){
  struct Graph *graf = creategraph(N, N, 1, 20);
  
  for(int i = 0; i < 200; i++){
    int start = rand() % N*N;
    int end = rand() % N*N;
    while(start == end){
      end = rand() % N*N;
    }
    if(dijkstra(graf, start, end) != dijkstra(graf, end, start)){
      printf("SHORTEST PATH TEST: FAILED\n");
      return 1;
    }
  }
  printf("SHORTEST PATH TEST: OK\n");
  return 0;
}

int isolatednode(){
  struct Graph *graf = creategraph(N, N, 1, 20);
  editgraph(graf, 0, 1);
  editgraph(graf, 1, 0);
  editgraph(graf, 0, N);
  editgraph(graf, N, 0);

  if(dijkstra(graf, 0, N/2) == -1 && dijkstra(graf, N/2, 0) == -1){
    printf("ISOLATED NODE TEST: OK\n");
  }
  else{
    printf("ISOLATED NODE TEST: FAILED\n");
    return 1;
  }
  return 0;
}

int main(int argc, char** argv){
  srand(time(NULL));
  struct Graph *graf = creategraph(N, N, 1, 20);

  if(dijkstra(graf, 0, 13) == -1)
    printf("DIJKSTRA TEST: FAILED\n");
  else
    printf("DIJKSTRA TEST: OK\n");

//shortest path test
  shortestpath();

//isolated node test
  isolatednode();


  return 0;
}