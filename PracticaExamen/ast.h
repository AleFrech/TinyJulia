#ifndef _AST_H
#define _AST_H
#include <list>
#include <string>
#include <map>
using namespace std;

class AstNode {

};

class Expr : public AstNode {
    public:
        virtual int evaluate()=0;
        virtual ~Expr(){};
        virtual kind getKind()=0;
};

class BinaryExpr : public Expr {
    public:
        Expr * expr1;
        Expr * expr2;
        BinaryExpr(Expr * e1,Expr * e2){
            this->expr1 = e1;
            this->expr2 = e2;
        }
        ~BinaryExpr();

};

#endif