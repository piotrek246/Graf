#include <stdio.h>
#include <stdlib.h>

struct Node{
  int dest;
  double weight;
  struct Node* next;
};

struct Graph{
  int k, w; //kolumny i wiersze
  struct Node** head;
};

void addToList(struct Graph* graf, int i, int k, double random);
struct Graph* initGraph(int k, int w);
struct Graph* createGraph(int K, int W, double min, double max);
void printGraph(FILE* out, struct Graph* graf);
void freeGraph(struct Graph* graf);
double randFrom(double min, double max);
