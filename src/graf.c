#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graf.h"
#include <stdbool.h>

void freeGraph(struct Graph* graf){
  int n = graf->w*graf->k;
  struct Node* tmp;

  for(int i = 0; i < n; i++){

    while (graf->head[i] != NULL)
    {
      tmp = graf->head[i];
      graf->head[i] = graf->head[i]->next;
      free(tmp);
    }
  }
  free(graf->head);
  free(graf);
}

void addToList(struct Graph* graf, int i, int k, double random){

      //pierwszy węzeł np. 0 do 1
      struct Node* node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i+k;
      node->weight = random;
      node->next = graf->head[i];
      graf->head[i] = node;

      //i w drugą stronę czyli 1 do 0
      node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i;
      node->weight = random;
      node->next = graf->head[i+k];
      graf->head[i+k] = node;

}

struct Graph* initGraph(int k, int w){
  struct Graph* graf = (struct Graph*)malloc(sizeof(struct Graph));
  graf->k = k;
  graf->w = w;
  int n = graf->k*graf->w; //liczba węzłów
  
  graf->head = calloc(n, sizeof(struct Node));
  return graf;
}

struct Graph* createGraph(int k, int w, double min, double max){
  srand(time(NULL));
  int i;

  struct Graph* graf = initGraph(k, w);

  //tworzy połączenia poziome
  for(i = 0; i < k*w; i++){
      if((i+1)%k != 0){
        double random = randFrom(min, max);
        addToList(graf, i, 1, random);
    }
  }
  //tworzy połączenia pionowe
  for(int i = 0; i < k*(w-1); i++){
    double random = randFrom(min, max);
    addToList(graf, i, k, random);
  }

  return graf;
}

//print graf tu chyba nie ma nic ciekawego
void printGraph(FILE* out, struct Graph* graf){
  int i;
  int n = graf->k*graf->w; //liczba węzłów

  fprintf(out, "%d %d", graf->w, graf->k);
  fprintf(out,"\n");

  for(i = 0; i < n; i++){
    struct Node* node = graf->head[i];

    //do momenu aż węzeł nie jest NULL patrzymy wszystki połączenia dla 0,1,2...,n
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
