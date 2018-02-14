%option noyywrap
%option yylineno


%{
    #include <stdio.h>
    #include "tokens.h"
    void initLexer(char * fileName);
%}

%%
"[ \t]" {}
"\n"    {}
[0-9]+ {return TK_NUM;}
<<EOF>> {return TK_EOF;}
%%


void initLexer(char * fileName){
    FILE *file =fopen(fileName,"r");

    if(file == NULL){
        fprintf(stderr,"File %s not found.\n",fileName);
        exit(-1);
    }
    YY_BUFFER_STATE currentBuffer = yy_create_buffer(file,YY_BUF_SIZE);
    yy_switch_to_buffer(currentBuffer);
}