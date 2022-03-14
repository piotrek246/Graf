#include <stdio.h>
#include <stdlib.h>

//Węzeł
struct Node{
  int dest;
  double weight;
  struct Node* next;
};
/*To jest stworzenie listy węzłów do której późneij dopisujemy relacje z innymi węzłami
do head[0] przypisane będą relacje z innymi węzłami(dla 3x3 to będzie 1 i 3)*/ 
struct Graph{
  int K,W;
  struct Node** head;
};

void freeGraph(struct Graph* graf);
double randFrom(double min, double max);
struct Graph* createGraph(int K, int W, double min, double max);
void printGraph(FILE* out, struct Graph* graf, int W, int K);
