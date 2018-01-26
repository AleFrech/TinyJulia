#include "ast.h"
#include <stdio.h>
using namespace std;
map<string , int> variables;

int AddExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1+v2;
}

int SubExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1-v2;
}

int MulExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1*v2;
}

int DivExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1/v2;
}

int VarExpr::evaluate(){
    return variables[this->Id];
}

void AssignStatement::execute(){
    variables[var]=this->expr->evaluate();
}

void BlockStatement::execute(){
    for(auto st:statementList){
        st->execute();
    }
}


