YACC=bison
YFLAGS= -dv
LEX=flex
LFLAGS=
OBJS = tree.tab.o lex.yy.o prints.o
CC=gcc
all: tcc
tree.tab.c: tree.y
	$(YACC) $(YFLAGS) tree.y
prints.c: tree.tab.h prints.h
	$(CC) -c $@
lex.yy.c: tree.l tree.tab.h
	$(LEX) $(LFLAGS) tree.l
tcc: $(OBJS)
	$(CC) -o $@ $(OBJS)
clean:
	rm $(OBJS)