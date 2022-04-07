#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "utils.h"

int main(int argc, char** argv){
  if(argc < 2){
    helper();
    return EXIT_FAILURE;
  }

  if(argc < 4 || argc > 4){
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }

  //sprawdza czy może pisać
  FILE *out = fopen(argv[1], "r");
  if(out != NULL){ 
    printf("Nie mogę nadpisać\n");
    fclose(out);
    return EXIT_FAILURE;
  }
  else{
    out = fopen(argv[1], "w");
  }
  
  char *nazwa_pliku = argv[1];
  int w, k;
  double min, max;

  if(sscanf(argv[2], "%d:%d", &w, &k) != 2){
    printf("Niepoprawny format rzędów i kolumn\n");
    return EXIT_FAILURE;
  }
  if(w <= 0 || k <=0){
    printf("Niepoprawne wartośći wierszy lub kolumn\n");
    return EXIT_FAILURE;
  }
  if(sscanf(argv[3], "%lf-%lf", &min, &max) != 2){
    printf("Niepoprawnie podany przedział wagi\n");
    return EXIT_FAILURE;
  }
  
  srand(time(NULL));
	struct Graph *graf = creategraph(k, w, min, max);
	printgraph(out, graf);
  freegraph(graf);
  fclose(out);

  return 0;
}