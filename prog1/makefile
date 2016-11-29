p1: main.o functions.o insert.o
	gcc -g  main.o functions.o insert.o -o p1

main.o: constants.h P1Headers.h main.c
	gcc -c main.c 

functions.o: P1Headers.h functions.c
	gcc -c functions.c

insert.o: P1Headers.h insert.c
	gcc -c insert.c
clean:
	rm -f *o core p1
