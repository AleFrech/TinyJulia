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
    int Index;
    BracketPostIdExpr(string id,int index){
        this->Id =id;
        this->Index =index;
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