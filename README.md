# Graf
Program w języku C, umożliwiający tworzenie, zapisywanie i odczytywanie grafu nieskierowanego o strukturze siatki, zadanej liczbie wierszy i kolumn oraz nadanych wagach krawędzi (generowanych losowo w podanym zakresie). Za pomocą algorytmu BFS program potrafi sprawdzić, czy graf jest spójny oraz poprzez algorytm Dijkstry potrafi znaleźć najkrótsze ścieżki pomiędzy wybranymi dwoma węzłami. 
# Funkcje, jakie program udostępnia
- tworzenie grafu 
- zapisywanie do pliku
- odczytywanie grafu z pliku
- sprawdzenie, czy graf jest spójny (algorytm BFS) 
  - Wykorzystując algorytm BFS (Breadth-First Search) program sprawdza, czy graf jest spójny, czyli, czy istnieją połączenie pomiędzy dwoma dowolnymi węzłami. 
- znalezienie najkrótszych ścieżek pomiędzy wybranymi węzłami (algorytm Dijkstry) 
  - Wykorzystując algorytm Dijkstry, program znajduje najkrótszą ścieżkę pomiędzy dwoma wybranymi węzłami. 
#  Argumenty wywołania programu
- Argumenty wywołania programu przy tworzeniu grafu: 
  - ./graf nazwa_pliku kolumny:wiersze (waga) od-do 
- Argumenty wywołania programu przy odczytywaniu grafu: 
  - Algorytm BFS:	 
    <br />./graf nazwa_pliku BFS 
  - Algorytm Dijkstry: 
    <br />./graf nazwa pliku Dijkstra węzeł-węzeł ...
# Przykłady wywołania
- Generacja grafu <br />./graf graf01.txt 20:25 0.00-19.99 <br />Program stworzy plik graf01.txt z wygenerowanym grafem(20 kolumn, 25 wierszy, generowane losowo wagi krawędzi z przedziału 0.00-19.99).
- Odczytywanie grafu
  - Algorytm BFS: <br />./graf graf01.txt BFS <br />Program odczyta plik graf01.txt i określi jego spójność.
  - Algorytm Dijkstry: <br />./graf graf01.txt Dijkstra 0-19 0-12 <br />Program odczyta plik graf01.txt i wyznaczy najkrótsze ścieżki od węzła 0 do 19 oraz od 	węzła 0 do 12. 
