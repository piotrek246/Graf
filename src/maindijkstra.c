#include <stdio.h>
#include <stdlib.h>
#include "pq.h"
#include "dijkstra.h"

#define MAX_BUF 1024

int main(int argc, char** argv){
  if(argc < 3 || argc > 3) {
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }
  int w, k;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");
  int start = atoi(argv[2]);
  
  struct Graph* graf = readgraph(in);
  if(start >= graf->k*graf->w){
    printf("Podano numer węzła który nie należy do grafu\n");
    return EXIT_FAILURE;
  }
  if(in == NULL){ 
    printf("nie mogę czytać\n");
    fclose(in);
    return 1;
  }
  else{
    dijkstra(graf, start);
    freegraph(graf);
    fclose(in);
  }
  return 0;
}