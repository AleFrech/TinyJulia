%code requires {
    #include "ast.h"
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
int errors;

void yyerror(const char* msg){
    printf("%s  in Line : %d\n",msg,yylineno);
    errors ++;
}

#define YYERROR_VERBOSE 1  
%}

%union{
    Statement * Statement_t;
    Expr * expr_t;
    int int_t;
    string * string_t;
    list<Expr*> *exprList_t;
}

%type <expr_t> expr term factor argument arithmetic relationals equalities pow 
%type <exprList_t> argumentList
%type <Statement_t> statementList statement print pass assign while block if else for
%token OP_ADD OP_SUB OP_MULT OP_DIV OP_EXP OP_MOD OP_LT OP_LTE OP_GT OP_GTE OP_NEQ OP_EQ OP_ASSGN
%token PAR_LEFT PAR_RIGHT TK_SEMICOLON TK_PRINT TK_WHILE TK_IF TK_ELSE TK_FOR TK_IN TK_RANGE TK_SPACE TK_PASS TK_EOL TK_ERROR TK_INPUT TK_COMMA OPEN_INDENT CLOSE_INDENT
%token <int_t> LIT_NUM
%token <string_t> LIT_STRING TK_ID



%%

start: opEols statementList opEols {$2->execute();}
;

opEols: TK_EOL
    | %empty
;

statementList: statementList TK_EOL statement {$$ =$1; ((BlockStatement*)$$)->statementList.push_back($3);}
    | statement {$$ = new BlockStatement();((BlockStatement*)$$)->statementList.push_back($1);}
;

statement: print 
    | pass
    | assign
    | while
    | if
    | for
;

while: TK_WHILE expr TK_SEMICOLON block {$$ = new WhileStatement($2,$4);}
;

if: TK_IF expr TK_SEMICOLON block  else {$$ = new IfStatement($2,$4,$5);}
;

else: TK_ELSE TK_SEMICOLON block {$$=$3;}
    | %empty {$$=NULL;}
;

for: TK_FOR TK_ID TK_IN TK_RANGE PAR_LEFT expr TK_COMMA expr PAR_RIGHT TK_SEMICOLON block {$$ = new ForStatement(*$2, $6, $8, $11);}
;

block: OPEN_INDENT statementList CLOSE_INDENT {$$ = $2;}
;

pass: TK_PASS {$$ = new PassStatement();}
;

assign: TK_ID OP_ASSGN expr {$$ = new AssignStatement(*$1,$3);}
;

print: TK_PRINT PAR_LEFT argumentList PAR_RIGHT {$$= new PrintStatement($3);}
;

argumentList: argumentList TK_COMMA argument {auto l =$1; l->push_back($3); $$=l;}
    | argument {auto l = new list<Expr*>(); l->push_back($1); $$=l;}
;

argument: expr {$$ = $1;}
    | LIT_STRING {$$ = new StringExpr(*$1);}
;

expr: equalities {$$ = $1;}
;

equalities: equalities OP_EQ relationals  {$$ = new EqualExpr($1,$3);}
    | equalities OP_NEQ relationals {$$ = new NotEqualExpr($1,$3);}
    | relationals {$$ = $1;}
;

relationals: relationals OP_GT arithmetic {$$ = new GreaterThanExpr($1,$3);}
    | relationals OP_LT arithmetic {$$ = new LessThanExpr($1,$3);}
    | relationals OP_GTE arithmetic {$$ = new GreaterThanEqualExpr($1,$3);}
    | relationals OP_LTE arithmetic {$$ = new LessThanEqualExpr($1,$3);}
    | arithmetic {$$ =$1;}
;

arithmetic: arithmetic OP_ADD term {$$ = new AddExpr($1,$3);}
    | arithmetic OP_SUB term {$$ = new SubExpr($1,$3);}
    | term  {$$ = $1;}
;

term: term OP_MULT pow {$$ = new MulExpr($1,$3);} 
    | term OP_DIV pow {$$ = new DivExpr($1,$3);}
    | term OP_MOD pow {$$ = new ModExpr($1,$3);}
    | pow {$$ = $1;}
;

pow: pow OP_EXP factor {$$ = new PowExpr($1,$3);}
    | factor {$$ = $1;}
;

factor: LIT_NUM {$$ = new NumberExpr($1);}
    | TK_INPUT PAR_LEFT LIT_STRING PAR_RIGHT {$$ = new InputExpr(*$3);} 
    | TK_ID {$$ = new VarExpr(*$1);}
    | PAR_LEFT expr PAR_RIGHT {$$ = $2;}
;
%%