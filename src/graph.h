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

double randfrom(double min, double max);
void freegraph(struct Graph* graf);
void addtolist(struct Graph* graf, int i, int k, double random, double min, double max);
void printgraph(FILE* out, struct Graph* graf);
Graph_t* initgraph(int k, int w);
Graph_t* creategraph(int K, int W, double min, double max);
Graph_t* readgraph(FILE *in);

