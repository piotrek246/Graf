#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "bfs.h"
#include "utils.h"


#define MAX_BUF 1024

int main(int argc, char** argv){
  if(argc < 2){
    helper();
    return EXIT_FAILURE;
  }
  if(argc < 3 || argc > 3) {
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }
  if(isNumber(argv[2]) == 1){
    printf("Niepoprawny format numeru węzła\n");
    return 1;
  }

  FILE *in = fopen(argv[1], "r");
  if(in == NULL){ 
    printf("nie mogę czytać\n");
    return EXIT_FAILURE;
  }
  int w, k;
  char *nazwa_pliku = argv[1];
  int start = atoi(argv[2]);

  struct Graph* graf = readgraph(in);
  if(start >= graf->k*graf->w){
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
    int result = bfs(graf, start);
    if(result == 0)
      printf("\nGraf jest spójny\n");
    else
      printf("\nGraf nie jest spójny\n");
    
    freegraph(graf);
    fclose(in);
  }
  return 0;
}