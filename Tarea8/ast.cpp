#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include "ast.h"

using namespace std;

set<string> variables;
set<string> fucntion_codes;
static int tmp_offset =4;
map<int, bool> tempInUse;
static int labelCount = 0;
static string currentContext ="";

void registerVariable(string varName) {
	variables.insert(currentContext+varName);
}

string getVariable(string varName){
	auto var = currentContext+varName;
	if(variables.find(var)!= variables.end())
		return var;
	else
		return varName;
}

void genDataSection() {
	cout<<endl;
	cout << "section .data" << endl;
	cout << "formatln db \"%d \", 10, 0"<< endl;
	cout << "format db \"%d \", 0"<< endl;

	for (auto &var : variables) {
		cout << var << " dd 0" << endl;
	}
}


void genFunctionSection(){
	cout<<endl;
	for (auto &fun : fucntion_codes) {
		cout << fun << endl;
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
	map<int, bool>::iterator it = tempInUse.begin();
	while (it != tempInUse.end()) {
		pair<int, bool> itm = *it;

		if (!itm.second) {
			tempInUse[itm.first] = true;
			return "DWORD[ebp - "+to_string(itm.first)+"]";
		}
		it++;
	}
	tempInUse[tmp_offset] = true;
	auto temp = "DWORD[ebp - "+to_string(tmp_offset)+"]";
	tmp_offset += 4;
	return temp;
}

static void releaseTemp(string temp) {
	map<int, bool>::iterator it = tempInUse.begin();
	while (it != tempInUse.end()) {
		pair<int, bool> itm = *it;

		auto str ="DWORD[ebp - "+to_string(itm.first)+"]";
		if(str == temp){
			tempInUse[itm.first] = false;
			return;
		}
		it++;
	}
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
		releaseTemp(ctx1.place);
		ctx.place = newTemp();
	    ctx.code += "mov eax, " + ctx1.place+"\n"+
		"add eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else if (ctx1.isConstant) {
		ctx.code = ctx2.code + "\n";
		releaseTemp(ctx2.place);
		ctx.place = newTemp();
		ctx.code += "mov eax, " + ctx1.place+"\n"+
		"add eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else {
		ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
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
		releaseTemp(ctx1.place);
		ctx.place = newTemp();
	    ctx.code += "mov eax, " + ctx1.place+"\n"+
		"sub eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else if (ctx1.isConstant) {
		ctx.code = ctx2.code + "\n";
		releaseTemp(ctx2.place);
		ctx.place = newTemp();
		ctx.code += "mov eax, " + ctx1.place+"\n"+
		"sub eax," + ctx2.place+"\n"+
		"mov "+ctx.place+", eax\n";
	} else {
		ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
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
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
		ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
		ctx.code += "mov ecx,"+ctx2.place+"\n";
	    ctx.code += "imul ecx\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
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
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
		ctx.code += "mov ecx,"+ctx2.place+"\n";
	    ctx.code += "idiv ecx\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
		ctx.isConstant = false;
	}
}

void ModExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue % ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
		ctx.code += "mov ecx,"+ctx2.place+"\n";
	    ctx.code += "idiv ecx\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", edx\n";
		ctx.isConstant = false;
	}
}

void EqualExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue == ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov ecx,"+ctx1.place+"\n";
		ctx.code += "mov edx,"+ctx2.place+"\n";
		ctx.code += "xor eax, eax\n";
	    ctx.code += "cmp ecx, edx\n";
		ctx.code += "sete al\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
		ctx.isConstant = false;
	}
}

void NotEqualExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue != ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov ecx,"+ctx1.place+"\n";
		ctx.code += "mov edx,"+ctx2.place+"\n";
		ctx.code += "xor eax, eax\n";
	    ctx.code += "cmp ecx, edx\n";
		ctx.code += "setne al\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
		ctx.isConstant = false;
	}
}

void LessThanExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue < ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov ecx,"+ctx1.place+"\n";
		ctx.code += "mov edx,"+ctx2.place+"\n";
		ctx.code += "xor eax, eax\n";
	    ctx.code += "cmp ecx, edx\n";
		ctx.code += "setl al\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
		ctx.isConstant = false;
	}
}

void LessThanEqualExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue <= ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov ecx,"+ctx1.place+"\n";
		ctx.code += "mov edx,"+ctx2.place+"\n";
		ctx.code += "xor eax, eax\n";
	    ctx.code += "cmp ecx, edx\n";
		ctx.code += "setle al\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
		ctx.isConstant = false;
	}
}

void GreaterThanExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue > ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov ecx,"+ctx1.place+"\n";
		ctx.code += "mov edx,"+ctx2.place+"\n";
		ctx.code += "xor eax, eax\n";
	    ctx.code += "cmp ecx, edx\n";
		ctx.code += "setg al\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
		ctx.isConstant = false;
	}
}

void GreaterThanEqualExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if (ctx1.isConstant && ctx2.isConstant) {
		ctx.numberValue = ctx1.numberValue >= ctx2.numberValue;
		ctx.place = to_string(ctx.numberValue);
		ctx.isConstant = true;
	} else {
		ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
		releaseTemp(ctx1.place);
		releaseTemp(ctx2.place);
	   	ctx.code += "mov ecx,"+ctx1.place+"\n";
		ctx.code += "mov edx,"+ctx2.place+"\n";
		ctx.code += "xor eax, eax\n";
	    ctx.code += "cmp ecx, edx\n";
		ctx.code += "setge al\n";
		ctx.place = newTemp();
	    ctx.code += "mov " + ctx.place+", eax\n";
		ctx.isConstant = false;
	}
}

void IdExpr::genCode(ExprContext &ctx) {
    ctx.place = newTemp();
    ctx.code = "mov eax, DWORD[" + getVariable(varName)+"]\n"+
	"mov " + ctx.place + ", eax\n";
	ctx.isConstant = false;
}

void FunctionCallExpr::genCode(ExprContext &ctx){
	this->expressionList->reverse();
	ExprContext tmpCtx;
	stringstream ss;
	for(auto e : *this->expressionList){
		e->genCode(tmpCtx);
		ss << tmpCtx.code
			<< "push "<< tmpCtx.place << endl;
	}
	releaseTemp(tmpCtx.place);
	ctx.place = newTemp();
	ss << "call " << this->varName << endl;
	ss << "add esp, "<<(4*(*this->expressionList).size()) << endl;
	ss << "mov " << ctx.place <<", eax" << endl;
	ctx.code = ss.str();
	releaseTemp(ctx.place);

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
	ss << ctx.code;
	ss << "mov eax, " << ctx.place << endl;
    ss << "mov DWORD[" << getVariable(varName) << "], eax\n";
	releaseTemp(ctx.place);
	return ss.str();
}

string PrintStatement::genCode() {
	stringstream ss;
	ExprContext ctx;

	expr->genCode(ctx);

	ss << ctx.code << endl
	   << "push " << ctx.place << endl;
	if(this->isNewLine){
		ss << "push formatln" <<endl;
	}else{
		ss << "push format" <<endl;
	}
	ss << "call printf"<<endl
	   << "add esp, 8"<<endl;
	releaseTemp(ctx.place);

	return ss.str();
}

string IfStatement::genCode() {
	stringstream ss;
	ExprContext ctx;

	expr->genCode(ctx);

	string labelFalse = newLabel();
	string labelEndIf = newLabel();

	ss << ctx.code << endl
	   << "mov eax, "<<ctx.place << endl
	   << "cmp eax , 0" << endl
	   << "jz "<<labelFalse << endl
	   << st1->genCode() << endl
	   << "jmp " << labelEndIf << endl
	   << labelFalse << ":" << endl;

	if (st2 != NULL) {
		ss << st2->genCode();
	}
	ss << labelEndIf << ":";

	releaseTemp(ctx.place);

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
	   << "mov eax, "<<ctx.place << endl
	   << "cmp eax , 0" << endl
	   << "jz "<<labelEndW << endl
	   << st->genCode() << endl
	   << "jmp " << labelWhile << endl
	   << labelEndW << ":";

	releaseTemp(ctx.place);

	return ss.str();
}

string FunctionStatement::genCode(){
	currentContext=this->id;
	stringstream ss;
	ss << currentContext << ":" << endl
	<< "push ebp"<<endl << "mov ebp, esp"<<endl;
	int i =0;
	for(string p : *params){
		registerVariable(p);
		ss << "mov eax, "<<  "DWORD [ebp+"<<(8+(i*4))<<"]"<<endl;
		ss << "mov DWORD ["<< getVariable(p) << "], eax"<<endl;
		i++;
	}	
	ss<< this->st->genCode() << endl
	<< "leave" <<endl
	<< "ret";
	currentContext="";
	fucntion_codes.insert(ss.str());
	return "";
}

string ReturnStatement::genCode(){
	stringstream ss;
	ExprContext ctx;
	this->expression->genCode(ctx);
	ss << ctx.code << endl
	<< "mov eax, " << ctx.place;
	releaseTemp(ctx.place);
	return ss.str();
}

string BlockStatement::genCode() {
	stringstream ss;

	for (Statement *st : statementList) {
		ss << st->genCode() << endl;
	}

	return ss.str();
}
