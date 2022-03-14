#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graf.h"


/*W znacznej mierze usprawnilem kod.

Z najważniejszych to pozbyłem się tworu Edge, który okazał się
zwyczajnie zbedny.

Podzielony na kilka plików a mianowicie graf.c i main.c,
w przyszłości potrzebny test.c oraz osobne algorytmy bfs i dijkstry.*/

int main(int argc, char** argv){

  char *nazwa_pliku = argv[1];
  int W, K;
  double min, max;

  sscanf(argv[2], "%d:%d", &W, &K);
  sscanf(argv[3], "%lf-%lf", &min, &max);

  //sprawdza czy podany plik istnieje
  FILE *out = fopen(argv[1], "r");
  if(out != NULL){ 
    printf("Plik o podanej nazwie już istnieje, nie mogę nadpisać\n");
    return 1;
  }
  else{
    out = fopen(argv[1], "w");
  }
  
	struct Graph *graf = createGraph(K, W, min, max);
	printGraph(out, graf, W, K);
  
  fclose(out);
  return 0;
}