#include "ast.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
map<string , int> variables;


void myReplace(string &str, string toReplace,string replaced,int size ){
    auto charIndex = str.find(toReplace);
    while(charIndex!=string::npos){
        str.replace(charIndex,size,replaced);
        charIndex = str.find(toReplace);
    }
}

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

int ModExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1%v2;
}

int EqualExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1==v2;
}

int NotEqualExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1!=v2;
}

int LessThanExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1<v2;
}

int LessThanEqualExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1<=v2;
}

int GreaterThanExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1>v2;
}

int GreaterThanEqualExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return v1>=v2;
}


int PowExpr::evaluate(){
    int v1=expr1->evaluate();
    int v2=expr2->evaluate();

    return pow(v1,v2);
}

int VarExpr::evaluate(){
    return variables[this->Id];
}

string StringExpr::getValue(){
    myReplace(value,"\"","",1);
    myReplace(value,"\\n","\n",2);
    myReplace(value,"\\\"","\"",2);
    return value;
}

string InputExpr::getvalue(){
    myReplace(value,"\"","",1);
    myReplace(value,"\\n","\n",2);
    myReplace(value,"\\\"","\"",2);
    return value;
}

int InputExpr::evaluate(){
    cout<<this->getvalue();
    int x=0;
    cin>>x;
    return x;
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
}

BlockStatement:: ~BlockStatement(){
    for(auto st : statementList){
        delete st;
    }
}

void PrintStatement::execute(){
    for(auto expr : *exprList){
        if(expr->getKind() == Kind::INTEGER){
            cout<<expr->evaluate()<<endl;
        }else{  
            auto str =((StringExpr*)expr)->getValue();
            cout<<str;
        }
    }
 }


void WhileStatement::execute(){
    while(this->condition->evaluate())
    {
        this->blockstatement->execute();
    }
}

void IfStatement::execute(){
    if(this->condition->evaluate() == 1){
        this->trueList->execute();
    }else if(this->falseList!=NULL){
        this->falseList->execute();
    }
}

void ForStatement::execute(){
    variables[this->id] = this->begin->evaluate();
    while(variables[this->id] < this->end->evaluate()){
        statementList->execute();
        variables[this->id]++;
    }    
}