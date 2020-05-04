all:
	lex lex.l
	yacc -d syntax_analyzer.y
	gcc lex.yy.c y.tab.c y.tab.h -o syntax_analyzer -lfl
clean:
	rm lex.yy.c
	rm syntax_analyzer
	rm y.tab.c
	rm y.tab.h
