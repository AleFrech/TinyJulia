%option noyywrap
%option yylineno

%x commentState

%{
    #include <stdio.h>
    #include "tokens.h"
    void initLexer(char * fileName);
%}

%%
[ \t] {}
\n    {yylineno++; return TK_EOL;}
"#="  {BEGIN(commentState);}
"#".*  {}
"+"     {return '+';}
"-"     {return '-';}
"!"     {return '!';}  
"?"     {return '?';}
"*"     {return '*';}  
"/"     {return '/';}  
"%"     {return '%';}  
"^"     {return '^';}
"~"     {return '~';}
"&"     {return '&';}
"|"     {return '|';}
"$"     {return '$';}
">>"    {return TK_SHIFT_RIGHT;}
"<<"    {return TK_SHIFT_LEFT;}
"=="    {return TK_EQUALS;}
"!="    {return TK_NOT_EQUALS;}
"<"     {return '<';}
"<="    {return TK_LESS_THAN_EQUALS;}
">="    {return TK_GREATER_THAN_EQUALS;}
"&&"    {return TK_LOGICAL_AND;}
"||"    {return TL_LOGICAL_OR;}
">"     {return '>';}
"("     {return '(';}
")"     {return ')';}
"["     {return '[';}
"]"     {return ']';}
";"     {return ';';}
"::"    {return TK_DOUBLE_COLON;}
":"     {return ':';}
","     {return ',';}
"="     {return '=';}
"+="    {return TK_ADD_ASGN;}
"-="    {return TK_SUB_ASGN;}
"*="    {return TK_MULT_ASGN;}
"/="    {return TK_DIV_ASGN;}
"%="    {return TK_MOD_ASGN;}
"^="    {return TK_POW_ASGN;}
"&="    {return TK_BIT_AND_ASGN;}
"|="    {return TK_BIT_OR_ASGN;}
"$="    {return TK_BIT_XOR_ASGN;}
"print" {return TK_PRINT;}
"println" {return TK_PRINTLN;}
"true"  {yylval.bool_t = true; return TK_TRUE;} 
"false" {yylval.bool_t = false; return TK_FALSE;}
"Bool"  {return TK_BOOL;}
"Int"   {return TK_INT;}
"if"    {return TK_IF;}
"else"  {return TK_ELSE;}
"elseif" {return TK_ELSEIF;}
"while" {return TK_WHILE;}
"for"   {return TK_FOR;}
"function" {return TK_FUNCTION;}
"return"    {return TK_RETURN;}
"end"   {return TK_END;}
"Array" {return TK_ARRAY;}          
[0-9]+  {yylval.int_t = atoi(yytext); return TK_NUM;}
[_a-zA-Z][a-zA-Z0-9]* {yylval.charPointer_t = strdup(yytext); return TK_ID;}
\"([^"])*\" {yytext[yyleng-1] = '\0'; yylval.charPointer_t = strdup(&yytext[1]); return STRING_LITERAL;}
.       {printf("Invalid Character: %s\n",yytext); return TK_ERROR;}
<INITIAL><<EOF>> {return 0;}
<commentState>"=#" {BEGIN(INITIAL);}
<commentState>.|\n {}
<commentState><<EOF>> {printf("Line %d : unclosed block comment\n",yylineno); return TK_ERROR;}
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