#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "utils.h"

int initgraph_test();
int addtolist_test();
int creatgraph_test();
int readgraph_test(FILE *in);
int printgraph_test(char *argv);


int main(int argc, char** argv){
  Graph_t *graf = creategraph(30, 20 ,0 , 19);
  FILE *in = fopen(argv[1], "r");
  printf("\nGraph Tests:");
  //----initgraph_test----
  if(initgraph_test() != 0)
    printf("\ninitgraph_test: FAILED\n");
  else
    printf("\ninitgraph_test: OK\n");

  //----addtolist_test----
  if(addtolist_test() != 0)
    printf("addtolist_test: FAILED\n");
  else 
    printf("addtolist_test: OK\n");

  //----creatgraph_test----
  if(creatgraph_test() != 0)
    printf("creatgraph_test: FAILED\n");
  else
    printf("creatgraph_test: OK\n");

  //----readgraph_test----
  if(readgraph_test(in) != 0)
    printf("readgraph_test: FAILED\n");
  else
    printf("readgraph_test: OK\n");

  //----printgraph_test----
  if(printgraph_test(argv[2]) != 0)
    printf("printgraph_test: FAILED\n");
  else
    printf("printgraph_test: OK\n");

  return 0;
}

int initgraph_test(){
  int k = 30;
  int w = 20;
  int i = 0;
  
  Graph_t *graf = initgraph(k, w);

  if(graf->k*graf->w != k*w)
    return 1;
  for(; i < k*w ; i++){
    if(graf->adjlist[i] != NULL)
      return 1;
  }
  freegraph(graf);
  return 0;
}

int addtolist_test(){
  double min = 0.5;
  double max = 10.12;
  double k = 0;
  Graph_t *graf = initgraph(30, 20);

  addtolist(graf, 0, 1, k, min, max);

  if((graf->adjlist[0]->weight > max && graf->adjlist[0]->weight < min) && (graf->adjlist[1]->weight > max && graf->adjlist[1]->weight < min)){
    freegraph(graf);
    return 1;
  }
  freegraph(graf);
  return 0;
}

int creatgraph_test(){
  int i = 0;
  Graph_t *graf = creategraph(30, 20, 0, 19);
  Node_t *tmp = graf->adjlist[0];

  for(; i < 30*20; i++){
    if(graf->adjlist[i] == NULL){
      freegraph(graf);
      free(tmp);
      return 1;
    }
    while(tmp != NULL){
      if(tmp->weight > 19 && tmp->weight < 0){
        freegraph(graf);
        free(tmp);
        return 1;
      }
      tmp = tmp->next;
    }
  }
  freegraph(graf);
  free(tmp);
  return 0;
}

int readgraph_test(FILE *in){
  int i = 0;
  Graph_t *graf = readgraph(in);
  Node_t *tmp = graf->adjlist[0];

  //k:10, w:30, min:0 i max:2 to wartości które znajdują się w pliku
  //oczekuje, że przeczytany graf będzie taki jaki znajduje się w zadanym pliku
  for(; i < 10*30; i++){
    if(graf->adjlist[i] == NULL)
      return 1;
    while(tmp != NULL){
      if(tmp->weight > 2 && tmp->weight < 0)
        return 1;
      tmp = tmp->next;
    }
  }
  return 0;
}

int printgraph_test(char *name){
  int i = 0;
  Graph_t *graf = creategraph(30, 20 ,0 , 2);
  FILE *out = fopen(name, "w");
  printgraph(out, graf);
  fclose(out);
  Node_t *tmp = graf->adjlist[0];

  //oczekuje, że graf który wyprintuje będzie w formacie który przeczyta funkcja readgraph()
  FILE *in = fopen(name, "r");
  Graph_t *graf1 = readgraph(in);
  fclose(in);

  for(; i < 30*20; i++){
    if(graf1->adjlist[i] == NULL)
      return 1;
    tmp = graf1->adjlist[i];
    while(tmp != NULL){
      if(tmp->weight > 2 && tmp->weight < 0)
        return 1;
      tmp = tmp->next;
    }
  }
  return 0;
}
