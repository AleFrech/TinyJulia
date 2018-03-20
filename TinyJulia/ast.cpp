#include "ast.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
map<string ,BaseType*> variables;
map<string, primitiveType> functions;
set<string> fucntion_codes;
vector<map<string,VariableMetaData>>$scopes;
map<string ,string> stringLiterals;
static string nearestLoop;
static string nearestLoopEnd;
static int tmp_offset =4;
static int labelCount = 0;
static int literalCount =0;
static bool isInnerContext = false;
static bool inLoop = false;
map<int, bool> tempInUse;

void genDataSection() {
	cout<<endl;
	cout << "section .data" << endl;
	cout << "format db \"%d\", 0"<< endl;
	cout << "formatString db \"%s\", 0"<< endl;
    cout << "newline db \"\" ,10 ,0"<<endl;

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


string getId(string id,primitiveType& type){

	int scopes = $scopes.size() - 1;
	for(int i = scopes; i >= 0; i--) {
		if($scopes[i].find(id) != $scopes[i].end()){
			type = $scopes[i][id].type;
			return "DWORD[ebp " + $scopes[i][id].address + "]";
		}
	}

	if(variables.find(id) != variables.end()){
		type = variables[id]->Type;
		return  "DWORD ["+id+"]";
	}

	$scopes[scopes][id].address = " - " + to_string(tmp_offset);
	string addr = "DWORD[ebp - " + to_string(tmp_offset) + "]";
	tmp_offset += 4;
	return addr;
}

string getId(string id){
	primitiveType type;
	return getId(id,type);
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

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE){
		throw invalid_argument("Cant add incompatible types");
	}

    ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.place = newTemp();
    ctx.code += "mov eax, " + ctx1.place+"\n"+
    "add eax," + ctx2.place+"\n"+
    "mov "+ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void SubExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant sub incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.place = newTemp();
    ctx.code += "mov eax, " + ctx1.place+"\n"+
    "sub eax," + ctx2.place+"\n"+
    "mov "+ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void MulExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant multiplicate incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "imul ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void DivExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant divide incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "idiv ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;

}

void ModExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant mod incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "idiv ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", edx\n";
	ctx.type = INT_TYPE;
}

void ExponentExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant pow incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "push "+ctx2.place+"\n";
    ctx.code += "push "+ctx1.place+"\n";
    ctx.code += "call power\n";
	ctx.code += "add esp,8\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void LessThanExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);


    if((ctx1.type == INT_TYPE && ctx2.type == INT_TYPE )){
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
		ctx.type = BOOL_TYPE;
    }else
	    throw invalid_argument("Cant '<' incompatible types");
}

void LessThanEqualsExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);


    if((ctx1.type == INT_TYPE && ctx2.type == INT_TYPE )){
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
		ctx.type = BOOL_TYPE;
    }else
	    throw invalid_argument("Cant '<=' incompatible types");
}


void GreaterThanExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);


    if((ctx1.type == INT_TYPE && ctx2.type == INT_TYPE )){
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
		ctx.type = BOOL_TYPE;
    }else
	    throw invalid_argument("Cant '>' incompatible types");
}

void GreaterThanEqualsExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);


    if((ctx1.type == INT_TYPE && ctx2.type == INT_TYPE )){
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
		ctx.type = BOOL_TYPE;
    }else
	    throw invalid_argument("Cant '>=' incompatible types");
}

void EqualExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);


    if((ctx1.type == INT_TYPE && ctx2.type == INT_TYPE ) || (ctx1.type == BOOL_TYPE && ctx2.type == BOOL_TYPE )){
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
		ctx.type = BOOL_TYPE;
    }else
	    throw invalid_argument("Cant '>=' incompatible types");
}

void NotEqualExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);


    if((ctx1.type == INT_TYPE && ctx2.type == INT_TYPE ) || (ctx1.type == BOOL_TYPE && ctx2.type == BOOL_TYPE )){
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
		ctx.type = BOOL_TYPE;
    }else
	    throw invalid_argument("Cant '>=' incompatible types");
}

void LeftShiftExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant << incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "sal eax, cl\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;	
}

void RightShiftExpr::genCode(ExprContext &ctx) {
	ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant >> incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "sar eax, cl\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void BitOrExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant bit and incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "or eax, ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void BitXorExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant bit and incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "xor eax, ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void BitAndExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
		throw invalid_argument("Cant bit and incompatible types");

    ctx.code = ctx1.code + "\n" + ctx2.code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    ctx.code += "mov eax,"+ctx1.place+"\ncdq\n";
    ctx.code += "mov ecx,"+ctx2.place+"\n";
    ctx.code += "and eax, ecx\n";
    ctx.place = newTemp();
    ctx.code += "mov " + ctx.place+", eax\n";
	ctx.type = INT_TYPE;
}

void UnaryAddExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
	this->expr->genCode(ctx1);
	if(ctx1.type != INT_TYPE){
		throw invalid_argument("unary '+' only compatible with int type");
	}
    ctx.code = ctx1.code + "\n";
    ctx.place = ctx1.place;
    releaseTemp(ctx1.place);
	ctx.type = INT_TYPE;
}

void LogicalAndExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != BOOL_TYPE || ctx2.type != BOOL_TYPE){
		throw invalid_argument("Cant && incompatible types");
	}

    ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    string isfalse = newLabel();
    string isTrue = newLabel();
    string done = newLabel();
    ctx.place = newTemp();
    ctx.code += "mov eax, " + ctx1.place+"\n"+
    "test eax, eax\n"+
    "jz "+ isfalse +"\n"+
    "mov eax ,"+ctx2.place+"\n"+
    "test eax, eax\n"+
    "jnz "+ isTrue +"\n"+
    isfalse+":\n"+
    "mov "+ctx.place+", 0\n"+
    "jmp "+done+"\n"+
    isTrue+":\n"+
    "mov "+ctx.place+", 1\n"
    "jmp "+done+"\n"+
    done + ":\n";
	ctx.type = BOOL_TYPE;
}

void LogicalOrExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
    ExprContext ctx2;

    expr1->genCode(ctx1);
    expr2->genCode(ctx2);

	if(ctx1.type != BOOL_TYPE || ctx2.type != BOOL_TYPE){
		throw invalid_argument("Cant || incompatible types");
	}

    ctx.code = ctx1.code + "\n" + ctx2. code + "\n";
    releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    string isfalse = newLabel();
    string isTrue = newLabel();
    string done = newLabel();
    ctx.place = newTemp();
    ctx.code += "mov eax, " + ctx1.place+"\n"+
    "test eax, eax\n"+
    "jnz "+ isTrue +"\n"+
    "mov eax ,"+ctx2.place+"\n"+
    "test eax, eax\n"+
    "jnz "+ isTrue +"\n"+
    isfalse+":\n"+
    "mov "+ctx.place+", 0\n"+
    "jmp "+done+"\n"+
    isTrue+":\n"+
    "mov "+ctx.place+", 1\n"
    "jmp "+done+"\n"+
    done + ":\n";
	ctx.type = BOOL_TYPE;
}



void UnarySubExpr::genCode(ExprContext &ctx) {
    ExprContext ctx1;
	this->expr->genCode(ctx1);
	if(ctx1.type != INT_TYPE){
		throw invalid_argument("unary '-' only compatible with int type");
	}
    ctx.code = ctx1.code + "\n";
    ctx.place = ctx1.place;
    releaseTemp(ctx1.place);
	ctx.type = INT_TYPE;
}

void UnaryNotExpr::genCode(ExprContext &ctx){
     ExprContext ctx1;
	 this->expr->genCode(ctx1);
     if(ctx1.type != INT_TYPE){
		throw invalid_argument("unary '~' only compatible with int type");
	 }
     ctx.code = ctx1.code + "\n";
     ctx.code += "mov eax,"+ctx1.place+"\n";
     ctx.code += "not eax\n";
     ctx.place = newTemp();
     ctx.code += "mov " + ctx.place+", eax\n";
	 ctx.type = INT_TYPE;
}

void UnaryDistintExpr::genCode(ExprContext &ctx){
     ExprContext ctx1;
	 this->expr->genCode(ctx1);
     if(ctx1.type != BOOL_TYPE){
		throw invalid_argument("unary '!' only compatible with bool type");
	 }
     ctx.code = ctx1.code + "\n";
     ctx.code += "mov eax,"+ctx1.place+"\n";
     ctx.code += "xor ecx, ecx\n";
     ctx.code += "test eax, eax\n";
     ctx.code += "setz cl\n";
     ctx.place = newTemp();
     ctx.code += "mov " + ctx.place+", ecx\n";
	 ctx.type = BOOL_TYPE;
}

void ParenthesisPosIdExpr::genCode(ExprContext &ctx) {
	
    this->expressionList->reverse();
    ExprContext tmpCtx;
	stringstream ss;
    string functionName = this->Id;
    for(auto e : *this->expressionList){
		e->genCode(tmpCtx);
        functionName+=to_string(tmpCtx.type);
		ss << tmpCtx.code
			<< "push "<< tmpCtx.place << endl;
	}
    if(functions.find(functionName) == functions.end())
		throw invalid_argument("undeclared function "+this->Id);
    releaseTemp(tmpCtx.place);
    ctx.place = newTemp();
    ss << "call " << functionName << endl;
    if((*this->expressionList).size()!=0)
	ss << "add esp, "<<(4*(*this->expressionList).size()) << endl;
	ss << "mov " << ctx.place <<", eax" << endl;
	ctx.code = ss.str();
	ctx.type = functions[functionName];
	releaseTemp(ctx.place);
}



void BoolExpr::genCode(ExprContext &ctx) {
	ctx.place =  this->value ? "1" : "0";
    ctx.code = "";
	ctx.type = BOOL_TYPE;
}

void StringExpr::genCode(ExprContext &ctx) {

}

void NumberExpr::genCode(ExprContext &ctx) {
	ctx.place = to_string(this->value);
	ctx.code = "";
	ctx.type = INT_TYPE;
}

void VarExpr::genCode(ExprContext &ctx) {
	ctx.place = getId(this->Id,ctx.type);
    ctx.code = "";
}

void ParamExpr::genCode(ExprContext &ctx) {

}

void BracketPostIdExpr::genCode(ExprContext &ctx) {

}

void ArrayExpr::genCode(ExprContext &ctx) {

}




void AssignExpr::genCode(ExprContext &ctx) {
	stringstream ss;
	ExprContext ctx1 , ctx2;
	this->right->genCode(ctx2);
	this->left->genCode(ctx1);
	if(ctx1.type != ctx2.type)
		throw invalid_argument("invalid assignation of diffrent type");	
	ss << ctx2.code;
	ss << "mov eax, " << ctx2.place << endl;
	if(VarExpr* idnode = dynamic_cast<VarExpr*>(this->left)){
         if( variables.find(idnode->Id) == variables.end())
            throw invalid_argument("Invalid asignation of a undifined global variable "+idnode->Id);

        // if(isInnerContext && variables.find(idnode->Id)!= variables.end())
        //     throw invalid_argument("Invalid asignation of a global variable "+idnode->Id);
		ss << "mov " << ctx1.place  << ", eax\n";
		releaseTemp(ctx2.place);
		releaseTemp(ctx1.place);
		ctx.code += ss.str();
		ctx.type = ctx1.type;
	}else{
		throw invalid_argument("left side of asignation must be a variable");
	}
}

string BreakStatement::genCode(){
    if(!inLoop)
        throw invalid_argument("break is not within a loop");
    return "jmp "+nearestLoopEnd+"\n";
}

string ContinueStatement::genCode(){
    if(!inLoop)
        throw invalid_argument("continue is not within a loop");
    return "jmp "+nearestLoop+"\n";;
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
    stringstream ss;
	ExprContext ctx;
	this->exp->genCode(ctx);
	ss << ctx.code << endl
	<< "mov eax, " << ctx.place <<endl
	<< "leave\nret"<< endl;
	releaseTemp(ctx.place);
	return ss.str();
}

string WhileStatement::genCode(){
    inLoop = true;
    isInnerContext = true;
    stringstream ss;
	ExprContext ctx;
    $scopes.push_back(map <string, VariableMetaData>());
	expr->genCode(ctx);
    if(ctx.type != BOOL_TYPE )
        throw invalid_argument("while expresion must be bool type");
    string labelWhile = newLabel();
    nearestLoop = labelWhile;
	string labelEndW = newLabel();
    nearestLoopEnd = labelEndW;
    ss << labelWhile << ":" << endl
    << ctx.code << endl
    << "mov eax, "<<ctx.place << endl
    << "cmp eax , 0" << endl
    << "jz "<<labelEndW << endl
    << this->blockStatement->genCode() << endl
    << "jmp " << labelWhile << endl
    << labelEndW << ":";

	releaseTemp(ctx.place);
    $scopes.pop_back();
    inLoop = false;
    isInnerContext = false;
	return ss.str();
}

string ForStatement::genCode(){
    inLoop = true;
    isInnerContext =true;
    ExprContext ctx1,ctx2;
    stringstream ss;
    $scopes.push_back(map <string, VariableMetaData>()); 
    string labelFor = newLabel();
    nearestLoop = labelFor;
	string labelForEnd = newLabel();
    nearestLoopEnd = labelForEnd;
    this->desde->genCode(ctx1);
    this->hasta->genCode(ctx2);
    if(ctx1.type != INT_TYPE || ctx2.type != INT_TYPE)
        throw invalid_argument("for indexes must be int type");
    
    ss << ctx1.code <<endl;
    ss << ctx2.code <<endl;
    ss << "mov " <<getId(this->Id) <<", "<<ctx1.place<<endl;
    ss << labelFor << ":"<<endl;
    ss << "mov ecx , "<<ctx2.place<<endl;
    ss << "cmp " <<getId(this->Id) << ", ecx"<<endl;
    ss << "jg " <<labelForEnd << endl
    << this->blockStatement->genCode()
    << "inc " <<  getId(this->Id) << endl
    << "jmp " << labelFor << endl
    << labelForEnd << ":";

	releaseTemp(ctx1.place);
    releaseTemp(ctx2.place);
    inLoop = false;
    isInnerContext = false;
    $scopes.pop_back();
	return ss.str();   
}

string IfStatement::genCode(){
    return "";
}

string FunctionStatement::genCode(){
    stringstream ss;
    isInnerContext = true;
	map <string, VariableMetaData> methodParams;
	int paramOffset = 8;
    string functionfullName = this->Id;
    for(auto expr : *expList){
        if(ParamExpr* param = dynamic_cast<ParamExpr*>(expr)){
            methodParams[param->Id].address = "+ " + to_string(paramOffset);
			methodParams[param->Id].type = param->Type;
            paramOffset += 4;
            functionfullName+=to_string(param->Type);
        }
    }
	
    $scopes.push_back(methodParams);
	functions[functionfullName] = this->Type;
    ss << functionfullName << ":" << endl
    << "push ebp" << endl 
	<< "mov ebp, esp" << endl;
    string methodBlock;
	if(this->Block != NULL){
        methodBlock = this->Block->genCode();
        if(BlockStatement* bst = dynamic_cast<BlockStatement*>(this->Block)){
            for(auto st : bst->stList){
                if(ReturnStatement* rt = dynamic_cast<ReturnStatement*>(st)){
                    if(this->Type == VOID_TYPE)
                        throw invalid_argument("Cant have return type in void function");
                    ExprContext ctx;
                    rt->exp->genCode(ctx);
                    if(ctx.type != this->Type)
                        throw invalid_argument("function and return type are incompatible");
                }
            }
        }
    }
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
        if(variables.find(this->Id) != variables.end())
            throw invalid_argument("Invalid re declaration of variable");
        if(this->Type == INT_TYPE)
            variables[this->Id] = new IntType(0);
        else if(this->Type == BOOL_TYPE)
            variables[this->Id] = new BoolType(0);
    }else{
        int scopes = $scopes.size() - 1;
        $scopes[scopes][this->Id].address = " - " + to_string(tmp_offset);
		 $scopes[scopes][this->Id].type = this->Type;
        tmp_offset += 4;
    }

	expr->genCode(ctx);
	if(ctx.type != this->Type){
		throw invalid_argument("Invalid declaration of diffrent types");
	}
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
			string value = " db \"";
			for(int i =0; i<lit.size();i++){
				if(lit[i]=='\n'){
					value+="\", 10, \"";
				}else if(lit[i]=='\t'){
					value+="\", 9, \"";
				}else if(lit[i]=='\"'){
					value+="\", 34, \"";
				}else if(lit[i]=='\\'){
					value+="\", 92, \"";
				}else
					value+=lit[i];
			}
			value+="\", 0";
            stringLiterals[pointer] = value;
            ss << "sub esp, 8"<<endl;
            ss << "push "<<pointer <<endl;
            ss << "push  formatString" <<endl;
                
        }else{
            expr->genCode(ctx);
            ss << ctx.code << endl
            << "sub esp, 8"<<endl
	        << "push " << ctx.place << endl;
            ss << "push format" <<endl;
            releaseTemp(ctx.place);
        }
        ss<< "call printf"<<endl
	    << "add esp, 8"<<endl;
    }
    if(this->hasNewLine){
        ss << "sub esp, 4"<<endl;
        ss<< "push newline"<<endl;
        ss<< "call printf"<<endl
        << "add esp, 4"<<endl;
    }
    return ss.str();    
}