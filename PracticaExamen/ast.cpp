#include "ast.h"
#include <iostream>
map<string,int> variables;


BinaryExpr::~BinaryExpr(){
    delete expr1;
    delete expr2;
}

int AddExpr::evaluate(){
    return expr1->evaluate() + expr2->evaluate();
}

int SubExpr::evaluate(){
    return expr1->evaluate() - expr2->evaluate();
}

int MultExpr::evaluate(){
    return expr1->evaluate() * expr2->evaluate();
}

int DivExpr::evaluate(){
    return expr1->evaluate() / expr2->evaluate();
}

int ModExpr::evaluate(){
    return expr1->evaluate() % expr2->evaluate();
}

int ExpExpr::evaluate(){
    return pow(expr1->evaluate(),expr2->evaluate());
}

int VarExpr::evaluate(){
    return variables[this->id];
}

void AssignStatement::execute(){
    variables[this->id] = this->value;
}

void PrintStatement::execute(){
    for(auto e : this->exprLsit){
        if(e->getType() == type::INT){
            printf("%d",e->evaluate());
        }else if(e->getType() == type::STRING){
            auto str = (StringExpr*)e;
            printf("%s",str->value.c_str());
        }else{
            auto chr = (CharExpr*)e;
            printf("%s",chr->value.c_str());
        }
    }
}


void BlockStatement::execute(){
    for(auto st :this->statementList){
        st->execute();
    }
}