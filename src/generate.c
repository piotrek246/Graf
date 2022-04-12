#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "graph.h"
#include "utils.h"
#include <string.h>
#include "bfs.h"
#include "dijkstra.h"

int main(int argc, char**argv){
  if(argc < 2){
    helper();
    return EXIT_FAILURE;
  }

  if(argc < 3){
    printf("Niepoprawna ilość argumentów\n");
    return EXIT_FAILURE;
  }

  int w, k, *result, start;
  double min, max;

  if(sscanf(argv[1], "%d:%d", &w, &k) != 2){
    printf("Niepoprawny format rzędów i kolumn\n");
    return EXIT_FAILURE;
  }
  if(w <= 0 || k <=0){
    printf("Niepoprawne wartośći wierszy lub kolumn\n");
    return EXIT_FAILURE;
  }
  if(sscanf(argv[2], "%lf-%lf", &min, &max) != 2){
    printf("Niepoprawnie podany przedział wagi\n");
    return EXIT_FAILURE;
  }
  if(min >= max){
    printf("Niepoprawnie podany przedział wagi\n");
    return EXIT_FAILURE;
  } 
  if(argc == 3){
    srand(time(NULL));
	  struct Graph *graf = creategraph(k, w, min, max);
    printf("Poprawnie stworzono graf\n");
    freegraph(graf);
    return EXIT_SUCCESS;
  }

  int num;
  if(strcmp(argv[3], "bfs") == 0){
    num = 1;
  }
  else if(strcmp(argv[3], "dijkstra") == 0){
    num = 2;
  }
  else{
    num = 3;
  }

  switch (num){
    //----------bfs----------
    case 1:
      if(argc == 4 || argc > 5){
        printf("Niepoprawna ilość argumentów dla bfs\n");
        return EXIT_FAILURE;
      }
      if(argc <= 5){
        if(isNumber(argv[4]) == 0)
          start = atoi(argv[4]);
        else{
          printf("Niepoprawnie podany węzeł początkowy\n");
          return EXIT_FAILURE;
        }
      	struct Graph *graf = creategraph(k, w, min, max);

        if(start >= graf->k*graf->w){
          printf("Podano numer węzła który nie należy do grafu\n");
          freegraph(graf);
          return EXIT_FAILURE;
        }
        result = bfs(graf, start);
        int n = graf->w*graf->k;
        for(int i = 0; i < n; i++){
          if(result[i] != BLACK){
            printf("\nGraf jest spójny\n");
            freegraph(graf);
            free(result);
            return EXIT_FAILURE; 
          }
        }
        printf("\nGraf jest spójny\n");
        freegraph(graf);
        free(result);
        return EXIT_SUCCESS;
        }
        break;
      
    case 2:
    //----------dijkstra----------
    if(argc >= 4 && argc <= 5){
      printf("Niepoprawna ilość argumentów dla dijkstry\n");
      return EXIT_FAILURE;
    }
    if(isNumber(argv[4]) == 0)
      start = atoi(argv[4]);
    else{
      printf("Niepoprawnie podany węzeł początkowy\n");
      return EXIT_FAILURE;
    }
    
    for(int i = 0; i < argc-5; i++){
      if(isNumber(argv[5+i]) == 1){
        printf("Niepoprawnie podany numeru węzła\n");
        return EXIT_FAILURE;
      }
    }
    int *end = malloc(sizeof(int)*(argc-5));
    
    for(int i = 0; i < argc-5; i++){
        end[i] = atoi(argv[5+i]);
    }

    struct Graph *graf = creategraph(k, w, min, max);

    for(int i = 0; i < argc-5; i++){
      if(end[i] >= graf->k*graf->w || start >=graf->k*graf->w){
        printf("Podano numer węzła który nie należy do grafu\n");
        free(end);
        freegraph(graf);
        return EXIT_FAILURE;
      }
      else if(end[i] < 0 || start < 0){
        printf("Podano ujemną wartość numeru węzła\n");
        free(end);
        freegraph(graf);
        return EXIT_FAILURE;
      }
    }

    distance_parents dp = dijkstra(graf, start);
        
    if(dp.exit == 1){
      free(end);
      freegraph(graf);
      return EXIT_FAILURE;
    }
    for(int i = 0; i < argc-5; i++){
      printf("%g\n",dp.d[end[i]]);
      printPath(dp.p, end[i]);
      printf("\n\n");
    }

    free(end);
    free(dp.p);
    free(dp.d);
    freegraph(graf);
    break;

  default:
    printf("Zła nazwa funkcji\n");
    return EXIT_FAILURE;
  }
  return 0;
}