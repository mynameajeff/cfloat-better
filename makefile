
#This is just a basic makefile for compilation. both Allegro 5.x.x and LibSodium will be required to properly compile.

CFILES = example.c fa_better.c
COUT = example
CC = gcc

all: 
	$(CC) $(CFILES) -o $(COUT)
