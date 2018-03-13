#include "ast.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
map<string ,BaseType> variables;
static int tmp_offset =4;
static int labelCount = 0;
map<int, bool> tempInUse;
static string currentContext ="";

void genDataSection() {
	cout<<endl;
	cout << "section .data" << endl;
	cout << "formatln db \"%d \", 10, 0"<< endl;
	cout << "format db \"%d \", 0"<< endl;

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
    
    for(auto expr : *this->exprList){
        if (expr->getKind() == ExprKind::LIT_STRING) {
            printf("%s", ((StringExpr*)expr)->str.c_str());
        }
    }
    if(hasNewLine)
        printf("\n");

    return "";
}

