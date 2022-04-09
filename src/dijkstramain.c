#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mpq.h"
#include "dijkstra.h"
#include "utils.h"

int main(int argc, char** argv){
  if(argc < 2){
    helper();
    return EXIT_FAILURE;
  }
  if(argc < 4) {
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }
  int w, k, count = 0;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");
  if(in == NULL){ 
    printf("nie mogę czytać\n");
    return EXIT_FAILURE;
  }

  if(isNumber(argv[2]) == 1){
    printf("Niepoprawny format numeru węzła\n");
    fclose(in);
    return 1;
  }
  int start = atoi(argv[2]);

  for(int i = 0; i < argc-3; i++){
    if(isNumber(argv[3+i]) == 1){
      printf("Niepoprawny format numeru węzła\n");
      fclose(in);
      return 1;
    }
  }
  int *end = malloc(sizeof(int)*(argc-3));
  
  for(int i = 0; i < argc-3; i++){
      end[i] = atoi(argv[3+i]);
  }
  struct Graph* graf = readgraph(in);
  if(in == NULL){ 
    printf("nie mogę czytać\n");
    free(end);
    freegraph(graf);
    fclose(in);
    return 1;
  }
  for(int i = 0; i < argc-3; i++){
    if(end[i] >= graf->k*graf->w || start >=graf->k*graf->w){
      printf("Podano numer węzła który nie należy do grafu\n");
      free(end);
      freegraph(graf);
      fclose(in);
      return EXIT_FAILURE;
    }
    else if(end[i] < 0 || start < 0){
      printf("Podano ujemną wartość numeru węzła\n");
      free(end);
      freegraph(graf);
      fclose(in);
      return EXIT_FAILURE;
    }
  }

  distance_parents dp = dijkstra(graf, start);
    
  if(dp.exit == 1){
    free(end);
    freegraph(graf);
    fclose(in);
    return EXIT_FAILURE;
  }
  for(int i = 0; i < argc-3; i++){
    printf("%g\n",dp.d[end[i]]);
    printPath(dp.p, end[i]);
    printf("\n\n");
  }

  free(end);
  free(dp.p);
  free(dp.d);
  freegraph(graf);
  fclose(in);
  
  return 0;
}