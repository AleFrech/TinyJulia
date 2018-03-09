%option noyywrap


%{
#include <stdio.h>
#include "tokens.h"
%}

letter [_a-zA-Z]
%%
[ \t\n]	{ /* Nada */ }
"+"		{ return '+'; }
"-"		{ return '-'; }
"*"		{ return '*'; }
"/"		{ return '/'; }
"("		{ return '('; }
")"		{ return ')'; }
";"		{ return ';'; }
"="		{ return '='; }
"{"		{ return '{'; }
"}"		{ return '}'; }
"if"	{ return KW_IF; }
"else"	{ return KW_ELSE; }
"print"	{ return KW_PRINT; }
"while"	{ return KW_WHILE; }
[0-9]+	{ yylval.string_t = strdup(yytext); return TK_NUMBER; }
{letter}({letter}|[0-9])* { yylval.string_t = strdup(yytext); return TK_ID; }
.		{ return TK_ERROR; }
%%
