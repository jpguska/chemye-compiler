CPP = g++
CPPFLAGS = -g -std=c++17 -Wall
LEX  = flex++
YACC = bison
YACCFLAGS = --defines=bison.tab.h -o bison.tab.cpp
LEX_CPP   = lex.yy.cpp
YACC_CPP  = bison.tab.cpp
YACC_H    = bison.tab.h


all: compilador raposeitor

compilador: bison.tab.o lex.yy.o
	$(CPP) $(CPPFLAGS) bison.tab.o lex.yy.o -o compilador

bison.tab.o: $(YACC_CPP)
	$(CPP) $(CPPFLAGS) -c $(YACC_CPP) -o bison.tab.o

lex.yy.o: $(LEX_CPP) $(YACC_H)
	$(CPP) $(CPPFLAGS) -c $(LEX_CPP) -o lex.yy.o

$(YACC_CPP) $(YACC_H): synan.y
	$(YACC) $(YACCFLAGS) synan.y

$(LEX_CPP): lexan.l $(YACC_H)
	$(LEX) -o $(LEX_CPP) lexan.l

raposeitor: raposeitor.cpp
	$(CPP) $(CPPFLAGS) raposeitor.cpp -o raposeitor

run: compilador raposeitor
	./compilador < $(TESTFILE) > assembly.rap
	./raposeitor assembly.rap

%.alch: compilador raposeitor
	./compilador < $@ > assembly.rap
	./raposeitor assembly.rap

clean:
	rm -f *.o compilador raposeitor bison.tab.* lex.yy.* assembly.rap