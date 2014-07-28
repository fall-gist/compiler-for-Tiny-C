CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = inc_dec.o main.c
all: inc_dec
inc_dec.o: inc_dec.asm
	$(ASM) $(ASMFLAG) inc_dec.asm
inc_dec: inc_dec.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
