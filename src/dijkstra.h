#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "mpq.h"

void relax(pq q, Node_t* v, hn u);
void dijkstra(Graph_t* graf, int s, int e);
#endif