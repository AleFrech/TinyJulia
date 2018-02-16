%code requires {
    #include <string>
}

%{
#include <stdio.h>
#include <list>
#include <iostream>
#include <string>
using namespace std;
int yylex();
extern int yylineno;

void yyerror(const char* msg){
    printf("%s  in Line : %d\n",msg,yylineno);
}

#define YYERROR_VERBOSE 1  
%}

%token TK_ADD TK_SUB TK_MULT TK_DIV TK_MOD TK_EXP TK_NUM TK_ID TK_STRING TK_CHAR TK_PRINT TK_PAR_LEFT TK_PAR_RIGHT TK_ERROR TK_COMMA

%%

start: statementList
;

statementList: statementList statement
    | statement
;

statement: print_statement TK_COMMA
;

print_statement: TK_PRINT TK_PAR_LEFT argument TK_PAR_RIGHT
;

argument: expression
    | TK_STRING
    | TK_CHAR
;

expression: aritmethic 
;

aritmethic: aritmethic TK_ADD term
    | aritmethic TK_SUB term
    | term
;

term: term TK_MULT exponent
    | term TK_DIV exponent
    | term TK_MOD exponent
    | exponent
;

exponent: exponent TK_EXP factor
    | factor
;

factor: TK_NUM
    | TK_ID
    | TK_PAR_LEFT expression TK_PAR_RIGHT
;
%%