#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "utils.h"

int main(int argc, char** argv){
  if(argc < 2){
    helper();
    return EXIT_FAILURE;
  }
  if(argc < 2 || argc > 2){
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }
  int w, k;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");

  if(in == NULL){ 
    printf("nie mogę czytać\n");
    fclose(in);
    return EXIT_FAILURE;
  }
  else{
    struct Graph* graf = readgraph(in);
    printgraph(stdout, graf);
    freegraph(graf);
    fclose(in);
    fclose(stdout);
  }
  return 0;
}