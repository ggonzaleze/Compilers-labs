#include <stdio.h>
#include<string.h>
#include <ctype.h>

/***********************************************************************************************************************************
*    Title: Infix to Postfix Conversion in C
*    Author: Programming9
*    Availability: https://www.programming9.com/programs/c-programs/230-c-program-to-convert-infix-to-postfix-expression-using-stack
***********************************************************************************************************************************/

char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

char* infixToPostfix(char* s) {
        char *e, x;
	char dest[100];
	int i = 0;
        e = s;
        while(*e != '\0')
        {
                if(isalnum(*e)){
			dest[i]=*e;i++;
		}
                else if(*e == '(')
                        push(*e);
                else if(*e == ')')
                {
                        while((x = pop()) != '('){
				dest[i]=x;i++;
			}
                }
                else
                {
                        while(priority(stack[top]) >= priority(*e)){
				dest[i]=pop();i++;
				
			}
                        push(*e);
                }
                e++;
        }
        while(top != -1)
        {
		dest[i]=pop();i++;
        }
	dest[i]='\0';
	return strdup(dest);
}
