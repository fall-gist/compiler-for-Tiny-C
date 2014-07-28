YACC=bison
YFLAGS= -dv
LEX=flex
LFLAGS=
OBJS = compiler.tab.o lex.yy.o tree.o emit.o peephole.o
CC=gcc
all: tcc
tree.c: tree.h
	$(CC) -c $@
peephole.c: peephole.h
	$(CC) -c $@
compiler.tab.c: compiler.y
	$(YACC) $(YFLAGS) compiler.y
emit.c: compiler.tab.h emit.h
	$(CC) -c $@
lex.yy.c: compiler.l compiler.tab.h
	$(LEX) $(LFLAGS) compiler.l
tcc: $(OBJS)
	$(CC) -o $@ $(OBJS)
clean:
	rm $(OBJS)