#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <map>
using namespace std;

class Expr;
typedef list<Expr*> ExprList;

enum ExprKind {
    TYPE,
    LIT_STRING
};

class Expr {
public:
    virtual int getKind() = 0;
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

class AssignExpr : public Expr {
public:
    Expr* left;
    Expr* right;
    AssignExpr(Expr* exp1, Expr* exp2){
        this->left = exp1;
        this->right = exp2;
    }
    int getKind(){return TYPE;}
    
};

class TernaryExpr : public Expr {
public:
    Expr* exp;
    Expr* trueExp;
    Expr* falseExp;
    TernaryExpr(Expr* exp ,Expr* trueExp, Expr* falseExp){
        this->exp = exp;
        this->trueExp = trueExp;
        this->falseExp = falseExp;
    }
    int getKind(){return TYPE;}
};

class LogicalOrExpr : public BinaryExpr {
public:
    LogicalOrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class LogicalAndExpr : public BinaryExpr {
public:
    LogicalAndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class BitOrExpr : public BinaryExpr {
public:
    BitOrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class BitXorExpr : public BinaryExpr {
public:
    BitXorExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class BitAndExpr : public BinaryExpr {
public:
    BitAndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class EqualExpr : public BinaryExpr {
public:
    EqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class NotEqualExpr : public BinaryExpr {
public:
    NotEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class GreaterThanExpr : public BinaryExpr {
public:
    GreaterThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class LessThanExpr : public BinaryExpr {
public:
    LessThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};


class LessThanEqualsExpr : public BinaryExpr {
public:
    LessThanEqualsExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class GreaterThanEqualsExpr : public BinaryExpr {
public:
    GreaterThanEqualsExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class SubExpr : public BinaryExpr {
public:
    SubExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class AddExpr : public BinaryExpr {
public:
    AddExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class LeftShiftExpr : public BinaryExpr {
public:
    LeftShiftExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class RightShiftExpr : public BinaryExpr {
public:
    RightShiftExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class MulExpr : public BinaryExpr {
public:
    MulExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class DivExpr : public BinaryExpr {
public:
    DivExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class ModExpr : public BinaryExpr {
public:
    ModExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class ExponentExpr : public BinaryExpr{
public:
    ExponentExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
};

class UnaryAddExpr : public Expr{
public:
    Expr* expr;
    UnaryAddExpr(Expr* expr){
        this->expr = expr;
    }
    int getKind(){return TYPE;}
};

class UnarySubExpr : public Expr{
public:
    Expr* expr;
    UnarySubExpr(Expr* expr){
        this->expr = expr;
    }
    int getKind(){return TYPE;}
};

class UnaryDistintExpr : public Expr{
public:
    Expr* expr;
    UnaryDistintExpr(Expr* expr){
        this->expr = expr;
    }
    int getKind(){return TYPE;}
};

class UnaryNotExpr : public Expr{
public:
    Expr* expr;
    UnaryNotExpr(Expr* expr){
        this->expr = expr;
    }
    int getKind(){return TYPE;}
};

class ParenthesisPosIdExpr: public Expr{
public:
    string Id;
    ExprList * expressionList;
    ParenthesisPosIdExpr(string id){
        this->Id = id;
        this->expressionList = NULL;
    }
    ParenthesisPosIdExpr(string id, ExprList * exprList){
        this->Id = id;
        this->expressionList = exprList;
    }
    int getKind(){return TYPE;}


};

class BracketPostIdExpr : public Expr{
public:
    string Id;
    Expr* Index;
    BracketPostIdExpr(string id,Expr* index){
        this->Id =id;
        this->Index =index;
    }
    int getKind(){return TYPE;}

};

class BoolExpr : public Expr{
public:
    bool value;
    BoolExpr(bool value){
        this->value = value;
    }
    int getKind(){return TYPE;}
};

class NumberExpr : public Expr {
public:
    NumberExpr(int value) { this->value = value; }
    int value;
    int getKind(){return TYPE;}
};

class VarExpr: public Expr{
public:
    string  Id;
    VarExpr(string  id) { this->Id = id; }
    int getKind(){return TYPE;}
};

class StringExpr: public Expr {
public:
    string str;
    StringExpr(string str) { 
        this->str = str;
    }
    int getKind() { return LIT_STRING; }
};


class Statement {
public:
    virtual void execute() = 0;
};

class BlockStatement: public Statement {
public:
    list<Statement *> stList;
    BlockStatement() {}
    void execute();
	void add(Statement *st) { stList.push_back(st); }
};

class PrintStatement: public Statement {
public:
    Expr* expr;
    bool hasNewLine;
    PrintStatement(Expr* expr , bool hasNewLine) { 
        this->expr = expr;
        this->hasNewLine = hasNewLine; 
    }
    void execute();
   
};

#endif