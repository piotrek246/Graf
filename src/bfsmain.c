#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "bfs.h"

#define MAX_BUF 1024

int main(int argc, char** argv){
  if(argc < 3) {
    printf("Nie podano węzła rozpoczynającego\n");
    return 1;
  }
  int w, k;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");
  struct Graph* graf = readGraph(in);
  int start = atoi(argv[2]);
  if(start >= graf->k*graf->w){
    printf("Podano numer węzła który nie należy do grafu\n");
    return 1;
  }

  FILE *out = stdout;

  if(in == NULL){ 
    printf("nie mogę czytać\n");
    fclose(in);
    return 1;
  }
  else{

    int result = bfs(graf, start);
    if(result == 0)
      printf("\nGraf jest spójny\n");
    else
      printf("\nGraf nie jest spójny\n");

    freeGraph(graf);
    fclose(in);
    fclose(out);
  }
  return 0;
}