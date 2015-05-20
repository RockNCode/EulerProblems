all : problem36 problem28

problem36 : utils.o problem36.o
	gcc -o problem36 problem36.o utils.o
problem28 : utils.o problem28.o
	gcc -o problem28 problem28.o utils.o
problem36.o  : problem36.c
	gcc -c problem36.c
problem28.o  : problem28.c
	gcc -c problem28.c
utils.o : utils.c
	gcc -c utils.c

clean:
	rm  problem36.o utils.o problem36 problem18 problem18.o
