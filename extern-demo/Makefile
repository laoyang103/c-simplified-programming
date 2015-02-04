CC = gcc
CFLAGS = -I.
OBJ = main.o moda.o 

all: un_use_include_demo use_include_demo

un_use_include_demo : $(OBJ)
	$(CC) -DUN_USE_INCLUDE_DEMO -c -o moda.o moda.c
	$(CC) -DUN_USE_INCLUDE_DEMO -c -o main.o main.c
	$(CC) -DUN_USE_INCLUDE_DEMO -o $@ $^ $(CFLAGS)

use_include_demo : $(OBJ)
	$(CC) -DUSE_INCLUDE_DEMO -c -o moda.o moda.c
	$(CC) -DUSE_INCLUDE_DEMO -c -o main.o main.c
	$(CC) -DUSE_INCLUDE_DEMO -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) use_include_demo un_use_include_demo 


