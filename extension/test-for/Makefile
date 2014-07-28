CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = for.o main.c
all: for
for.o: for.asm
	$(ASM) $(ASMFLAG) for.asm
for: for.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
