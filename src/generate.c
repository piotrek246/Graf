#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "graph.h"
#include "utils.h"
#include <string.h>
#include "bfs.h"

int main(int argc, char**argv){
  if(argc < 2){
    helper();
    return EXIT_FAILURE;
  }

  if(argc < 6 || argc > 6){
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }

  int w, k;
  double min, max;

  if(sscanf(argv[1], "%d:%d", &w, &k) != 2){
    printf("Niepoprawny format rzędów i kolumn\n");
    return EXIT_FAILURE;
  }
  if(w <= 0 || k <=0){
    printf("Niepoprawne wartośći wierszy lub kolumn\n");
    return EXIT_FAILURE;
  }
  if(sscanf(argv[2], "%lf-%lf", &min, &max) != 2){
    printf("Niepoprawnie podany przedział wagi\n");
    return EXIT_FAILURE;
  }
  if(min >= max){
    printf("Niepoprawnie podany przedział wagi\n");
    return EXIT_FAILURE;
  } 
  srand(time(NULL));
	struct Graph *graf = creategraph(k, w, min, max);
  if(argc = 5){
    if(!strcmp(argv[3],"bfs")){
      freegraph(graf);
      return 1;
    }
    //bfs(graf, atoi(argv[4]));
  }
  freegraph(graf);
  return 0;
}