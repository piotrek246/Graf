#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graf.h"

struct Graph* createGraph(int K, int W, double min, double max, int n, int N){
  srand(time(NULL));
  int i;

  struct Graph* graf = (struct Graph*)malloc(sizeof(struct Graph));
  
  //alokujemy pamięć dla tablicy N node'ów nazwanej head
  graf->head = malloc(sizeof(struct Node)*N);

  //head dla wszywstkich węzłów ustawiamy na NULL
	for (i = 0; i < N; i++) {
		graf->head[i] = NULL;
	}

  //tworzy krawędzie poziome
  for(i = 0; i < K*W; i++){
    if((i+1)%K == 0)
      ;  //nie twórz
    else {
      double random = randFrom(min, max);

      //pierwszy węzeł np. 0 do 1
      struct Node* node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i+1;
      node->weight = random;
      node->next = graf->head[i];
      graf->head[i] = node;

      //i w drugą stronę czyli 1 do 0
      node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i;
      node->weight = random;
      node->next = graf->head[i+1];
      graf->head[i+1] = node;
    }
  }

  //tworzy krawędzie pionowe
  for(int i = 0; i< K*(W-1); i++){
    double random = randFrom(min, max);
    //pierwszy węzeł np. 0 do 3
      struct Node* node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i+K;
      node->weight = random;
      node->next = graf->head[i];
      graf->head[i] = node;

      //i w drugą stronę czyli np. 3 do 0
      node = (struct Node*)malloc(sizeof(struct Node));
      node->dest = i;
      node->weight = random;
      node->next = graf->head[i+K];
      graf->head[i+K] = node;
  }
  return graf;
}

//print graf tu chyba nie ma nic ciekawego
void printGraph(FILE* out, struct Graph* graf, int N, int W, int K){
  int i;
  fprintf(out, "%d %d", W, K);
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
