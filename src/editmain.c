#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char **argv){
  if(argc < 4 || argc > 4){
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
  int v = atoi(argv[2]);
  int e = atoi(argv[3]);
  struct Graph* graf = readgraph(in);
  Node_t *tmp = graf->adjlist[v];
  Node_t *head = graf->adjlist[v];
  Node_t *prev = NULL;

  while(tmp != NULL){
    if(tmp->dest != e){
      if(tmp->next == NULL && tmp->dest != e){
        printf("Nie ma takiej krawędzi");
        return EXIT_FAILURE;
      }
      else{
        prev = tmp;
        tmp = tmp->next;
      }
    }
    if(tmp->dest == e && tmp == head){
      prev = tmp;
      graf->adjlist[v] = prev->next;
      free(tmp);
      break;
    }
    if(tmp->dest == e && tmp != head){
      prev->next = tmp->next;
      free(tmp);
      break;
    }
  }
  FILE *out = fopen(argv[1], "w");
  printgraph(out, graf);

  return 0;
}