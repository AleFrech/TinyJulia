%code requires {
    #include "ast.h"
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

%union {
    char *charPointer_t;
    int  int_t;
    Statement *statement_t;
	BlockStatement *blkstatement_t;
    Expr *expr_t;
    ExprList *exprlist_t;
}

%token<num_t> TK_NUM
%token<charPointer_t> TK_ID
%token<charPointer_t> STRING_LITERAL
%token TK_EOL TK_INC TK_DEC TK_SHIFT_RIGHT TK_SHIFT_LEFT TK_EQUALS TK_NOT_EQUALS TK_LESS_THAN_EQUALS TK_GREATER_THAN_EQUALS
%token TK_LOGICAL_AND TL_LOGICAL_OR TK_DOUBLE_COLON TK_ADD_ASGN TK_SUB_ASGN TK_MULT_ASGN TK_DIV_ASGN TK_MOD_ASGN TK_POW_ASGN
%token TK_PRINT TK_PRINTLN TK_TRUE TK_FALSE TK_BOOL TK_INT TK_IF TK_ELSE TK_ELSEIF TK_WHILE TK_FOR TK_FUNCTION TK_RETURN
%token TK_END TK_ERROR

%type<expr_t> argument
%type<statement_t> print_statement
%type<statement_t> statement
%type<blkstatement_t> statementList

%%

start: opEols statementList opEols {$2->execute();}
;

opEols: TK_EOL
    | %empty
;


statementList: statementList TK_EOL statement { $$ = $1; $$->add($3); }
    | statement { $$ = new BlockStatement; $$->add($1); }
;

statement: print_statement  {$$ = $1;}
;

print_statement: TK_PRINT '(' argument ')' {$$ = new PrintStatement($3,false);}
    | TK_PRINTLN '(' argument ')' {$$ = new PrintStatement($3,true);}
;

argument: STRING_LITERAL {$$ = new StringExpr(string($1));}
;
%%