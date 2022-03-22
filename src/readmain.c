#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char** argv){
  int w, k;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");

  FILE *out = stdout;

  if(in == NULL){ 
    printf("nie mogę czytać\n");
    fclose(in);
    return 1;
  }
  else{
    struct Graph* graf = readGraph(in);
    printGraph(out, graf);
    freeGraph(graf);
    fclose(in);
    fclose(out);
  }
  return 0;
}