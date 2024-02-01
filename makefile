all: lista.o ordenacao.o 
	gcc main.c lista.o ordenacao.o -o prog 

lista.o: lista.c
	gcc -c lista.c

ordenacao.o: ordenacao.c
	gcc -c ordenacao.c

clean:
	rm *.o prog