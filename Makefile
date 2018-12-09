holamake: ayuda.c main.c
	gcc main.c ayuda.c -o proyecto3.o -lm -I ./libs

clean: 
	rm proyecto3.o
