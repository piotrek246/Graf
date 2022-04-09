all: graf read bfs dijkstra generate edit

generate: src/generate.o src/graph.o src/mpq.o src/dijkstra.o src/queue.o src/bfs.o
	gcc src/generate.c src/graph.c src/mpq.c src/dijkstra.c src/queue.c src/bfs.c -g -o generate

graf: src/main.o src/graph.o 
	gcc src/main.c src/graph.c -g -o graf

read:	src/readmain.o src/graph.o
	gcc src/readmain.c src/graph.c -g -o read

bfs: src/bfsmain.o src/graph.o src/queue.o src/bfs.o
	gcc src/bfsmain.c src/graph.c src/queue.c src/bfs.c -g -o bfs

dijkstra: src/dijkstramain.o src/graph.o src/mpq.o src/dijkstra.o
	gcc src/dijkstramain.c src/graph.c src/mpq.c src/dijkstra.c -g -o dijkstra

edit: src/editmain.o src/graph.o 
	gcc src/editmain.c src/graph.c -g -o edit

test_dijkstra: src/test_dijkstra.o src/dijkstra.o src/graph.o src/mpq.o 
	gcc src/test_dijkstra.c src/graph.c src/mpq.c src/dijkstra.c -g -o test_dijkstra
	./test_dijkstra
	rm test_dijkstra

test_graph: src/graph.o src/main.o
	gcc src/graph_test.c src/graph.c -g -o test_graph
	./graf test_graf_01 10:30 0-2
	./test_graph test_graf_01 test_graf02
	rm test_graph test_graf* 

test: graf read bfs dijkstra
	./graf testgraf 7:4 0-1
	./read testgraf
	./bfs testgraf 0
	./dijkstra testgraf 0 15
	rm testgraf

clean:
	rm read graf bfs src/*.o dijkstra edit

cleantxt:
	rm *.txt
