all: graph read bfs dijkstra

graph: src/main.o src/graph.o 
	gcc src/main.c src/graph.c -o graph

read:	src/readmain.o src/graph.o
	gcc src/readmain.c src/graph.c -o read

bfs: src/bfsmain.o src/graph.o src/queue.o src/bfs.o
	gcc src/bfsmain.c src/graph.c src/queue.c src/bfs.c -o bfs

dijkstra: src/maindijkstra.o src/graph.o src/pq.o src/dijkstra.o
	gcc src/maindijkstra.c src/graph.c src/pq.c src/dijkstra.c -o dijkstra
clean:
	rm read graph bfs src/*.o

cleantxt:
	rm *.txt
