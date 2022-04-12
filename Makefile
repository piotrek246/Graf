all: graf read bfs dijkstra generate utils

generate: src/generate.o src/graph.o src/mpq.o src/dijkstra.o src/queue.o src/bfs.o src/utils.o
	gcc src/generate.c src/graph.c src/mpq.c src/dijkstra.c src/queue.c src/bfs.c -g -o generate

graf: src/main.o src/graph.o src/utils.o
	gcc src/main.c src/graph.c -g -o graf

read:	src/readmain.o src/graph.o src/utils.o
	gcc src/readmain.c src/graph.c -g -o read

bfs: src/bfsmain.o src/graph.o src/queue.o src/bfs.o src/utils.o
	gcc src/bfsmain.c src/graph.c src/queue.c src/bfs.c -g -o bfs

dijkstra: src/dijkstramain.o src/graph.o src/mpq.o src/dijkstra.o src/utils.o
	gcc src/dijkstramain.c src/graph.c src/mpq.c src/dijkstra.c -g -o dijkstra


utils: src/utils.o
	gcc src/utils.c -c -o utils

test_dijkstra: dijkstra
	gcc src/dijkstra_test.c src/graph.c src/mpq.c src/dijkstra.c -g -o test_dijkstra
	./test_dijkstra
	rm test_dijkstra

test_bfs: bfs
	gcc src/bfs_test.c src/graph.c src/queue.c src/bfs.c -g -o test_bfs
	./test_bfs
	rm test_bfs

test_graph: src/graph.o src/main.o graf
	gcc src/graph_test.c src/graph.c -g -o test_graph
	./graf test_graf_01 10:30 0-2
	./test_graph test_graf_01 test_graf02
	rm test_graph test_graf* 

test_FIFO: src/queue.o
	gcc src/queue_test.c src/queue.c -g -o test_FIFO
	./test_FIFO
	rm test_FIFO

test_pq: src/mpq.o
	gcc src/mpq_test.c src/mpq.c -g -o test_pq
	./test_pq
	rm test_pq

tests: test_pq test_FIFO test_graph test_dijkstra test_bfs

test: graf read bfs dijkstra
	./graf testgraf 7:4 0-1
	./read testgraf
	./bfs testgraf 0
	./dijkstra testgraf 0 15
	rm testgraf

clean:
	rm graf read bfs dijkstra generate utils src/*.o

cleantxt:
	rm *.txt
