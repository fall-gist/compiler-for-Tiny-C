CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = sum-of-squares.o main.c
all: sos
sum-of-squares.o: sum-of-squares.asm
	$(ASM) $(ASMFLAG) sum-of-squares.asm
sos: sum-of-squares.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
