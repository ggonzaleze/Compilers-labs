#include <stdio.h>
void main(int argc, char *argv[]){
	char *filename = argv[1];
	FILE *f;
	char c;
	int parenthesis = 0;
	int brackets = 0;
	int braces = 0;
	int quotes = 0;
	int squotes = 0;
	int isComment = 0;
	int isChar = 0;
	int isStr = 0;
	if ((f = fopen(filename,"r")) == NULL){
		printf("Error opening file");
	}
	while((c = fgetc(f)) != EOF){
		if( c == '/' && fgetc(f) == '/'){
			isComment = 1;
		}
		if(c == '\n' && isComment == 1){
			isComment = 0;
		}
		if(c == '"' 
			&& isComment == 0 
			&& isChar == 0){
				if(isStr == 0){
					isStr = 1;
				}else{isStr = 0;}
				quotes = quotes + 1;
		}
		if(c == '\''
                        && isComment == 0
                        && isStr == 0){
                                if(isChar == 0){
                                        isChar = 1;
                                }else{isChar = 0;}
                                squotes = squotes + 1;
                }
		if( (c == '(' || c == ')') 
			&& isComment == 0
			&& isChar == 0
			&& isStr == 0){
				parenthesis = parenthesis + 1;
		}
		if( (c == '{' || c == '}')
                        && isComment == 0
                        && isChar == 0
                        && isStr == 0){
                                braces = braces + 1;
                }
		if( (c == '[' || c == ']')
                        && isComment == 0
                        && isChar == 0
                        && isStr == 0){
                                brackets = brackets + 1;
                }		
	}
	fclose(f);	
	int errors = 0;
	if(quotes%2!=0){
                printf("Unbalanced quotes \"\" \n");
                errors = errors + 1;
        }
        if(squotes%2!=0){
                printf("Unbalanced single quotes \'\' \n");
                errors = errors + 1;
        }	
	if(parenthesis%2!=0){
		printf("Unbalanced parenthesis () \n");
		errors = errors + 1;
	}
	if(braces%2!=0){
                printf("Unbalanced braces {} \n");
		errors = errors + 1;
        }
	if(brackets%2!=0){
                printf("Unbalanced brackets [] \n");
		errors = errors + 1;
        }
	if(errors == 0){
		printf("No errors \n");
	}
}
