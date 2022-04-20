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
  int *result;
  int start = atoi(argv[2]);

  struct Graph* graf = readgraph(in);
  if(graf == NULL){
    printf("Błędny format pliku\n");
    return EXIT_FAILURE;
  }
  int n = graf->w*graf->k;

  if(start >= n || start < 0){
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
    result = bfs(graf, start);

    for(int i = 0; i < n; i++){
      if(result[i] != BLACK){
        printf("\nGraf nie jest spójny\n");
        freegraph(graf);
        //free(graf);
        free(result);
        fclose(in);
        return EXIT_FAILURE; 
      }
    }
    printf("\nGraf jest spójny\n");
    freegraph(graf);
    free(result);
    fclose(in);
  }
  return 0;
}