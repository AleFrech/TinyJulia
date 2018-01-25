#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
int term();
int factor();
extern char *yytext;
extern int token;

/*
    E -> TE`

    E' -> +TE'
        ~e


    T -> FT'
    
    T' -> *FT'
        ~e

    F -> num
        (E)
*/

int expr()
{
    int result = term();
    if (token != OP_ADD && token != OP_SUB)
        return result;

    if (token == OP_ADD)
    {
        token = yylex();
        return result + expr();
    }
    if (token == OP_SUB)
    {
        token = yylex();
        return result - expr();
    }
}

int term()
{
    int result = factor();
    if (token != OP_MULT && token != OP_DIV)
        return result;
    if (token == OP_MULT)
    {
        token = yylex();
        return result * term();
    }
    if (token == OP_DIV)
    {
        token = yylex();
        return result / term();
    }
}

int factor()
{
    if (token == LIT_NUM)
    {
        int result = atoi(yytext);
        token = yylex();
        return result;
    }
    if (token == PAR_LEFT)
    {
        token = yylex();
        int result = expr();
        if (token != PAR_RIGHT)
        {
            printf("Error Expected ) found:%s", yytext);
            exit(-1);
        }
        token = yylex();
        return result;
    }
    printf("Error Expected NUM or ) found:%s", yytext);
}
