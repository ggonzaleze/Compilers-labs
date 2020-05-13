all:
	gcc -c toPostfix.c -o toPostfix.o	
	gcc -c syntax-direct-translator.c -o syntax-direct.o
	gcc toPostfix.o syntax-direct.o -o syntax-direct-translator
clean:
	rm toPostfix.o
	rm syntax-direct.o
	rm syntax-direct-translator
