CC = gcc
OBJ = fonction.o
OPT = -g -W -Wall

all: bj test

bj :  $(OBJ)
	$(CC) $(OBJ) bj.c -o bj


test : $(OBJ)
	$(CC) $(OBJ) test.c -o test

bj.o : bj.c fonction.h 
	$(CC) -c bj.c $(OPT)
	
test.o : test.c fonction.h
	$(CC) -c test.c $(OPT)
	

fonction.o : fonction.c fonction.h
	$(CC) -c fonction.c $(OPT)
	
clean:
	rm -f *.o bj test

