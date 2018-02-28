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
    bool bool_t;
    Statement *statement_t;
	BlockStatement *blkstatement_t;
    Expr *expr_t;
    ExprList *exprlist_t;
}

%token<int_t> TK_NUM
%token<bool_t> TK_TRUE TK_FALSE
%token<charPointer_t> TK_ID
%token<charPointer_t> STRING_LITERAL
%token TK_EOL TK_INC TK_DEC TK_SHIFT_RIGHT TK_SHIFT_LEFT TK_EQUALS TK_NOT_EQUALS TK_LESS_THAN_EQUALS TK_GREATER_THAN_EQUALS
%token TK_LOGICAL_AND TL_LOGICAL_OR TK_DOUBLE_COLON TK_ADD_ASGN TK_SUB_ASGN TK_MULT_ASGN TK_DIV_ASGN TK_MOD_ASGN TK_POW_ASGN TK_BIT_AND_ASGN
%token TK_PRINT TK_PRINTLN TK_BOOL TK_INT TK_IF TK_ELSE TK_ELSEIF TK_WHILE TK_FOR TK_FUNCTION TK_RETURN TK_BIT_XOR_ASGN TK_BIT_OR_ASGN
%token TK_ARRAY TK_END TK_ERROR

%type<exprlist_t> argument_expression_list
%type<expr_t> print_argument factor post_id unary_exp expression term exponent shift_exp aritmethic relational_expr
%type<expr_t> bit_and_exp bit_xor_exp bit_or_exp conditional_and_exp conditional_or_exp conditional_exp assign_exp 
%type<statement_t> print_statement
%type<statement_t> statement
%type<blkstatement_t> statementList

%%

start: opEols statementList opEols {$2->execute();}
;

new_line:  new_line TK_EOL
    | TK_EOL
;

opEols: new_line
    | %empty
;

statementList: statementList TK_EOL statement { $$ = $1; $$->add($3); }
    | statement { $$ = new BlockStatement; $$->add($1); }
;

statement: print_statement  {$$ = $1;}
;

print_statement: TK_PRINT '(' print_argument ')' {$$ = new PrintStatement($3,false);}
    | TK_PRINTLN '(' print_argument ')' {$$ = new PrintStatement($3,true);}
;

print_argument: STRING_LITERAL {$$ = new StringExpr(string($1)); delete $1;}
    | expression
;

argument_expression_list: argument_expression_list ',' expression {$1->push_back($3); $$=$1; }
    | expression {$$ = new ExprList;}
;

expression: assign_exp {$$ = $1;}
;

assign_exp: post_id '=' assign_exp {$$ = new AssignExpr($1,$3);}
    |post_id TK_ADD_ASGN assign_exp {$$ = new AssignExpr($1,new AddExpr($1,$3));}
    |post_id TK_SUB_ASGN assign_exp {$$ = new AssignExpr($1,new SubExpr($1,$3));}
    |post_id TK_MULT_ASGN assign_exp {$$ = new AssignExpr($1,new MulExpr($1,$3));}
    |post_id TK_DIV_ASGN assign_exp {$$ = new AssignExpr($1,new DivExpr($1,$3));}
    |post_id TK_MOD_ASGN assign_exp {$$ = new AssignExpr($1,new ModExpr($1,$3));}
    |post_id TK_POW_ASGN assign_exp {$$ = new AssignExpr($1,new ExponentExpr($1,$3));}
    |post_id TK_BIT_OR_ASGN assign_exp {$$ = new AssignExpr($1,new BitOrExpr($1,$3));}
    |post_id TK_BIT_XOR_ASGN assign_exp {$$ = new AssignExpr($1,new BitXorExpr($1,$3));}
    |post_id TK_BIT_AND_ASGN assign_exp {$$ = new AssignExpr($1,new BitAndExpr($1,$3));}
    | conditional_exp {$$ = $1;}
;

conditional_exp: conditional_or_exp '?' expression ':' expression {$$ = new TernaryExpr($1,$3,$5);}
    | conditional_or_exp {$$ = $1;}
;

conditional_or_exp: conditional_or_exp TL_LOGICAL_OR conditional_and_exp {$$ = new LogicalOrExpr($1,$3);}
    | conditional_and_exp {$$ =$1;}
;

conditional_and_exp: conditional_and_exp TK_LOGICAL_AND bit_or_exp {$$ = new LogicalAndExpr($1,$3);}
    | bit_or_exp {$$ = $1;}
;

bit_or_exp: bit_or_exp '|' bit_xor_exp {$$ = new BitOrExpr($1,$3);}
    | bit_xor_exp {$$ =$1;}
;

bit_xor_exp: bit_xor_exp '$' bit_and_exp {$$ = new BitXorExpr($1,$3);}
    | bit_and_exp {$$ =$1;}
;

bit_and_exp: bit_and_exp '&' relational_expr {$$ = new BitAndExpr($1,$3);}
    | relational_expr {$$ = $1;}
;

relational_expr: relational_expr TK_EQUALS aritmethic {$$ = new EqualExpr($1,$3);} 
    | relational_expr TK_NOT_EQUALS aritmethic {$$ = new NotEqualExpr($1,$3);} 
    | relational_expr '>' aritmethic {$$ = new GreaterThanExpr($1,$3);}
    | relational_expr '<' aritmethic {$$ = new LessThanExpr($1,$3);}
    | relational_expr TK_GREATER_THAN_EQUALS aritmethic {$$ = new GreaterThanEqualsExpr($1,$3);}
    | relational_expr TK_LESS_THAN_EQUALS aritmethic {$$ = new LessThanEqualsExpr($1,$3);}
    | aritmethic {$$ =$1;}
;

aritmethic: aritmethic '-' shift_exp {$$ = new SubExpr($1,$3);}
    | aritmethic '+' shift_exp {$$ = new AddExpr($1,$3);}
    | shift_exp {$$ = $1;}
;

shift_exp: shift_exp TK_SHIFT_LEFT term {$$ = new LeftShiftExpr($1,$3);}
    | shift_exp TK_SHIFT_RIGHT term {$$ = new RightShiftExpr($1,$3);}
    | term { $$ = $1;}
;

term: term '*' exponent { $$ = new MulExpr($1,$3);}
    | term '/' exponent { $$ = new DivExpr($1,$3);}
    | term '%' exponent { $$ = new ModExpr($1,$3);}
    | exponent  { $$ = $1; }
;

exponent: exponent '^' unary_exp {$$ = new ExponentExpr($1,$3);}
    | unary_exp {$$ = $1;}
;

unary_exp: '-' unary_exp {$$ = new UnarySubExpr($2);}
    | '+' unary_exp {$$ = new UnaryAddExpr($2);}
    | '~' unary_exp {$$ = new UnaryDistintExpr($2);}
    | '!' unary_exp {$$ = new UnaryNotExpr($2);}
    | post_id {$$ = $1;}
;

post_id: factor {$$ = $1;}
    | TK_ID '(' argument_expression_list ')' {$$ = new ParenthesisPosIdExpr(string($1),$3); delete $1;}
    | TK_ID '(' ')' {$$ = new ParenthesisPosIdExpr(string($1)); delete $1;}
    | TK_ID '[' expression ']' {$$ = new BracketPostIdExpr(string($1),$3); delete $1;}
;

factor: TK_NUM  {$$ = new NumberExpr($1);}
    | TK_TRUE   {$$ = new BoolExpr($1);}
    | TK_FALSE {$$ = new BoolExpr($1);}
    | TK_ID     {$$ = new VarExpr(string($1)); delete $1;}
    | '(' expression ')' {$$ = $2;}
;
%%