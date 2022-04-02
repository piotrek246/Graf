#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/*int editgraph(Graph_t* graf, int v, int e, char *name){
  Node_t *tmp = graf->adjlist[v];
  Node_t *head = graf->adjlist[v];
  Node_t *prev = NULL;

  while(tmp != NULL){
    if(tmp->dest != e){
      if(tmp->next == NULL && tmp->dest != e){
        printf("Nie ma takiej krawędzi");
        return -1;
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
  FILE *out = fopen(name, "w");
  printgraph(out, graf);
  return 0;
}*/


int main(int argc, char **argv){
  if(argc < 4 || argc > 4){
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }
  //int w, k;
  char *nazwa_pliku = argv[1];
  FILE *in = fopen(argv[1], "r");

  if(in == NULL){ 
    printf("nie mogę czytać\n");
    fclose(in);
    return EXIT_FAILURE;
  }
  struct Graph* graf = readgraph(in);

  int v = atoi(argv[2]);
  int e = atoi(argv[3]);
  if(v >= graf->k*graf->w || e >=graf->k*graf->w){
    printf("Podano numer węzła który nie należy do grafu\n");
    freegraph(graf);
    fclose(in);
    return EXIT_FAILURE;
  }

  if(editgraph(graf, v, e)){
    printf("Coś poszło nie tak\n");
    return EXIT_FAILURE;
  }
  FILE *out = fopen(argv[1], "w");
  printgraph(out, graf);
  
  return 0;
}