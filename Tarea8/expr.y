%code requires {
	#include "ast.h"
}
%{
#include <stdio.h>
#include <iostream>
#include <string>
#include "tokens.h"
#include <list>

int yylex();
int errors;

void yyerror(const char *msg) {
	errors++;
	fprintf(stderr, "%s\n", msg);
}

using namespace std;

BlockStatement *statement;

#define YYERROR_VERBOSE 1
%}

%union {
    Expr *expr_t;
	Statement *statement_t;
	BlockStatement *blk_statement_t;
    char *string_t;
	ExprList *exprlist_t;
}

%token OP_ADD OP_SUB OP_MUL OP_DIV TK_LEFT_PAR TK_RIGHT_PAR
%token<string_t> TK_NUMBER "number"
%token<string_t> TK_ID "identifier"
%token KW_IF KW_ELSE KW_WHILE KW_PRINT KW_GTE KW_LTE KW_NE KW_EQ KW_PRINTLN KW_RETURN
%token TK_ERROR

%type<expr_t> expr equalities relationals arithmetic term factor
%type<exprlist_t> expr_list
%type<statement_t> assign_statement
%type<statement_t> if_statement
%type<statement_t> opt_else
%type<statement_t> while_statement
%type<statement_t> print_statement
%type<statement_t> statement
%type<blk_statement_t> statement_list opt_statement_list

%%

input: opt_statement_list {
			statement = $1;
		}
;

opt_statement_list: statement_list	{ $$ = $1; }
					|				{ $$ = NULL; }
;

statement_list: statement_list statement
				{ $$ = $1; $$->addStatement($2); }
				| statement { $$ = new BlockStatement(); $$->addStatement($1); }
;

statement: print_statement	 { $$ = $1; }
		 | assign_statement	 { $$ = $1; }
		 | if_statement	     { $$ = $1; }
		 | while_statement	 { $$ = $1; }
;

print_statement: KW_PRINT expr ';' { $$ = new PrintStatement($2,false); }
				| KW_PRINTLN expr ';' {$$ = new PrintStatement($2,true);}
;

assign_statement: TK_ID '=' expr ';' {
			string id = $1;
			free($1);

			$$ = new AssignStatement(id, $3);
		}
;

if_statement: KW_IF '(' expr ')' '{' statement_list '}' opt_else
			  { $$ = new IfStatement($3, $6, $8); }
;

opt_else: KW_ELSE '{' statement_list '}' { $$ = $3; }
		 | 								 { $$ = NULL; }
;

while_statement: KW_WHILE '(' expr ')' '{' statement_list '}' { $$ = new WhileStatement($3, $6); }
;

expr_list: expr_list ',' expr {$1->push_back($3); $$=$1; }
	| expr {auto exl= new ExprList; exl->push_back($1); $$=exl;}
;

expr: equalities {$$ = $1;}
;

equalities: equalities KW_EQ relationals  {$$ = new EqualExpr($1,$3);}
    | equalities KW_NE relationals {$$ = new NotEqualExpr($1,$3);}
    | relationals {$$ = $1;}
;

relationals: relationals '>' arithmetic {$$ = new GreaterThanExpr($1,$3);}
    | relationals '<' arithmetic {$$ = new LessThanExpr($1,$3);}
    | relationals KW_GTE arithmetic {$$ = new GreaterThanEqualExpr($1,$3);}
    | relationals KW_LTE arithmetic {$$ = new LessThanEqualExpr($1,$3);}
    | arithmetic {$$ =$1;}
;

arithmetic:  arithmetic '+' term { $$ = new AddExpr($1, $3);; }
	  | arithmetic '-' term { $$ = new SubExpr($1, $3); }
	  | term { $$ = $1; }
;

term:  term '*' factor { $$ = new MulExpr($1, $3); }
	  | term '/' factor { $$ = new DivExpr($1, $3); }
	  | term '%' factor {$$ = new ModExpr($1, $3); }
	  | factor { $$ = $1; }
;

factor: TK_NUMBER {
		  string numStr = $1;
		  free($1);
		  $$ = new NumExpr(numStr);
  		}
        | TK_ID   {
              string id = $1;
              free($1);
              $$ = new IdExpr(id);
          }
		| TK_ID '(' expr_list ')' {
              string id = $1;
              free($1);
              $$ = new FunctionCallExpr(id,$3);
          }
		| TK_ID '(' ')' {
              string id = $1;
              free($1);
              $$ = new FunctionCallExpr(id);
          }
		| '(' expr ')' { $$ = $2; }
;
