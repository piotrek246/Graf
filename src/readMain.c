#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

#define MAX_BUF 1024

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
    int dest;
    double weight;
    char buf[MAX_BUF];
    int count = -1;
    int offset;

    fscanf(in, "%d %d", &w, &k);
    struct Graph* graf = initGraph(k, w);

    while(fgets(buf, MAX_BUF ,in) != NULL){
      char *data = buf;
      while(sscanf(data, "%d :%lf%n", &dest, &weight, &offset) == 2 ){
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->dest = dest;
        node->weight = weight;
        node->next = graf->head[count];
        graf->head[count] = node;
        data += offset;
      }
      count++;
    }
  
    printGraph(out, graf);
    freeGraph(graf);
    fclose(in);
    fclose(out);
  }
  return 0;
}