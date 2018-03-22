#include <stdio.h>
#include <iostream>
#include <string>
#include "ast.h"
int yyparse();
extern BlockStatement *statement;
extern vector<map<string,string>>$scopes;
void initLexer(char *);

int main (int argc , char * args[]){
    if(argc != 2){
        fprintf(stderr, "%s , expects a file name\n", args[0]);
        return 1;
    }
    initLexer(args[1]);
    $scopes.push_back(map<string,string>());
    yyparse();

    if (statement != NULL) {
            string code = statement->genCode();

            cout << "extern printf" << endl
                << "extern power" <<endl
                << "global main" << endl;
            genBssSection();
            genDataSection();
            cout << endl << "section .text" << endl;
            cout << "main:" <<endl
                 << "push ebp"<<endl << "mov ebp, esp"<<endl
                 << code
                 << "leave\nret\n";
            genFunctionSection();

    }
}