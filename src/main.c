#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

int main(int argc, char** argv){
  srand(time(NULL));

  char *nazwa_pliku = argv[1];
  int w, k;
  double min, max;

  sscanf(argv[2], "%d:%d", &w, &k);
  sscanf(argv[3], "%lf-%lf", &min, &max);

  //sprawdza czy może pisać
  FILE *out = fopen(argv[1], "r");
  if(out != NULL){ 
    printf("nie mogę nadpisać\n");
    fclose(out);
    return 1;
  }
  else{
    out = fopen(argv[1], "w");
  }
  
	struct Graph *graf = createGraph(k, w, min, max);
	printGraph(out, graf);
  freeGraph(graf);
  fclose(out);
  return 0;
}