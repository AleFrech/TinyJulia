#include "ast.h"

void BlockStatement::execute()
{
    for (auto st : stList){
        st->execute();
    }
}

void PrintStatement::execute()
{
    if (expr->getKind() == ExprKind::LIT_STRING) {
        printf("%s", ((StringExpr*)expr)->str.c_str());
    } else {
      int result = expr->evaluate();
      printf("%d", result);
    }
    if(hasNewLine)
        printf("\n");
}