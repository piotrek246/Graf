#ifndef DIJKSTRA_H
#define DIJKSTRA_H

void relax(Graph_t* graf, Node_t* v, int u, int o[], int p[]);
void dijkstra(Graph_t* graf, int s);
#endif