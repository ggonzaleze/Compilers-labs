%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(const char* s);
%}

%token A B C NL 

%%
S: A B C E	{ printf("passed\n"); return 0; }
 ;
E: C NL
 | NL
 ;
%%

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }
int main(void)
 {
 return yyparse();
 }

