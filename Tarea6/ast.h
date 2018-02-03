#ifndef _AST_H
#define _AST_H
#include <list>
#include <string>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

enum class Kind {INTEGER,STRING};

class Expr {
    public:
        virtual int evaluate()=0;
        virtual ~Expr() {};
        virtual Kind getKind()=0;
};

class BinaryExpr : public Expr {
    protected:
        BinaryExpr(Expr *expr1, Expr *expr2) {
            this->expr1 = expr1;
            this->expr2 = expr2;
    }

    public:
        Expr *expr1, *expr2;
        ~BinaryExpr();
};

class AddExpr : public BinaryExpr {
    public:
        AddExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class SubExpr : public BinaryExpr {
    public:
        SubExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};


class MulExpr : public BinaryExpr {
    public:
        MulExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class DivExpr : public BinaryExpr {
    public:
        DivExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class ModExpr : public BinaryExpr {
    public:
        ModExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class PowExpr : public BinaryExpr {
    public:
        PowExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class EqualExpr : public BinaryExpr {
    public:
        EqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class NotEqualExpr : public BinaryExpr {
    public:
        NotEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class LessThanExpr : public BinaryExpr {
    public:
        LessThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class GreaterThanEqualExpr : public BinaryExpr {
    public:
        GreaterThanEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class LessThanEqualExpr : public BinaryExpr {
    public:
        LessThanEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class GreaterThanExpr : public BinaryExpr {
    public:
        GreaterThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};


class NumberExpr : public Expr {
    public:
        NumberExpr(int value) { this->value = value; }
        int value;
        int evaluate(){
            return value;
        }
        Kind getKind(){return Kind::INTEGER;}
};

class StringExpr : public Expr {
    public:
        StringExpr(string value) { 
            this->value = value;
        }
        string value;
        int evaluate(){
            return 0;
        }
        string getValue();
        Kind getKind(){return Kind::STRING;}
};

class InputExpr : public Expr{
    public:
        InputExpr(string value) {this->value=value;}
        string value;
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
        string getvalue();
};

class VarExpr : public Expr {
    public:
        VarExpr(string  id) { this->Id = id; }
        string  Id;
        int evaluate();
        Kind getKind(){return Kind::INTEGER;}
};

class Statement {
    public:
        virtual void execute()=0;
        virtual ~Statement(){}; 
};

class AssignStatement : public Statement{
public:
    AssignStatement(string var,Expr* expr){
        this->var=var;
        this->expr=expr;
    }
    void execute();
    ~AssignStatement();
    string var;
    Expr * expr;
};

class PassStatement : public Statement{
public:
    PassStatement()=default;
    void execute(){
        return;
    }
};

class PrintStatement : public Statement{
public:
    list<Expr*> *exprList;
    PrintStatement(list<Expr*> *exprList){
        this->exprList = exprList;
    }
    void execute();
};

class WhileStatement : public Statement{
public:
    Expr* condtion;
    Statement * blockstatement;
    WhileStatement(Expr* con , Statement* block){
        this->condtion = con;
        this->blockstatement = block;
    }
    void execute();
};

class BlockStatement : public Statement{
public:
    BlockStatement()=default;
    list<Statement*> statementList;
    ~BlockStatement();
    void execute();
};

#endif