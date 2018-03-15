#include "ast.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
map<string ,BaseType*> variables;
vector<map<string,string>>$scopes;
map<string ,string> stringLiterals;
static int tmp_offset =4;
static int labelCount = 0;
static int literalCount =0;
map<int, bool> tempInUse;

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
			cout << var.first << " dd " << 0 << endl;
	}
}

string resolveId(string id){

	int scopes = $scopes.size() - 1;
	for(int i = scopes; i >= 0; i--) {
		if($scopes[i].find(id) != $scopes[i].end()){
			return "DWORD[ebp " + $scopes[i][id] + "]";
		}
	}

	if(variables.find(id) != variables.end()){
		return  "DWORD ["+id+"]";
	}

	$scopes[scopes][id] = " - " + to_string(tmp_offset);
	string addr = "DWORD[ebp - " + to_string(tmp_offset) + "]";
	tmp_offset += 4;
	return addr;
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
	ctx.place =  this->value ? "1" : "0";
    ctx.code = "";
}

void StringExpr::genCode(ExprContext &ctx) {

}

void NumberExpr::genCode(ExprContext &ctx) {
	ctx.place = to_string(this->value);
	ctx.code = "";
}

void VarExpr::genCode(ExprContext &ctx) {
	ctx.place = resolveId(this->Id);
    ctx.code = "";
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

void BitOrExpr::genCode(ExprContext &ctx) {

}

void BitXorExpr::genCode(ExprContext &ctx) {

}

void BitAndExpr::genCode(ExprContext &ctx) {

}

void AssignExpr::genCode(ExprContext &ctx) {
	stringstream ss;
	ExprContext ctx1 , ctx2;

	this->right->genCode(ctx2);
	ss << ctx2.code;
	ss << "mov eax, " << ctx2.place << endl;
	this->left->genCode(ctx1);
	//todo la mierda con arrays tmbn
	if(VarExpr* idnode = dynamic_cast<VarExpr*>(this->left)){
		ss << "mov " << ctx1.place  << ", eax\n";
		releaseTemp(ctx2.place);
		releaseTemp(ctx1.place);
		ctx.code += ss.str();
	}else{
		throw invalid_argument("left side of asignation must be a variable");
	}
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
   stringstream ss;
   ExprContext ctx;
   if(this->Type == INT_TYPE)
		variables[this->Id] = new IntType(0);
   else if(this->Type == BOOL_TYPE)
		variables[this->Id] = new BoolType(0);

	expr->genCode(ctx);
	ss << ctx.code;
	ss << "mov eax, " << ctx.place << endl;
    ss << "mov " <<resolveId(this->Id) << ", eax\n";
	releaseTemp(ctx.place);
	return ss.str();




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

