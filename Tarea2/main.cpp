#include <stdio.h>
#include "parser.h"
extern int expr();
extern int yylex();
int token;
int main(){
    auto *parser = new Parser();
    token = yylex();
    auto st = parser->parse();
    st->execute();
    for(auto var :variables){
        printf("%s = %d\n",var->first,var->second);
    }
}