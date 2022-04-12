#ifndef BFS_H
#define BFS_H
#include "graph.h"

enum colors{WHITE, GRAY, BLACK};

int *bfs(Graph_t *graf, int s);

#endif