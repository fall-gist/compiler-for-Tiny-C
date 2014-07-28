YACC=bison
YFLAGS= -dv
LEX=flex
LFLAGS=
OBJS = semantic.tab.o lex.yy.o tree_sem.o print.o
CC=gcc
all: tcc
semantic.tab.c: semantic.y
	$(YACC) $(YFLAGS) semantic.y
tree_sem.c: semantic.tab.h tree_sem.h
	$(CC) -c $@
print.c: semantic.tab.h print.h
	$(CC) -c $@
lex.yy.c: semantic.l semantic.tab.h
	$(LEX) $(LFLAGS) semantic.l
tcc: $(OBJS)
	$(CC) -o $@ $(OBJS)
clean: 
	rm $(OBJS)