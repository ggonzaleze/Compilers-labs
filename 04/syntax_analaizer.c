/***************
Grammar
S -> aBc
B -> bc | b
****************/

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct AST {
	char root;
	char *level1;
	char *level2;
};

struct AST ast;
char *l2;
int i = 0;
bool S_prod(char line[]);
bool B_prod(char line[]);
bool End(char line[]);

bool match(char c, char t) {
	if (c == t){
		i++;
		return true;
	}
	else
		return false;
}

bool S_prod(char line[]){
	i = 0;
	if(match(line[i],'a')){
		return B_prod(line);
	}
	else
		return false;
}

bool B_prod(char line[]){
	if(match(line[i],'b')){
		return End(line);
	}
}

bool End(char line[]){
	if( match(line[i],'c') && match(line[i],'\0') ){
		l2 = "b";
		return true; 
	}
	else{
		i--;
		if ( match(line[i],'c') && match(line[i],'c') && match(line[i],'\0') ){
			l2 = "bc";
			return true;
		}
		else
			return false;
	}	
}

void printAST(){
	printf("digraph G {\n");
	int n;
	for(n = 0; n < strlen(ast.level1)-1;n++){
		printf(" \"%c\"->\"%c\" \n",ast.root,ast.level1[n]);
	}
	printf(" \"%c\"->\"%c$\" \n",ast.root,ast.level1[n]);
	for(n = 0; n < strlen(ast.level2);n++){
                printf(" \"B\"->\"%c\" \n",ast.level2[n]);
        }
	printf("} \n");
}

int main(int argc, char *argv[]){
	ast.root = 'S';
	ast.level1 = strdup("aBc");
	char const* const fileName = argv[1];
	FILE* file = fopen(fileName, "r");
	char line[256];
	while (fgets(line, sizeof(line), file)) {
		line[strlen(line) - 1] = '\0';
		if(S_prod(line)){
			printf("%s : Passed \n",line);
			ast.level2 = strdup(l2);
			printAST();
		}else
			printf("%s : Syntax error \n",line); 
	}
	fclose(file);
	
	return 0;
}
