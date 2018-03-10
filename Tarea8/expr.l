%option noyywrap
%option yylineno
%x commentState

%{
#include <stdio.h>
#include "tokens.h"
%}

letter [_a-zA-Z]
%%
[ \t\n]	{ /* Nada */ }
"/*"    {BEGIN(commentState);}
"//".*  {}
"+"		{ return '+'; }
"-"		{ return '-'; }
"*"		{ return '*'; }
"/"		{ return '/'; }
"%"     { return '%'; }
">"     { return '>'; }
"<"     { return '<'; }
">="    { return KW_GTE; }
"<="    { return KW_LTE;}
"!="    { return KW_NE;}
"=="    { return KW_EQ;}
"("		{ return '('; }
")"		{ return ')'; }
";"		{ return ';'; }
","     { return ','; }
"="		{ return '='; }
"{"		{ return '{'; }
"}"		{ return '}'; }
"if"	{ return KW_IF; }
"else"	{ return KW_ELSE; }
"print"	{ return KW_PRINT; }
"println"   {return KW_PRINTLN;}
"while"	{ return KW_WHILE; }
"return" { return KW_RETURN; }
[0-9]+	{ yylval.string_t = strdup(yytext); return TK_NUMBER; }
{letter}({letter}|[0-9])* { yylval.string_t = strdup(yytext); return TK_ID; }
<INITIAL><<EOF>> {yyterminate();}
.		{printf("Invalid Character: %s\n",yytext); return TK_ERROR; }
<commentState>"*/" {BEGIN(INITIAL);}
<commentState>.|\n {}
<commentState><<EOF>> {printf("Line %d : unclosed block comment\n",yylineno); return 0;}

%%
