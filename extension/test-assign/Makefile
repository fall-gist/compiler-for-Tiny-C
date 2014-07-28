CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = assign.o main.c
all: assign
assign.o: assign.asm
	$(ASM) $(ASMFLAG) assign.asm
assign: assign.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
