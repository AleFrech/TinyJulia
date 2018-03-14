#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;

enum primitiveType {
    INT_TYPE,
    BOOL_TYPE,
    ARRAY_INT_TYPE,
    ARRAY_BOOL_TYPE,
};

struct ExprContext {
    string code;
    string place;
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
    virtual void genCode(ExprContext &ctx) = 0;
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
    void genCode(ExprContext &ctx);
    
};

// class TernaryExpr : public Expr {
// public:
//     Expr* exp;
//     Expr* trueExp;
//     Expr* falseExp;
//     TernaryExpr(Expr* exp ,Expr* trueExp, Expr* falseExp){
//         this->exp = exp;
//         this->trueExp = trueExp;
//         this->falseExp = falseExp;
//     }
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

class LogicalOrExpr : public BinaryExpr {
public:
    LogicalOrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class LogicalAndExpr : public BinaryExpr {
public:
    LogicalAndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

// class BitOrExpr : public BinaryExpr {
// public:
//     BitOrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

// class BitXorExpr : public BinaryExpr {
// public:
//     BitXorExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

// class BitAndExpr : public BinaryExpr {
// public:
//     BitAndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

class EqualExpr : public BinaryExpr {
public:
    EqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class NotEqualExpr : public BinaryExpr {
public:
    NotEqualExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class GreaterThanExpr : public BinaryExpr {
public:
    GreaterThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class LessThanExpr : public BinaryExpr {
public:
    LessThanExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};


class LessThanEqualsExpr : public BinaryExpr {
public:
    LessThanEqualsExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class GreaterThanEqualsExpr : public BinaryExpr {
public:
    GreaterThanEqualsExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class SubExpr : public BinaryExpr {
public:
    SubExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class AddExpr : public BinaryExpr {
public:
    AddExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

// class LeftShiftExpr : public BinaryExpr {
// public:
//     LeftShiftExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

// class RightShiftExpr : public BinaryExpr {
// public:
//     RightShiftExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

class MulExpr : public BinaryExpr {
public:
    MulExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class DivExpr : public BinaryExpr {
public:
    DivExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class ModExpr : public BinaryExpr {
public:
    ModExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class ExponentExpr : public BinaryExpr{
public:
    ExponentExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {}
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

// class UnaryAddExpr : public Expr{
// public:
//     Expr* expr;
//     UnaryAddExpr(Expr* expr){
//         this->expr = expr;
//     }
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

class UnarySubExpr : public Expr{
public:
    Expr* expr;
    UnarySubExpr(Expr* expr){
        this->expr = expr;
    }
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

// class UnaryDistintExpr : public Expr{
// public:
//     Expr* expr;
//     UnaryDistintExpr(Expr* expr){
//         this->expr = expr;
//     }
//     int getKind(){return TYPE;}
//     void genCode(ExprContext &ctx);
// };

// class UnaryNotExpr : public Expr{
// public:
//     Expr* expr;
//     UnaryNotExpr(Expr* expr){
//         this->expr = expr;
//     }
//     int getKind(){return TYPE;}
// };

class ParenthesisPosIdExpr: public Expr{
public:
    string Id;
    ExprList * expressionList;
    ParenthesisPosIdExpr(string id){
        this->Id = id;
        this->expressionList = new list<Expr*>;
    }
    ParenthesisPosIdExpr(string id, ExprList * exprList){
        this->Id = id;
        this->expressionList = exprList;
    }
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);


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
    void genCode(ExprContext &ctx);

};

class ArrayExpr: public Expr{
public:
     ExprList * expressionList;
     ArrayExpr(ExprList * list){
         this->expressionList = list;
     }
     int getKind(){return TYPE;}
     void genCode(ExprContext &ctx);
};

class BoolExpr : public Expr{
public:
    bool value;
    BoolExpr(bool value){
        this->value = value;
    }
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class NumberExpr : public Expr {
public:
    NumberExpr(int value) { this->value = value; }
    int value;
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class VarExpr: public Expr{
public:
    string  Id;
    VarExpr(string  id) { this->Id = id; }
    int getKind(){return TYPE;}
    void genCode(ExprContext &ctx);
};

class StringExpr: public Expr {
public:
    string str;
    StringExpr(string str) { 
        
        this->str = str;
    }
    int getKind() {return LIT_STRING; }
    void genCode(ExprContext &ctx);

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
    void genCode(ExprContext &ctx);
};


class Statement {
public:
    virtual string genCode() = 0;
};


class BreakStatement : public Statement{
public:
    BreakStatement(){}
    string genCode();
};

class ContinueStatement : public Statement{
public:
    ContinueStatement(){}
    string genCode();
};

class ReturnStatement : public Statement {
public:
    Expr* exp;
    ReturnStatement(Expr* expr){
	this->exp = expr;
    }
    string genCode();
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
    string genCode();
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
    string genCode();
};

class BlockStatement: public Statement {
public:
    list<Statement *> stList;
    BlockStatement() {}
    string genCode();
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
    string genCode();
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
    string genCode();
};


class WhileStatement: public Statement {
public:
    Expr* expr;
    Statement * blockStatement;
    WhileStatement(Expr* exp, Statement* blockSt){
        this->expr=exp;
        this->blockStatement = blockSt;
    }
    string genCode();
};

class ExprStatement: public Statement {
public:
    Expr * expr;
    ExprStatement(Expr * expr){
        this->expr=expr;
    }
    string genCode();
};

class PrintStatement: public Statement {
public:
    ExprList * exprList;
    bool hasNewLine;
    PrintStatement( ExprList * exprList, bool hasNewLine) { 
        this->exprList = exprList;
        this->hasNewLine = hasNewLine; 
    }
    string genCode();
   
};


void genDataSection();
void genFunctionSection();

#endif
