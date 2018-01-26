#include <stdio.h>
extern int expr();
extern int yylex();
int token;
int main(){
    token = yylex();
    printf("Result :%d",expr());
}