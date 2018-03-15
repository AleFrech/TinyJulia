#include "ast.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
map<string ,BaseType*> variables;
set<string> fucntion_codes;
vector<map<string,string>>$scopes;
map<string ,string> stringLiterals;
static int tmp_offset =4;
static int labelCount = 0;
static int literalCount =0;
static bool isInnerContext = false;
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

void genFunctionSection(){
	cout<<endl;
	for (auto &fun : fucntion_codes) {
		cout << fun << endl;
	}
}

string getId(string id){

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

void resetOffset(){
	tmp_offset = 4;
}

void AddExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

    ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.place = newTemp();
    ctx.code += "mov eax, " + ctx1.place+"\n"+
    "add eax," + ctx2.place+"\n"+
    "mov "+ctx.place+", eax\n";
}

void SubExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

    ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.place = newTemp();
    ctx.code += "mov eax, " + ctx1.place+"\n"+
    "sub eax," + ctx2.place+"\n"+
    "mov "+ctx.place+", eax\n";
}

void MulExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "imul ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
}

void DivExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "idiv ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";

}

void ModExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "idiv ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", edx\n";
}

void ExponentExpr::genCode(ExprContext &ctx) {

}

void UnarySubExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    this->expr->genCode(ctx1);
    ctx.code = ctx1.code + "\n";
    ctx.place = ctx1.place;
    releaseTemp(ctx1.place);
}

void ParenthesisPosIdExpr::genCode(ExprContext &ctx) {
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
    ss << "call " << this->Id << endl;
    if((*this->expressionList).size()!=0)
	ss << "add esp, "<<(4*(*this->expressionList).size()) << endl;
	ss << "mov " << ctx.place <<", eax" << endl;
	ctx.code = ss.str();
	releaseTemp(ctx.place);
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
	ctx.place = getId(this->Id);
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
         if( variables.find(idnode->Id) == variables.end())
            throw invalid_argument("Invalid asignation of a undifined global variable "+idnode->Id);

        if(isInnerContext && variables.find(idnode->Id)!= variables.end())
            throw invalid_argument("Invalid asignation of a global variable "+idnode->Id);
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
    stringstream ss;
	ExprContext ctx;
    this->expr->genCode(ctx);
    ss << ctx.code << endl;
    releaseTemp(ctx.place);
	return ss.str();  
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
    stringstream ss;
    isInnerContext = true;
	map <string, string> methodParams;
	int paramOffset = 8;
    for(auto expr : *expList){
        if(ParamExpr* param = dynamic_cast<ParamExpr*>(expr)){
            methodParams[param->Id] = "+ " + to_string(paramOffset);
            paramOffset += 4;
        }
    }
    $scopes.push_back(methodParams);
    ss << this->Id << ":" << endl
    << "push ebp" << endl 
	<< "mov ebp, esp" << endl;
    string methodBlock;
	if(this->Block != NULL) methodBlock = this->Block->genCode();
	string espStack = "sub esp, " + to_string(tmp_offset - 4);
	if(tmp_offset > 4) ss << espStack << endl;
	ss << methodBlock << endl
    << "xor eax, eax"<<endl
	<< "leave" <<endl
	<< "ret";
    resetOffset();
    $scopes.pop_back();
    isInnerContext = false;
    fucntion_codes.insert(ss.str());
    return "";
}

string DeclarationStatement::genCode(){
   stringstream ss;
   ExprContext ctx;
   if(!isInnerContext){
        if(this->Type == INT_TYPE)
		    variables[this->Id] = new IntType(0);
        else if(this->Type == BOOL_TYPE)
		    variables[this->Id] = new BoolType(0);
    }else{
        int scopes = $scopes.size() - 1;
        $scopes[scopes][this->Id] = " - " + to_string(tmp_offset);
        tmp_offset += 4;
    }

	expr->genCode(ctx);
	ss << ctx.code;
	ss << "mov eax, " << ctx.place << endl;
    ss << "mov " <<getId(this->Id) << ", eax\n";
	releaseTemp(ctx.place);
	return ss.str();

}

string PrintStatement::genCode()
{
    stringstream ss;
    ExprContext ctx;
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
                
        }else{
            expr->genCode(ctx);
            ss << ctx.code << endl
	        << "push " << ctx.place << endl;
            if(hasNewLine)
                ss << "push formatln" <<endl;
            else
                ss << "push format" <<endl;
            
            releaseTemp(ctx.place);
        }
        ss<< "call printf"<<endl
	    << "add esp, 8"<<endl;
    }
    return ss.str();    
}

