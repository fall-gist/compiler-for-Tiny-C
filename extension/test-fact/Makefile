CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = fact.o main.c
all: fact
fact.o: fact.asm
	$(ASM) $(ASMFLAG) fact.asm
fact: fact.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
