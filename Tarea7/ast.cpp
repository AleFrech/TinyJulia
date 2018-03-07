#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include "ast.h"

using namespace std;

set<string> variables;
static int tmp_offset =4;
static int labelCount = 0;

void registerVariable(string varName) {
	variables.insert(varName);
}

void genDataSection() {
	cout<<endl;
	cout << "section .data" << endl;
	cout << "format db \"%d \", 10, 0"<< endl;

	for (auto &var : variables) {
		cout << var << " dd 0" << endl;
	}
}

string newLabel() {
	string label = ".L" + to_string(labelCount);
	labelCount++;

	return label;
}

void resetOffset(){
	tmp_offset = 4;
}

static string newTemp() {
	string temp = "DWORD[ebp - " + to_string(tmp_offset) + "]";
	tmp_offset += 4;
	return temp;
}

static void releaseTemp(string temp) {
	
}

void AddExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	ctx.isConstant = false;
	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue + ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else if (ctx2.isConstant) {
		ctx.code = ctx1.code + "\n";
		ctx.place = newTemp();
	    ctx.code += "mov eax, " + ctx1.place+"\n"+
		"add eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else if (ctx1.isConstant) {
		ctx.code = ctx2.code + "\n";
		ctx.place = newTemp();
		ctx.code += "mov eax, " + ctx1.place+"\n"+
		"add eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else {
		ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
		ctx.place = newTemp();
	    ctx.code += "mov eax, " + ctx1.place+"\n"+
		"add eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	}
}

void SubExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	ctx.isConstant = false;
	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue - ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else if (ctx2.isConstant) {
		ctx.code = ctx1.code + "\n";
		ctx.place = newTemp();
	    ctx.code += "mov eax, " + ctx1.place+"\n"+
		"sub eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else if (ctx1.isConstant) {
		ctx.code = ctx2.code + "\n";
		ctx.place = newTemp();
		ctx.code += "mov eax, " + ctx1.place+"\n"+
		"sub eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else {
		ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
		ctx.place = newTemp();
	    ctx.code += "mov eax, " + ctx1.place+"\n"+
		"sub eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	}
}

void MulExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue * ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
	    ctx.place = newTemp();
		ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
		ctx.code += "mov ecx,"+ctx2.place+"\ncdq\n";
	    ctx.code += "imul ecx\n";
	    ctx.code += "mov " + ctx.place+", eax";
		ctx.isConstant = false;
	}
}

void DivExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue / ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
	    ctx.place = newTemp();
	   	ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
		ctx.code += "mov ecx,"+ctx2.place+"\ncdq\n";
	    ctx.code += "idiv ecx\n";
	    ctx.code += "mov " + ctx.place+", eax";
		ctx.isConstant = false;
	}
}

void IdExpr::genCode(ExprContext &ctx) {
    ctx.place = newTemp();
    ctx.code = "mov eax, DWORD[" + varName+"]\n"+
	"mov " + ctx.place + ", eax";
	ctx.isConstant = false;
}

void NumExpr::genCode(ExprContext &ctx) {
	ctx.numberValue = atoi(numStr.c_str());
	ctx.place = numStr;
	ctx.isConstant = true;
    ctx.code = "";
}

// Statement code generation
string AssignStatement::genCode() {
	stringstream ss;
	ExprContext ctx;

	expr->genCode(ctx);
	registerVariable(varName);
	ss << ctx.code << endl
	<< "mov eax, " << ctx.place << endl
    << "mov DWORD[" << varName << "], eax";
	return ss.str();
}

string PrintStatement::genCode() {
	stringstream ss;
	ExprContext ctx;

	expr->genCode(ctx);

	ss << ctx.code << endl
	   << "push " << ctx.place << endl
	   << "push format" <<endl
	   << "call printf"<<endl
	   << "add esp, 8"<<endl;

	return ss.str();
}

string IfStatement::genCode() {
	stringstream ss;
	ExprContext ctx;

	expr->genCode(ctx);

	string labelFalse = newLabel();
	string labelEndIf = newLabel();

	ss << ctx.code << endl
	   << "beqz " << ctx.place << ", " << labelFalse << endl
	   << st1->genCode() << endl
	   << "j " << labelEndIf << endl
	   << labelFalse << ":" << endl;

	if (st2 != NULL) {
		ss << st2->genCode();
	}
	ss << labelEndIf << ":";

	return ss.str();
}

string WhileStatement::genCode() {
	stringstream ss;
	ExprContext ctx;

	expr->genCode(ctx);

	string labelWhile = newLabel();
	string labelEndW = newLabel();

	ss << labelWhile << ":" << endl
	   << ctx.code << endl
	   << "beqz " << ctx.place << ", " << labelEndW << endl
	   << st->genCode() << endl
	   << "j " << labelWhile << endl
	   << labelEndW << ":";

	return ss.str();
}

string BlockStatement::genCode() {
	stringstream ss;

	for (Statement *st : statementList) {
		ss << st->genCode() << endl;
	}

	return ss.str();
}
