#include "ast.h"

map<string ,BaseType> variables;

void BreakStatement::execute(){

}

void ContinueStatement::execute(){

}

void BlockStatement::execute()
{
    for (auto st : stList){
        st->execute();
    }
}

void ExprStatement::execute(){
    
}

void WhileStatement::execute(){
    
}

void ForStatement::execute(){

}

void IfStatement::execute(){

}

void FunctionStatement::execute(){

}

void DeclarationStatement::execute(){

}

void PrintStatement::execute()
{
    for(auto expr : *this->exprList){
        if (expr->getKind() == ExprKind::LIT_STRING) {
            printf("%s", ((StringExpr*)expr)->str.c_str());
        }
    }
    if(hasNewLine)
        printf("\n");
}