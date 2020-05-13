#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* infixToPostfix(char* s);

int isOperator(char o){
        if(o == '+' | o == '-' | o == '/' | o == '*'){
                return 1;
        }
        return 0;
}

int isValid(char* s) {
        int i;
        int r;
        for(i = 0; i < strlen(s); i++){
                if(isdigit(s[i]) == 0){
                        break;
                }
        }
        r = i;
        for(; i < strlen(s); i++){
                if(isOperator(s[i]) == 0){
                        return -1;
                }
        }
        if(strlen(s) - r == r - 1)
                return r;
        else
                return -1;
}

char* operation(char o) {
        switch(o)
        {
                case '+':
                        return "add";
                case '-':
                        return strdup("sub");
                case '/':
                        return "div";
                case '*':
                        return "mul";
        }
}

void toMiddleCode(char* s, int r) {
        char line[100];
        line[0] = '\0';
        char num[2];
        char* op = operation(s[r]);
        strcat(line, op);
        strcat(line, " ");
        num[0] = s[r-2];
        num[1] = '\0';
        strcat(line, num);
        strcat(line, ",");
        num[0] = s[r-1];
        num[1] = '\0';
        strcat(line, num);
        strcat(line, ",acum");
        printf("%s\n",line);

	int i;
	line[0] = '\0';
	for(i = 1; i+r < strlen(s); i++){
		char* op = operation(s[r+i]);
		strcat(line, op);
		strcat(line, " &acum,");
		num[0] = s[r-(2+i)];
		num[1] = '\0';
		strcat(line, num);
		strcat(line, ",acum \n");
	}
	printf("%s\n",line);
}

void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

void createCode(char *line) {
        remove_spaces(line);
        line[strlen(line) - 1] = '\0';
        char *infix = infixToPostfix(line);
        int r = isValid(infix);
        if( r != -1){
                toMiddleCode(infix, r);
        }else{
                printf("%s",infix);
                printf(" is invalid \n");
        }
}

int main(int argc, char *argv[])
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        createCode(line);
    }
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
