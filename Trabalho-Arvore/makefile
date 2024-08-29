all: trabalho

trabalho: trabalho2.o estoque.o
	gcc -Wall -o trabalho trabalho2.o estoque.o

trabalho1.o: trabalho1.c
	gcc -c -Wall trabalho2.c

estoque.o: estoque.c
	gcc -c -Wall estoque.c

clean: 
	rm trabalho2.o
	rm estoque.o
	rm trabalho