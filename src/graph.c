#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "utils.c"

void freegraph(Graph_t* graf){
  int n = graf->w*graf->k;
  struct Node* tmp;

  for(int i = 0; i < n; i++){
    while(graf->adjlist[i] != NULL){
      tmp = graf->adjlist[i];
      graf->adjlist[i] = graf->adjlist[i]->next;
      free(tmp);
    }
  }
  free(graf->adjlist);
  free(graf);
}

void addtolist(Graph_t* graf, int i, int k, double weight, double min, double max){

  struct Node* node = malloc(sizeof(*node));
  node->dest = i+k;
  node->weight = randfrom(min, max);
  node->next = graf->adjlist[i];
  graf->adjlist[i] = node;
  
  node = malloc(sizeof(*node));
  node->dest = i;
  node->weight = randfrom(min, max);
  node->next = graf->adjlist[i+k];
  graf->adjlist[i+k] = node;

}

struct Graph* initgraph(int k, int w){
  Graph_t* graf = malloc(sizeof(*graf));
  graf->k = k;
  graf->w = w;
  int n = graf->k*graf->w; //liczba węzłów
  
  graf->adjlist = calloc(k*w, sizeof(*graf->adjlist));
  return graf;
}

Graph_t* creategraph(int k, int w, double min, double max){
  int i;

  Graph_t* graf = initgraph(k, w);

  //tworzy połączenia poziome
  for(i = 0; i < k*w; i++){
      if((i+1)%k != 0){
        double weight = randfrom(min, max);
        addtolist(graf, i, 1, weight, min, max);
    }
  }
  //tworzy połączenia pionowe
  for(int i = 0; i < k*(w-1); i++){
    double weight = randfrom(min, max);
    addtolist(graf, i, k, weight, min, max);
  }

  return graf;
}

void printgraph(FILE* out, Graph_t* graf){
  int i;
  int n = graf->k*graf->w; //liczba węzłów

  fprintf(out, "%d %d", graf->w, graf->k);
  fprintf(out,"\n");

  for(i = 0; i < n; i++){
    Node_t* node = graf->adjlist[i];

    fprintf(out, "\t");
    while(node != NULL){
      fprintf(out, "%d :%lf\t\t", node->dest, node->weight);
      node = node->next;
    }
    fprintf(out,"\n");
  }
}

Graph_t* readgraph(FILE *in){
  int dest, w, k;
  double weight;
  char buf[MAX_BUF];
  int count = -1;
  int offset;

  if(fscanf(in, "%d %d", &w, &k) != 2)
    return NULL;
  Graph_t* graf = initgraph(k, w);
  

  while (fgets(buf, MAX_BUF, in) != NULL){
    char *data = buf;
    
    if((count >1 && sscanf(data, "%d :%lf", &dest, &weight) != 2)){
      return NULL;
    }
    while(sscanf(data, "%d :%lf%n", &dest, &weight, &offset) == 2)
    {
      Node_t* node = malloc(sizeof(*node));
      node->dest = dest;
      node->weight = weight;
      node->next = graf->adjlist[count];
      graf->adjlist[count] = node;
      data += offset;
    }
    count++;
  }
  return graf;
}