#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1024

typedef struct Node{
  int dest;
  double weight;
  struct Node* next;
} Node_t;

typedef struct Graph{
  int k, w; //kolumny i wiersze
  struct Node** adjlist;
} Graph_t;

void freeGraph(struct Graph* graf);
void addToList(struct Graph* graf, int i, int k, double random);
Graph_t* initGraph(int k, int w);
Graph_t* createGraph(int K, int W, double min, double max);
void printGraph(FILE* out, struct Graph* graf);
double randFrom(double min, double max);
Graph_t* readGraph(FILE *in);
