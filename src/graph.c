#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

void freeGraph(Graph_t* graf){
  int n = graf->w*graf->k;
  struct Node* tmp;

  for(int i = 0; i < n; i++){

    while (graf->adjlist[i] != NULL)
    {
      tmp = graf->adjlist[i];
      graf->adjlist[i] = graf->adjlist[i]->next;
      free(tmp);
    }
  }
  free(graf->adjlist);
  free(graf);
}

void addToList(Graph_t* graf, int i, int k, double weight){

      struct Node* node = malloc(sizeof(*node));
      node->dest = i+k;
      node->weight = weight;
      node->next = graf->adjlist[i];
      graf->adjlist[i] = node;

      node = malloc(sizeof(*node));
      node->dest = i;
      node->weight = weight;
      node->next = graf->adjlist[i+k];
      graf->adjlist[i+k] = node;

}

struct Graph* initGraph(int k, int w){
  Graph_t* graf = malloc(sizeof(*graf));
  graf->k = k;
  graf->w = w;
  int n = graf->k*graf->w; //liczba węzłów
  
  graf->adjlist = calloc(n, sizeof(Node_t));
  return graf;
}

Graph_t* createGraph(int k, int w, double min, double max){
  srand(time(NULL));
  int i;

  Graph_t* graf = initGraph(k, w);

  //tworzy połączenia poziome
  for(i = 0; i < k*w; i++){
      if((i+1)%k != 0){
        double weight = randFrom(min, max);
        addToList(graf, i, 1, weight);
    }
  }
  //tworzy połączenia pionowe
  for(int i = 0; i < k*(w-1); i++){
    double weight = randFrom(min, max);
    addToList(graf, i, k, weight);
  }

  return graf;
}

void printGraph(FILE* out, Graph_t* graf){
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

//funkcja pomocnicza do generowania losowej wartosci wagi od min do max
double randFrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

Graph_t* readGraph(FILE *in){
  int dest, w, k;
  double weight;
  char buf[MAX_BUF];
  int count = -1;
  int offset;

  fscanf(in, "%d %d", &w, &k);
  Graph_t* graf = initGraph(k, w);

  while (fgets(buf, MAX_BUF, in) != NULL){
    char *data = buf;
    while (sscanf(data, "%d :%lf%n", &dest, &weight, &offset) == 2)
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