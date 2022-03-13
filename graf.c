#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Troche kodu jest, na razie wszsystko w jedynm pliku
trzeba będzie to porozdzielać tak żeby w main zostało tylko
zarządzanie przypadkami(tj. generowanie, odczyt, bfs, dijkstra),
a w innych plikach będziemy mieli wszystko dotyczące grafu, 
czy tworzenia krawędzi(więcej dalej)

Zakłądam że graf powinien być nieskierowany, tak żeby waga z 0 do 1 była taka sama jak waga z 1 do 0,
tak przynajmniej wynika z opisu projektu(ale nie z pliku ktory dostalismy)

Jeżeli jednak waga 0-1 ma być inna niż 1-0 to niestety ale kod trzeba będzie radykalnie zmienić*/

//Węzeł
struct Node{
  int dest;
  double weight;
  struct Node* next;
};
/*To jest stworzenie listy węzłów do której późneij dopisujemy relacje z innymi węzłami
do head[0] przypisane będą relacje z innymi węzłami(dla 3x3 to będzie 1 i 3)*/ 
struct Graph{
  struct Node** head;
};
//Krawędź, charakteryzuje się source, destination i weight
struct Edge{
  int src, dest;
  double weight;
};
//funkcja tworząca graf, przyjmuje tablice krawędzi, ilość krawędzi i ilość węzłów
struct Graph* stworzGraf(struct Edge edges[], int n, int N){
  int i;
  //alokujemy pamięć
  struct Graph* graf = (struct Graph*)malloc(sizeof(struct Graph));
  graf->head = malloc(sizeof(struct Node)*N);
  //head dla wszywstkich węzłów ustawiamy najpierw na NULL
	for (i = 0; i < N; i++) {
		graf->head[i] = NULL;
	}
  
  for(i = 0; i < n; i++){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    //destination oraz weight węzła przyjmujemy z wygenerowanej krawędzi
    node->dest = edges[i].dest;
    node->weight = edges[i].weight;
    node->next = graf->head[edges[i].src];

    //zależnie od tego, z którego węzła wychodzi krawędź ustalamy na którym miejscu w tablicy head[] ma się ona znajdować
    //dla krawędzi typu {0,1,weight}, węzeł będzie przyporządkowany dla head[0]
    graf->head[edges[i].src] = node;

    //tworzymy drugi węzeł który jest połączony w drugą stronę niż poprzedni
    //tutaj dla {0,1,weight}, węzeł będzie przyporządkowany dla head[1](z tą samą wagą co węzeł powyżej)
    node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = edges[i].src;
    node->weight = edges[i].weight;

    node->next = graf->head[edges[i].dest];
    graf->head[edges[i].dest] = node;
  }
  return graf;
}

//print graf tu chyba nie ma nic ciekawego
void printGraf(struct Graph* graf, int N, FILE* out, int W, int K){
  int i;
  fprintf(out, "%d %d", W, K);
  fprintf(out,"\n");

  for(i = 0; i < N; i++){
    struct Node* node = graf->head[i];
    //do momenu aż węzeł nie jest NULL patrzymy wszystki połączenia dla 0,1,2...,n
    while(node != NULL){
      fprintf(out, "\t%d: %g  ", node->dest, node->weight);
      node = node->next;
    }
    fprintf(out,"\n");
  }
}
//funkcja pomocnicza do generowania randomowej wartosci(wagi) od min do max
double randFrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
/*main na razie jest najmniej zrobiony, powiino być tu dużo rzeczy związanych z reagowaniem
argumenty wywołania (tj. sprawdzanie czy jest odpowiednia ilość, czy odpowiedni format, jaki tryb, etc)*/


int main(int argc, char** argv){

  char *nazwa_pliku = argv[1];
  int W, K;
  double min, max;

  sscanf(argv[2], "%d:%d", &W, &K);
  sscanf(argv[3], "%lf-%lf", &min, &max);

  FILE *out = fopen(argv[1], "r");
  if(out != NULL){ //sprawdza czy podany plik istnieje
    printf("Plik o podanej nazwie już istnieje, nie mogę nadpisać\n");
    return 1;
  }
  else{
    out = fopen(argv[1], "w");
  }
  
  int N = K*W; //liczba węzłów
  int n = ((K-1)*W + (W-1)*K); //liczba krawędzi
  int count = 0;

  srand(time(NULL));

  struct Edge *edges = malloc(sizeof(*edges)*((K-1)*W + (W-1)*K));

  //teorzy krawędzie poziome
  for(int j = 0; j < K*W; j++){
    if((j+1)%K == 0)
      ;//nie twórz
    else {
      double random = randFrom(min, max);
      struct Edge edge;
      edges[count].src = j;
      edges[count].dest = j+1;
      edges[count].weight = random;
      count++;
    }
  }
  //tworzy krawędzie pionowe
  for(int i = 0; i< K*(W-1); i++){
    double random = randFrom(min, max);;
    struct Edge edge;
    edges[i+((K-1)*W)].src = i;
    edges[i+((K-1)*W)].dest = i+K;
    edges[i+((K-1)*W)].weight = random;
  }

	struct Graph *graf = stworzGraf(edges, n, N);
	printGraf(graf, N, out, W, K);

  return 0;
}