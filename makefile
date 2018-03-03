
#This is just a basic makefile for compilation.

CFILES = documentation/example.c fa_better.c
COUT = example
CC = gcc

all: 
	$(CC) $(CFILES) -o $(COUT)
