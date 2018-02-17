%option noyywrap
%option yylineno

%{
    #include <stdio.h>
    #include "tokens.h"
    void initLexer(char * fileName);
%}

%%
[ \t] {}
"\n"    {yylineno++;}
"+"     {return TK_ADD;}
"-"     {return TK_SUB;}  
"*"     {return TK_MULT;}  
"/"     {return TK_DIV;}  
"%"     {return TK_MOD;}  
"^"     {return TK_EXP;}
"("     {return TK_PAR_LEFT;}
")"     {return TK_PAR_RIGHT;}
";"     {return TK_EOS;}
","     {return TK_COMMA;}
"="     {return TK_EQ;}
"print" {return TK_PRINT;}           
[0-9]+  {yylval=new NumExpr(atoi(yytext)); return TK_NUM;}
[_a-zA-Z][a-zA-Z0-9]*   {yylval = new VarExpr(string(yytext)); return TK_ID;}
\"((\\[\"n\\])|[^"\\])*\"   {yylval = new StringExpr(string(yytext)); return TK_STRING;}
\'((\\[\"n\\])|[^'\\])\'    {yylval = new CharExpr(string(yytext)); return TK_CHAR;}
.       {printf("Invalid Character: %s\n",yytext); return TK_ERROR;}
<<EOF>> {return 0;}
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