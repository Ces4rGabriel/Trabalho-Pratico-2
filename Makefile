all: main.o lista.o
	@gcc main.o lista.o -o exe
lista.o: lista.c
	@gcc lista.c -c -lm -Wall
pratica.o: pratica.c
	@gcc main.c -c -lm -Wall
run:
	@./exe
