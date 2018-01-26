#ifndef _PARSER_H
#define _PARSER_H
#include "tokens.h"
#include "ast.h"
extern int yylex();
extern char *yytext;
extern int token;

class Parser{
    public:
        Statement * Parse();
    private:
        BlockStatement * StatementListFunction();
        Statement * StatementFuntion();
        Statement * AssignStatementFunction();
        Expr * Expression();
        Expr * EPrime();
        Expr * Term();
        Expr * TPrime();
        Expr * Factor(); 
};

#endif