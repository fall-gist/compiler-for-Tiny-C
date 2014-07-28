CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = foo.o main.c
all: foo
foo.o: foo.asm
	$(ASM) $(ASMFLAG) foo.asm
foo: foo.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
