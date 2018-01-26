#ifndef _PARSER_H
#define _PARSER_H
#include "tokens.h"
#include "ast.h"
extern int yylex();
extern char *yytext;
extern int token;

class Parser{
    public:
        Statement* Parse(){
            Statement* code = Code();
            if (token != TK_EOF)
                throw invalid_argument("End of file expected");
            return code;
        }
    private:
        Statement* Code(){
            return StatementListFunction();
        }

        BlockStatement* StatementListFunction(){
            if (token != TK_ID)
            {
                auto st = StatementFunction();
                BlockStatement * stList = StatementListFunction();
                stList->addStatement(st);
                return stList;
            }
            else
            {
                return new BlockStatement();
            }
        }

        Statement* StatementFunction(){
            if (token == TK_ID)
            {
                return AssignStatementFunction();
            }
            else
            {
            throw invalid_argument("Statement expected found :"+string(yytext));
            }
        }


        Statement * AssignStatementFunction(){
            if(token != TK_ID)
                throw invalid_argument("Id expected found :"+string(yytext));
            string id = string(yytext);
            token = yylex();
            if (token != OP_ASG)
                throw invalid_argument("= expected found :"+string(yytext));
            token = yylex();
            auto Evalue = Expression();
            if (token != TK_EOS)
                throw invalid_argument("= expected found :"+string(yytext));
            token = yylex();
            return new AssignStatement(id, Evalue);
        }

        Expr* Expression(){
            auto Tvalue = Term();
            return EPrime(Tvalue);
        }

        Expr* EPrime(Expr* param){
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

        Expr* Term(){
            auto Fvalue = Factor();
            return TPrime(Fvalue);
        }

        Expr* TPrime(Expr* param){
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

        Expr* Factor(){
            if (token == PAR_LEFT)
            {
                token = yylex();
                auto Evalue = Expression();
                if (token != PAR_RIGHT)
                    throw invalid_argument(") expected found :"+string(yytext));
                token = yylex();
                return Evalue;
                
            }else if (token == LIT_NUM)
            {
                auto value = new NumberExpr(atoi(yytext));
                token = yylex();
                return value;

            }else if (token == TK_ID)
            {
                string id = string(yytext);
                token= yylex();
                return new VarExpr(id);
            }
            else
            {
                throw invalid_argument("Factor expected found :"+string(yytext));
            }
        }
};

#endif