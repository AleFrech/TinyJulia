#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <map>
using namespace std;

class Expr;
typedef list<Expr*> ExprList;

enum ExprKind {
    NUM,
    BOOL,
    LIT_STRING
};

class Expr {
public:
    virtual int evaluate() = 0;
    virtual int getKind() = 0;
};

class StringExpr: public Expr {
public:
    string str;
    StringExpr(string str) { 
        this->str = str;
    }
    int evaluate() { return 0; }
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