YACC=bison
YFLAGS= -dv
LEX=flex
LFLAGS=
OBJS = compiler.tab.o lex.yy.o tree.o emit.o
CC=gcc
all: tcc
compiler.tab.c: compiler.y
	$(YACC) $(YFLAGS) compiler.y
tree.c: compiler.tab.h tree.h
	$(CC) -c $@
emit.c: compiler.tab.h emit.h
	$(CC) -c $@
lex.yy.c: compiler.l compiler.tab.h
	$(LEX) $(LFLAGS) compiler.l
tcc: $(OBJS)
	$(CC) -o $@ $(OBJS)
clean:
	rm $(OBJS)