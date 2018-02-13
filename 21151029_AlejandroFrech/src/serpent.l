%option noyywrap
%option yylineno
%option nodefault

%{
#include <cstdlib>
#include <cstring>
#include <list>
#include "ast.h"
#include "tokens.h"

using namespace std;

list<int> tabs;
string accumulate;
extern int errors;
%}

DIGIT [0-9]
LETTER [a-zA-Z]

%x eol
%x switchState

%%

"<?" {BEGIN(switchState);}
. { accumulate += to_string(accumulate);}
INITIAL<<EOF>> {
    
}
<switchState>"=" { return '='; }
<switchState>"+" { return '+'; }
<switchState>"-" { return '-'; }
<switchState>"*" { return '*'; }
<switchState>"/" { return '/'; }
<switchState>"%" { return '%'; }
<switchState>"**" { return OP_EXP; }
<switchState>"<" { return OP_LT; }
<switchState>">" { return OP_GT; }
<switchState>"?>" {BEGIN(INITIAL); return TK_EOL;}
<switchState>"<=" { return OP_LTE; }
<switchState>">=" { return OP_GTE; }
<switchState>"!=" { return OP_NE; }
<switchState>"==" { return OP_EQ; }
<switchState>"("  { return '('; }
<switchState>")"  { return ')'; }
<switchState>"{"  { return '{'; }
<switchState>"}"  { return '}'; }
<switchState>","  { return ','; }
<switchState>":"  { return ':'; }
<switchState>"if" { return KW_IF; }
<switchState>"else" { return KW_ELSE; }
<switchState>"while" { return KW_WHILE; }
<switchState>"for" { return KW_FOR; }
<switchState>"in" { return KW_IN; }
<switchState>"range" { return KW_RANGE; }
<switchState>"print" { return KW_PRINT; }
<switchState>"input" { return KW_INPUT; }
<switchState>"#"[^\n]* { /* Nothing */ }
<switchState>"'"[^']*"'" { yytext[yyleng-1] = '\0'; yylval.id_t = strdup(&yytext[1]); return STRING_LITERAL; }
<switchState>"\""[^"]*"\"" { yytext[yyleng-1] = '\0'; yylval.id_t = strdup(&yytext[1]); return STRING_LITERAL; }
<switchState>[ \t] { /* Nada */ }
<switchState>"\n"  { return TK_EOL; }
<switchState>{DIGIT}+ { yylval.num_t = atoi(yytext); return TK_NUM; }
<switchState>{LETTER}({DIGIT}|{LETTER}|_)* { yylval.id_t = strdup(yytext); return TK_ID; }
<switchState>. { errors++; printf("Line %d: Invalid symbol '%c'\n", yylineno, yytext[0]); }
%%
