#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "mpq.h"

#define INF 10000000

typedef struct distance_parents{
  double *d;
  int *p;
  int exit;
} distance_parents;

//void relax(pq q, Node_t* v, hn u);
distance_parents dijkstra(Graph_t* graf, int s);
void printPath(int p[], int e);

#endif