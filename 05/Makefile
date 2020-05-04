all:
	lex lex.l
	yacc -d syntax_analyzer.y
	gcc lex.yy.c y.tab.c y.tab.h -o syntax_analyzer -lfl
