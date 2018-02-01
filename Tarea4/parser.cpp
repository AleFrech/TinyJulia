#include "ast.h"
#include "parser.h"
#include <stdio.h>
using namespace std;

Statement* Parser::Parse()
{
    Statement *code = Code();
    // if (token != TK_EOF){
    //     printf("%d\n",token);
    //     throw invalid_argument("End of file expected");
    // }
    return code;
}

Statement* Parser::Code()
{
    return StatementListFunction();
}

BlockStatement* Parser::StatementListFunction()
{
    if (token == TK_ID)
    {
        auto st = StatementFunction();
        BlockStatement *stList = StatementListFunction();
        stList->statementList.push_front(st);
        return stList;
    }
    else
    {
        return new BlockStatement();
    }
}

Statement* Parser::StatementFunction()
{
    if (token == TK_ID)
    {
        return AssignStatementFunction();
    }
    else
    {
        throw invalid_argument("Statement expected found :" + string(yytext));
    }
}

Statement* Parser::AssignStatementFunction()
{
    if (token != TK_ID)
        throw invalid_argument("Id expected found :" + string(yytext));
    string id = string(yytext);
    token = yylex();
    if (token != OP_ASG)
        throw invalid_argument("= expected found :" + string(yytext));
    token = yylex();
    auto Evalue = Expression();
    if (token != TK_EOS)
        throw invalid_argument("= expected found :" + string(yytext));
    token = yylex();
    return new AssignStatement(id, Evalue);
}

Expr* Parser::Expression()
{
    auto Tvalue = Term();
    return EPrime(Tvalue);
}

Expr* Parser::EPrime(Expr *param)
{
    if (token == OP_ADD)
    {
        token = yylex();
        auto Tvalue = Term();
        return EPrime(new AddExpr(param, Tvalue));
    }
    else if (token == OP_SUB)
    {
        token = yylex();
        auto Tvalue = Term();
        return EPrime(new SubExpr(param, Tvalue));
    }
    else
    {
        return param;
    }
}

Expr* Parser::Term()
{
    auto Fvalue = Factor();
    return TPrime(Fvalue);
}

Expr* Parser::TPrime(Expr *param)
{
    if (token == OP_MULT)
    {
        token = yylex();
        auto Fvalue = Factor();
        return EPrime(new MulExpr(param, Fvalue));
    }
    else if (token == OP_DIV)
    {
        token = yylex();
        auto Fvalue = Factor();
        return EPrime(new DivExpr(param, Fvalue));
    }
    else
    {
        return param;
    }
}

Expr* Parser::Factor()
{
    if (token == PAR_LEFT)
    {
        token = yylex();
        auto Evalue = Expression();
        if (token != PAR_RIGHT)
            throw invalid_argument(") expected found :" + string(yytext));
        token = yylex();
        return Evalue;
    }
    else if (token == LIT_NUM)
    {
        auto value = new NumberExpr(stoi(yytext));
        token = yylex();
        return value;
    }
    else if (token == TK_ID)
    {
        string id = string(yytext);
        token = yylex();
        return new VarExpr(id);
    }
    else
    {
        throw invalid_argument("Factor expected found :" + string(yytext));
    }
}