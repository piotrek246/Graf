#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graf.h"

void freeGraph(struct Graph* graf){
  int N = graf->K*graf->W;
  struct Node* tmp;

  for(int i = 0; i < N; i++){

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

void addToList(struct Graph* graf, int i, int K, double random){

      //pierwszy węzeł np. 0 do 1
      struct Node* node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i+K;
      node->weight = random;
      node->next = graf->head[i];
      graf->head[i] = node;

      //i w drugą stronę czyli 1 do 0
      node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i;
      node->weight = random;
      node->next = graf->head[i+K];
      graf->head[i+K] = node;

}

struct Graph* createGraph(int K, int W, double min, double max){
  srand(time(NULL));
  int i;

  struct Graph* graf = (struct Graph*)malloc(sizeof(struct Graph));
  graf->K = K;
  graf->W = W;
  int N = graf->K*graf->W; //liczba węzłów
  
  //alokujemy pamięć dla tablicy N node'ów nazwanej head
  graf->head = malloc(N*sizeof(struct Node));

  //head dla wszywstkich węzłów ustawiamy na NULL
	for (i = 0; i < N; i++) {
		graf->head[i] = NULL;
	}

  //tworzy krawędzie poziome
  for(i = 0; i < K*W; i++){
    if((i+1)%K != 0){
      double random = randFrom(min, max);
      addToList(graf, i, 1, random);
    }
  }

  //tworzy krawędzie pionowe
  for(int i = 0; i < K*(W-1); i++){
    double random = randFrom(min, max);
    addToList(graf, i, K, random);
  }

  return graf;
}

//print graf tu chyba nie ma nic ciekawego
void printGraph(FILE* out, struct Graph* graf){
  int i;
  int N = graf->K*graf->W;

  fprintf(out, "%d %d", graf->W, graf->K);
  fprintf(out,"\n");

  for(i = 0; i < N; i++){
    struct Node* node = graf->head[i];

    //do momenu aż węzeł nie jest NULL patrzymy wszystki połączenia dla 0,1,2...,n
    while(node != NULL){
      fprintf(out, "\t%d: %g  ", node->dest, node->weight);
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
