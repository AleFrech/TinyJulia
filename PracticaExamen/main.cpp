#include <stdio.h>
int yyparse();
void initLexer(char *);

int main (int argc , char * args[]){
    if(argc != 2){
        fprintf(stderr, "%s , expects a file name\n", args[0]);
        return 1;
    }
    initLexer(args[1]);
    yyparse();
}