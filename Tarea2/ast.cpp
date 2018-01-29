#include "ast.h"
#include <stdio.h>
#include <iostream>
using namespace std;
map<string , int> variables;

BinaryExpr::~BinaryExpr(){
    delete expr1;
    delete expr2;
}

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

AssignStatement:: ~AssignStatement(){
    delete expr;
}

void BlockStatement::execute(){
    for(auto st : statementList){
        st->execute();
    }
    for(auto var : variables){
        cout<<var.first << " = " << var.second<<endl; 
    }
}

BlockStatement:: ~BlockStatement(){
    for(auto st : statementList){
        delete st;
    }
}

