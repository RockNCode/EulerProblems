problem36 : utils.o problem36.o
	gcc -o problem36 problem36.o utils.o
problem36.o  : problem36.c
	gcc -c problem36.c
utils.o : utils.c
	gcc -c utils.c

clean:
	rm  problem36.o utils.o problem36
