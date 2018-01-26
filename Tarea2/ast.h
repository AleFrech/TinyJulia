#ifndef _AST_H
#define _AST_H
#include <list>
#include <string>
#include <map>
using namespace std;

class Expr {
public:
    virtual int evaluate()=0;
};

class BinaryExpr : public Expr {
    protected:
        BinaryExpr(Expr *expr1, Expr *expr2) {
            this->expr1 = expr1;
            this->expr2 = expr2;
    }

    public:
        Expr *expr1, *expr2;
};

class AddExpr : public BinaryExpr {
    public:
        AddExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
};

class SubExpr : public BinaryExpr {
    public:
        SubExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
};


class MulExpr : public BinaryExpr {
    public:
        MulExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
};

class DivExpr : public BinaryExpr {
    public:
        DivExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
};

class NumberExpr : public Expr {
    public:
        NumberExpr(int value) { this->value = value; }
        int value;
        int evaluate(){
            return value;
        }
};

class VarExpr : public Expr {
public:
  VarExpr(string  id) { this->Id = id; }
  string  Id;
  int evaluate();
};

class Statement {
public:
    virtual void execute()=0;
};

class AssignStatement : public Statement{
public:
    AssignStatement(string var,Expr* expr){
        this->var=var;
        this->expr=expr;
    }
    void execute();
    string var;
    Expr * expr;
};

class BlockStatement : public Statement{
public:
    list<Statement*> statementList;
    BlockStatement(){}
    void addStatement(Statement * statement){
        statementList.push_back(statement);
    }
    void execute();


};

#endif