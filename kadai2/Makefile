CC=gcc
YACC=bison
YFLAGS=-d
LEX=flex
LFLAGS=
OBJS=calc.tab.o lex.yy.o
all: calc
calc.tab.c: calc.y
	$(YACC) $(YFLAGS) calc.y
lex.yy.c: calc.l calc.tab.h
	$(LEX) $(LFLAGS) calc.l
calc: $(OBJS)
	$(CC) -o $@ $(OBJS)
clean: 
	rm $(OBJS)