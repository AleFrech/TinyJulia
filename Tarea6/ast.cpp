#include "ast.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
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
    value = value.substr(1, value.size() - 2);
    auto charIndex = value.find("\\n");
    string newline = "\n";
    while(charIndex!=string::npos){
        value.replace(charIndex,2,newline);
        charIndex = value.find("\\n");
    }
    charIndex = value.find("\\\"");
    while(charIndex!=string::npos){
        value.replace(charIndex,2,"\"");
        charIndex = value.find("\\\"");
    }
    return value;
}

string InputExpr::getvalue(){
    value = value.substr(1, value.size() - 2);
    auto charIndex = value.find("\\n");
    string newline = "\n";
    while(charIndex!=string::npos){
        value.replace(charIndex,2,newline);
        charIndex = value.find("\\n");
    }
    charIndex = value.find("\\\"");
    while(charIndex!=string::npos){
        value.replace(charIndex,2,"\"");
        charIndex = value.find("\\\"");
    }
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
    while(1){
        int con = this->condtion->evaluate();
        if(con)
            this->blockstatement->execute();
        else
            break;
    } 
}