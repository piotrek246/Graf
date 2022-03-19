#include <stdio.h>
#include <stdlib.h>
#include "graf.h"
#include "bfs.h"

#define MAX_BUF 1024

int main(int argc, char** argv){
  int w, k;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");
  int start = atoi(argv[2]);

  FILE *out = stdout;

  if(in == NULL){ 
    printf("nie mogę czytać\n");
    fclose(in);
    return 1;
  }
  else{
    struct Graph* graf = readGraph(in);

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