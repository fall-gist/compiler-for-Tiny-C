CC = gcc
CCFLAG = -m32
ASM = nasm
ASMFLAG = -f macho
OBJS = bre_con.o main.c
all: bre_con
bre_con.o: bre_con.asm
	$(ASM) $(ASMFLAG) bre_con.asm
bre_con: bre_con.o main.c
	$(CC) $(CCFLAG) -o $@ $(OBJS)
