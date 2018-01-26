#ifndef _PARSER_H
#define _PARSER_H
#include "tokens.h"
#include "ast.h"
extern int yylex();
extern char *yytext;

class Parser{
    public:
        Parser(){
            token = yylex();
        }
        Statement* Parse();
    private:
        int token;
        Statement* Code();
        BlockStatement* StatementListFunction();
        Statement * StatementFunction();
        Statement * AssignStatementFunction();
        Expr* Expression();
        Expr* EPrime(Expr* param);
        Expr* Term();
        Expr* TPrime(Expr* param);
        Expr* Factor();
};

#endif