#include <stdio.h>
#include "tokens.h"
int yylex();
void initLexer(char *);

int main (int argc , char * args[]){
    if(argc != 2){
        fprintf(stderr, "%s , expects a file name\n", args[0]);
        return 1;
    }
    initLexer(args[1]);
    int token = yylex();
    while(token != TK_EOF){
        printf("Token : %d\n",token);
        token = yylex();
    }
    printf("The EOF Token : %d\n",token);
}