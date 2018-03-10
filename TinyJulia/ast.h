#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

enum primitiveType {
    INT_TYPE,
    BOOL_TYPE,
    ARRAY_INT_TYPE,
    ARRAY_BOOL_TYPE,
};

class BaseType {
public:
  primitiveType Type;
  BaseType(primitiveType type){
      this->Type = type;
  }
};

class IntType : public BaseType { 
public:
    int value;
    IntType(int value) : BaseType(INT_TYPE) { this->value = value; }
};

class BoolType : public BaseType { 
public:
    bool value;
    BoolType(bool value) : BaseType(BOOL_TYPE) { this->value = value; }
};

class ArrayIntType : public BaseType { 
public:
    vector<int> array;
    ArrayIntType() : BaseType(ARRAY_INT_TYPE) {  }
};

class ArrayBoolType : public BaseType { 
public:
    vector<int> array;
    ArrayBoolType() : BaseType(ARRAY_BOOL_TYPE) { }
};

enum ExprKind {
    TYPE,
    LIT_STRING
};

class Expr;
typedef list<Expr*> ExprList;


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

class ArrayExpr: public Expr{
public:
     ExprList * expressionList;
     ArrayExpr(ExprList * list){
         this->expressionList = list;
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


class ParamExpr: public Expr {
public:
    string Id;
    primitiveType Type;
    ParamExpr(string id, primitiveType type){
        this->Id = id;
        this->Type = type;
    }
    int getKind(){return TYPE;}
};


class Statement {
public:
    virtual void execute() = 0;
};


class BreakStatement : public Statement{
public:
    BreakStatement(){}
    void execute();
};

class ContinueStatement : public Statement{
public:
    ContinueStatement(){}
    void execute();
};

class ReturnStatement : public Statement {
public:
    Expr* exp;
    ReturnStatement(Expr* expr){
	this->exp = expr;
    }
    void execute();
};

class FunctionStatement: public Statement {
public:
    string Id;
    ExprList * expList;
    primitiveType Type;
    Statement * Block;
    FunctionStatement(string id,ExprList * expList,primitiveType type, Statement * block){
        this->Id = id;
        this->Type = type;
        this->expList = expList;
        this->Block = block;
    }
    void execute();
};

class DeclarationStatement: public Statement {
public:
    string Id;
    Expr* expr;
    primitiveType Type;
    DeclarationStatement(string id,primitiveType type,Expr* exp){
        this->Id = id;
        this->Type = type;
        this->expr = exp;
    }
    void execute();
};

class BlockStatement: public Statement {
public:
    list<Statement *> stList;
    BlockStatement() {}
    void execute();
	void add(Statement *st) { stList.push_back(st); }
};

class IfStatement: public Statement {
public:
    Expr * exp;
    Statement * ifBody;
    Statement * elseBody;
    IfStatement(Expr * exp , Statement * ifBody, Statement * elseBody){
        this->exp = exp;
        this->ifBody = ifBody;
        this->elseBody = elseBody;
    }
    void execute();
};

class ForStatement: public Statement {
public:
    string Id;
    Expr* to;
    Expr* from;
    Statement* blockStatement;
    ForStatement(string id, Expr* to, Expr* from, Statement* blockStatement){
        this->Id = id;
        this->to = to;
        this->from = from;
        this->blockStatement = blockStatement;

    }
    void execute();
};


class WhileStatement: public Statement {
public:
    Expr* expr;
    Statement * blockStatement;
    WhileStatement(Expr* exp, Statement* blockSt){
        this->expr=exp;
        this->blockStatement = blockSt;
    }
    void execute();
};

class ExprStatement: public Statement {
public:
    Expr * expr;
    ExprStatement(Expr * expr){
        this->expr=expr;
    }
    void execute();
};

class PrintStatement: public Statement {
public:
    ExprList * exprList;
    bool hasNewLine;
    PrintStatement( ExprList * exprList, bool hasNewLine) { 
        this->exprList = exprList;
        this->hasNewLine = hasNewLine; 
    }
    void execute();
   
};

#endif
