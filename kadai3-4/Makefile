YACC=bison
YFLAGS= -dv
LEX=flex
LFLAGS=
OBJS = parser.tab.o lex.yy.o
CC=gcc
all: tcc
parser.tab.c: parser.y
	$(YACC) $(YFLAGS) parser.y
lex.yy.c: parser.l parser.tab.h
	$(LEX) $(LFLAGS) parser.l
tcc: $(OBJS)
	$(CC) -o $@ $(OBJS)
clean: 
	rm $(OBJS)