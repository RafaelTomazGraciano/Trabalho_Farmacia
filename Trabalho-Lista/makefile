all: trabalho

trabalho: trabalho1.o estoque.o
	gcc -Wall -o trabalho trabalho1.o estoque.o

trabalho1.o: trabalho1.c
	gcc -c -Wall trabalho1.c

estoque.o: estoque.c
	gcc -c -Wall estoque.c

clean: 
	rm trabalho1.o
	rm estoque.o
	rm trabalho