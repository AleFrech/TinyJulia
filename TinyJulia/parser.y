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
    int  num_t;
    Statement *statement_t;
	BlockStatement *blkstatement_t;
    Expr *expr_t;
    ExprList *exprlist_t;
}

%token<num_t> TK_NUM
%token<charPointer_t> TK_ID
%token<charPointer_t> STRING_LITERAL

%%

start: statementList {((Statement *)$1)->execute();}
;

statementList: statementList statement {((BlockStatement*)$1)->statementList.push_back((Statement*)$2); $$=$1;}
    | statement {BlockStatement* bs = new BlockStatement(); bs->statementList.push_back((Statement*)$1); $$=bs;}
;

statement: print_statement TK_EOS {$$=$1;}
    | assign_statement TK_EOS {$$= $1;}
;

assign_statement: TK_ID TK_EQ expression {$$ = new AssignStatement((VarExpr*)$1,((Expr*)$3));}
;

print_statement: TK_PRINT TK_PAR_LEFT argumentList TK_PAR_RIGHT {$$ = new PrintStatement((ExprList*)$3);}
;

argumentList: argumentList TK_COMMA argument {((ExprList*)$1)->expressionList.push_back((Expr*)$3); $$=$1;}
    | argument { auto l = new ExprList(); l->expressionList.push_back((Expr*)$1); $$ =l;}
;

argument: expression {$$=$1;}
    | TK_STRING {$$=$1;}
    | TK_CHAR   {$$=$1;}
;

expression: aritmethic {$$=$1;}
;

aritmethic: aritmethic TK_ADD term {$$ =new AddExpr((Expr*)$1,(Expr*)$3);}
    | aritmethic TK_SUB term {$$ =new SubExpr((Expr*)$1,(Expr*)$3);}
    | term {$$=$1;}
;

term: term TK_MULT exponent {$$ =new MultExpr((Expr*)$1,(Expr*)$3);}
    | term TK_DIV exponent {$$ =new DivExpr((Expr*)$1,(Expr*)$3);}
    | term TK_MOD exponent {$$ =new ModExpr((Expr*)$1,(Expr*)$3);}
    | exponent {$$ =$1;}
;

exponent: exponent TK_EXP factor {$$ = new ExpExpr((Expr*)$1,(Expr*)$3);}
    | factor    {$$ = $1;}    
;

factor: TK_NUM  {$$ =$1;}
    | TK_ID {$$=$1;}
    | TK_PAR_LEFT expression TK_PAR_RIGHT {$$ = $1;}
;
%%