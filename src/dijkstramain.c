#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mpq.h"
#include "dijkstra.h"

int main(int argc, char** argv){
  if(argc < 4) {
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }
  int w, k;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");
  int start = atoi(argv[2]);
  int end = atoi(argv[3]);

  struct Graph* graf = readgraph(in);
  
  if(end >= graf->k*graf->w || start >=graf->k*graf->w){
    printf("Podano numer węzła który nie należy do grafu\n");
    freegraph(graf);
    fclose(in);
    return EXIT_FAILURE;
  }
  if(in == NULL){ 
    printf("nie mogę czytać\n");
    freegraph(graf);
    fclose(in);
    return 1;
  }
  else{
    double *d = dijkstra(graf, start);
    if(d == NULL)
      return EXIT_FAILURE;
    printf("%g\n",d[end]);
    freegraph(graf);
    fclose(in);
  }
  return 0;
}