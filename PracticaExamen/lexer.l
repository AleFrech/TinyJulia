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
"+"     {return TK_ADD;}
"-"     {return TK_SUB;}  
"*"     {return TK_MULT;}  
"/"     {return TK_DIV;}  
"%"     {return TK_MOD;}  
"^"     {return TK_EXP;}
"("     {return TK_PAR_LEFT;}
")"     {return TK_PAR_RIGHT;}
"print" {return TK_PRINT;}           
[0-9]+  {return TK_NUM;}
[_a-zA-Z][a-zA-Z0-9]*   {return TK_ID;}
\"(\\.|[^"\\])*\"   {return TK_STRING;}
\'(\\.|[^'\\])\'    {return TK_CHAR;}
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