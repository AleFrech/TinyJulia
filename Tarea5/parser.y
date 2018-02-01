%{
#include <stdio.h>
int yylex();
extern int yylineno;

void yyerror(const char* msg){
    printf("%s  in Line : %d\n",msg,yylineno);
}

#define YYERROR_VERBOSE 1  
%}

%token OP_ADD OP_SUB OP_MULT OP_DIV PAR_LEFT PAR_RIGHT LIT_NUM TK_ERROR


%%
start: expr {printf("%d\n",$1);}
;

expr: expr OP_ADD term {$$ = $1 + $3;}
    | expr OP_SUB term { $$ = $1 - $3;}
    | term {$$ = $1;}
;

term: term OP_MULT factor {$$ = $1 * $3;}
    | term OP_DIV factor {$$ = $1 / $3;}
    | factor
;

factor: LIT_NUM {$$ = $1;}
    | PAR_LEFT expr PAR_RIGHT {$$ = $2;}
;
%%