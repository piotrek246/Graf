#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isNumber(char number[]){
  int i = 0;
  if(number[0] == '-')
    i = 1;
  for(; number[i] != 0; i++)
    if(!isdigit(number[i]))
      return 1;
  return 0;
}

double randfrom(double min, double max){
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void helper(){
  printf("ARGUMENTY WYWOŁANIA PROGRAMU:\n\nGeneracja grafu z zapisem do pliku:\n./graf <nazwa pliku> <kolumny:wiersze> [waga]<od-do>\nnp:./graf graf1 3:3 0-1");
  printf("\n\nOdczytywanie grafu z pliku:\n./read <nazwa pliku>\nnp:./read graf1");
  printf("\n\nAlgorytm BFS:\n./bfs <nazwa pliku> <węzeł startowy>\nnp:./bfs graf1 0");
  printf("\n\nAlgorytm Dijkstry:\n./dijkstra <nazwa pliku> <węzeł startowy> <węzły końcowe odzielone spacją>\nnp:./dijkstra graf1 0 3 8\n");
}