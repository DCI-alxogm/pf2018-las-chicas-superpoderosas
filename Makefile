holamake: void.c main.c
	gcc -o proyecto3.o main.c void.c -I ./lib

clean: 
	rm proyecto3.o
