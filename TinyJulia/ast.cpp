#include "ast.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
map<string ,BaseType> variables;
map<string ,string> stringLiterals;
static int tmp_offset =4;
static int labelCount = 0;
static int literalCount =0;
map<int, bool> tempInUse;
static string currentContext ="";

void genDataSection() {
	cout<<endl;
	cout << "section .data" << endl;
	cout << "formatln db \"%d \", 10, 0"<< endl;
	cout << "format db \"%d \", 0"<< endl;
    cout << "formatStringln db \"%s \", 10, 0"<< endl;
	cout << "formatString db \"%s \", 0"<< endl;

    for(auto &lit : stringLiterals){
        cout << lit.first << lit.second << endl;
    }

	for (auto &var : variables) {
		cout << var.first << " dd 0" << endl;
	}
}

string newTemp() {
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

 void releaseTemp(string temp) {
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

string newLabel() {
	string label = ".L" + to_string(labelCount);
	labelCount++;

	return label;
}

string newLiteral() {
    string literal = "literal" + to_string(literalCount);
    literalCount++;
    return literal;
}

void AddExpr::genCode(ExprContext &ctx) {

}

void SubExpr::genCode(ExprContext &ctx) {

}

void MulExpr::genCode(ExprContext &ctx) {

}

void DivExpr::genCode(ExprContext &ctx) {

}

void ModExpr::genCode(ExprContext &ctx) {

}

void ExponentExpr::genCode(ExprContext &ctx) {

}

void UnarySubExpr::genCode(ExprContext &ctx) {

}

void ParenthesisPosIdExpr::genCode(ExprContext &ctx) {

}

void BracketPostIdExpr::genCode(ExprContext &ctx) {

}

void ArrayExpr::genCode(ExprContext &ctx) {

}

void BoolExpr::genCode(ExprContext &ctx) {

}

void StringExpr::genCode(ExprContext &ctx) {

}

void NumberExpr::genCode(ExprContext &ctx) {

}

void VarExpr::genCode(ExprContext &ctx) {

}

void ParamExpr::genCode(ExprContext &ctx) {

}

void LessThanEqualsExpr::genCode(ExprContext &ctx) {

}

void LessThanExpr::genCode(ExprContext &ctx) {

}

void GreaterThanEqualsExpr::genCode(ExprContext &ctx) {

}

void GreaterThanExpr::genCode(ExprContext &ctx) {

}

void NotEqualExpr::genCode(ExprContext &ctx) {

}

void EqualExpr::genCode(ExprContext &ctx) {

}

void LogicalAndExpr::genCode(ExprContext &ctx) {

}

void LogicalOrExpr::genCode(ExprContext &ctx) {

}

void AssignExpr::genCode(ExprContext &ctx) {

}

string BreakStatement::genCode(){
    return "";
}

string ContinueStatement::genCode(){
    return "";
}

string BlockStatement::genCode()
{
    stringstream ss;

	for (Statement *st : this->stList) {
		ss << st->genCode() << endl;
	}

	return ss.str();
}

string ExprStatement::genCode(){
    return "";    
}

string ReturnStatement::genCode(){
   return "";
}

string WhileStatement::genCode(){
    return ""; 
}

string ForStatement::genCode(){
    return "";
}

string IfStatement::genCode(){
    return "";
}

string FunctionStatement::genCode(){
    return "";
}

string DeclarationStatement::genCode(){
    return "";
}

string PrintStatement::genCode()
{
    stringstream ss;
    for(auto expr : *this->exprList){ 
        if (expr->getKind() == ExprKind::LIT_STRING) {
            string lit = ((StringExpr*)expr)->str.c_str();
            string pointer = newLiteral();
            stringLiterals[pointer] = " db \""+lit+"\", 0";
            ss << "push "<<pointer <<endl;
            if(hasNewLine)
                ss << "push  formatStringln" <<endl;
            else
                ss << "push  formatString" <<endl;
            
               ss<< "call printf"<<endl
	           << "add esp, 8"<<endl;
                
        }else{
        }
    }
    return ss.str();    
}

