#ifndef _AST_H
#define _AST_H
#include <list>
#include <string>
#include <map>
#include <math.h>
using namespace std;

class AstNode {

};

enum type {CHAR,STRING,INT};

class Expr : public AstNode {
    public:
        virtual int evaluate()=0;
        virtual ~Expr(){};
        virtual type getType()=0;
};

class BinaryExpr : public Expr {
    public:
        Expr * expr1;
        Expr * expr2;
        BinaryExpr(Expr * e1,Expr * e2){
            this->expr1 = e1;
            this->expr2 = e2;
        }
        ~BinaryExpr();

};

class AddExpr : public BinaryExpr {
    public:
        AddExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1, expr2) {

        }
        int evaluate();
        type getType() {
            return type::INT;
        }
};

class SubExpr : public BinaryExpr{
    public:
        SubExpr(Expr * expr1, Expr * expr2) : BinaryExpr(expr1,expr2){

        }
        int evaluate();
        type getType(){
            return type::INT;
        }
};

class MultExpr : public BinaryExpr{
    public:
        MultExpr(Expr * expr1, Expr * expr2) : BinaryExpr(expr1,expr2){

        }
        int evaluate();
        type getType(){
            return type::INT;
        }
};

class DivExpr : public BinaryExpr{
    public:
        DivExpr(Expr* expr1, Expr* expr2) : BinaryExpr(expr1,expr2){

        }
        int evaluate();
        type getType(){
            return type::INT;
        }
};

class ModExpr : public BinaryExpr{
    public:
        ModExpr(Expr * expr1, Expr * expr2) : BinaryExpr(expr1,expr2){

        }
        int evaluate();
        type getType(){
            return type::INT;
        }
};

class ExpExpr : public BinaryExpr{
    public:
        ExpExpr(Expr * expr1, Expr * expr2) : BinaryExpr(expr1,expr2){

        }
        int evaluate();
        type getType(){
            return type::INT;
        }
};

class NumExpr : public Expr {
    public:
        int value;
        NumExpr(int value){
            this->value=value;
        }
        int evaluate(){
            return value;
        }
        type getType(){
            return type::INT;
        }
};

class StringExpr : public Expr {
    public:
        string value;
        StringExpr(string value){
            this->value = value.substr(1,value.size()-2);
            myReplace(this->value ,"\\n","\n",2);
            myReplace(this->value ,"\\\"","\"",2);
        }
        string getValue(){
            return value;
        }
        int evaluate(){
            return -1;
        }

        void myReplace(string &str, string toReplace,string newStr,int size ){
            auto charIndex = str.find(toReplace);
            while(charIndex!=string::npos){
                str.replace(charIndex,size,newStr);
                charIndex = str.find(toReplace);
            }
        }

        type getType(){
            return type::STRING;
        }
};

class CharExpr : public Expr{
    public:
        string value;
        CharExpr(string value){
            this->value = value.substr(1,value.size()-2) ;
        }
        int evaluate(){
            return -1;
        }
        type getType(){
            return type::CHAR;
        }
};

class VarExpr : public Expr{
    public:
        string id;
        VarExpr(string id){
            this->id = id;
        }
        int evaluate();
        type getType(){
            return type::INT;
        }
};


class Statement : public AstNode{
    public:
        virtual void execute()=0;
        virtual ~Statement(){}; 
    
};

class AssignStatement : public Statement{
    public:
        string id;
        int value;
        AssignStatement(VarExpr* exp,Expr* value){
            this->id =exp->id;
            this->value = value->evaluate();
        }
        void execute();
};

class ExprList : public AstNode{
    public:
        list<Expr*> expressionList;
};

class PrintStatement : public Statement{
    public:
        list<Expr*> exprLsit;
        PrintStatement(ExprList* el){
            this->exprLsit = el->expressionList;
        }
        void execute();
};


class BlockStatement : public Statement{
    public:
        list<Statement*> statementList;
        void execute();
};

typedef AstNode* YYSTYPE;
#define YYSTYPE_IS_DECLARED 1


#endif

