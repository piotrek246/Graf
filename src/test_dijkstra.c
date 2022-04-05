#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mpq.h"
#include "dijkstra.h"
#include "time.h"

#define N 40

int main(int argc, char** argv){
  srand(time(NULL));
  struct Graph *graf = creategraph(N, N, 1, 20);

  return 0;
}