all: graph read bfs dijkstra edit

graph: src/main.o src/graph.o 
	gcc src/main.c src/graph.c -o graf

read:	src/readmain.o src/graph.o
	gcc src/readmain.c src/graph.c -o read

bfs: src/bfsmain.o src/graph.o src/queue.o src/bfs.o
	gcc src/bfsmain.c src/graph.c src/queue.c src/bfs.c -o bfs

dijkstra: src/maindijkstra.o src/graph.o src/mpq.o src/dijkstra.o
	gcc src/maindijkstra.c src/graph.c src/mpq.c src/dijkstra.c -o dijkstra

edit: src/editmain.o src/graph.o
	gcc src/editmain.c src/graph.c -o edit

test: graph read bfs dijkstra
	./graf testgraf0 7:4 0-1
	./read testgraf0
	./bfs testgraf0 0
	./dijkstra testgraf0  0 15
	rm testgraf0

clean:
	rm read graf bfs src/*.o dijkstra

cleantxt:
	rm *.txt
