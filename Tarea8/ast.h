#ifndef _AST_H
#define _AST_H

#include <string>
#include <list>

using namespace std;

struct ExprContext {
    string code;
    string place;
	int numberValue;
	bool isConstant;
};

#define DEFINE_BINARY_EXPR(name) \
	class name##Expr: public BinaryExpr { \
	public:								  \
		name##Expr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {} \
		void genCode(ExprContext &ctx);		\
	}

class Expr;
typedef list<Expr*> ExprList;

class Expr {
public:
	virtual void genCode(ExprContext &ctx) = 0;
};

class BinaryExpr: public Expr {
protected:
	BinaryExpr(Expr *expr1, Expr *expr2) {
		this->expr1 = expr1;
		this->expr2 = expr2;
	}
public:
	Expr *expr1, *expr2;
};

DEFINE_BINARY_EXPR(Add);
DEFINE_BINARY_EXPR(Sub);
DEFINE_BINARY_EXPR(Mul);
DEFINE_BINARY_EXPR(Div);
DEFINE_BINARY_EXPR(Mod);
DEFINE_BINARY_EXPR(Equal);
DEFINE_BINARY_EXPR(NotEqual);
DEFINE_BINARY_EXPR(GreaterThan);
DEFINE_BINARY_EXPR(GreaterThanEqual);
DEFINE_BINARY_EXPR(LessThan);
DEFINE_BINARY_EXPR(LessThanEqual);

class NumExpr: public Expr {
public:
	NumExpr(string numStr) {
		this->numStr = numStr;
	}

    void genCode(ExprContext &ctx);

	string numStr;
};

class IdExpr: public Expr {
public:
	IdExpr(string varName) {
		this->varName = varName;
	}

	void genCode(ExprContext &ctx);

	string varName;
};

class FunctionCallExpr: public Expr{
public:
    string varName;
    ExprList * expressionList;
    FunctionCallExpr(string varName){
        this->varName = varName;
        this->expressionList = new ExprList;
    }
    FunctionCallExpr(string varName, ExprList * exprList){
        this->varName = varName;
        this->expressionList = exprList;
    }
	void genCode(ExprContext &ctx);
};


class Statement {
public:
	virtual string genCode() = 0;
};

class AssignStatement: public Statement {
public:
	AssignStatement(string varName, Expr *expr) {
		this->varName = varName;
		this->expr = expr;
	}

	string genCode();

	string varName;
	Expr *expr;
};

class PrintStatement: public Statement {
public:
	PrintStatement(Expr *expr, bool newLine) {
		this->expr = expr;
		this->isNewLine = newLine;
	}

	string genCode();
	bool isNewLine;
	Expr *expr;
};

class IfStatement: public Statement {
public:
	IfStatement(Expr *expr, Statement *st_true, Statement *st_false) {
		this->expr = expr;
		this->st1 = st_true;
		this->st2 = st_false;
	}

	string genCode();

	Expr *expr;
	Statement *st1;
	Statement *st2;
};

class WhileStatement: public Statement {
public:
	WhileStatement(Expr *expr, Statement *st) {
		this->expr = expr;
		this->st = st;
	}

	string genCode();

	Expr *expr;
	Statement *st;
};

class ReturnStatement: public Statement {
public:
	ReturnStatement(Expr * expression){
		this->expression = expression;
	}

	string genCode();

	Expr* expression;
};

class FunctionStatement: public Statement {
public:
	FunctionStatement(string id, list<string>* params, Statement* st){
		this->id=id;
		this->params =params;
		this->st = st;
	}
	string genCode();
	string id;
	list<string>*  params;
	Statement *st;
};

class BlockStatement: public Statement {
public:
	BlockStatement() {}

	void addStatement(Statement *statement) {
		statementList.push_back(statement);
	}

	string genCode();

	list<Statement*> statementList;
};

void tempInit();
void genDataSection();
void genFunctionSection();
#endif
