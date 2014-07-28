CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = gcd.o main.c
all: gcd
gcd.o: gcd.asm
	$(ASM) $(ASMFLAG) gcd.asm
gcd: gcd.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
