all: graf read bfs

graf: 
	gcc src/main.c src/graf.c -o graf

read:
	gcc src/readMain.c src/graf.c -o read

bfs:
	gcc src/bfsMain.c src/graf.c src/queue.c src/bfs.c -o bfs

clean:
	rm read graf bfs

cleantxt:
	rm *.txt
