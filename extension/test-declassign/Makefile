declassignCC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = declassign.o main.c
all: declassign
declassign.o: declassign.asm
	$(ASM) $(ASMFLAG) declassign.asm
declassign: declassign.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
