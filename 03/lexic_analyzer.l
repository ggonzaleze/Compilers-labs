%{
#include <stdio.h>
%}

%%
\/\/[a-zA-Z0-9]+[\n]
i[ ]+[a-eg-hj-oq-z]			fprintf(yyout,"intdcl id");
f[ ]+[a-eg-hj-oq-z]			fprintf(yyout,"floatdcl id");
=					fprintf(yyout,"assign");
\+					fprintf(yyout,"plus");
\-					fprintf(yyout,"minus");
\*					fprintf(yyout,"times");
\/					fprintf(yyout,"div");
[0-9]+					fprintf(yyout,"inum");
[a-e]|[g-h]|[j-o]|[q-z]			fprintf(yyout,"id");
[0-9]+\.[0-9]{1,5}			fprintf(yyout,"fnum");
p[ ]+[a-eg-hj-oq-z]			fprintf(yyout,"print id");
%%

int yywrap() 
{ 
    return 1; 
} 
  
/* code section */
int main(int argc, char *argv[]) 
{ 
        extern FILE *yyin, *yyout; 
        /* open the source file  
           in read mode */
    yyin=fopen(argv[1],"r"); 
  
          
        /* open the output file  
           in write mode */
    yyout=fopen("lex.out","w"); 
    yylex(); 
} 
