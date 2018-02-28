#include "ast.h"
#include "Types/BaseType.h"

map<string ,BaseType> variables;

void BlockStatement::execute()
{
    for (auto st : stList){
        st->execute();
    }
}

void ExprStatement::execute(){
    
}

void PrintStatement::execute()
{
    if (expr->getKind() == ExprKind::LIT_STRING) {
        printf("%s", ((StringExpr*)expr)->str.c_str());
    } 
    if(hasNewLine)
        printf("\n");
}