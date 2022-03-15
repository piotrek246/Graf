all: graf read

graf: 
	gcc src/main.c src/graf.c -o graf

read:
	gcc src/readMain.c src/graf.c -o read

clean:
	rm read graf

cleantxt:
	rm *.txt
