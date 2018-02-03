%option noyywrap
%option yylineno

%{
    #include <stdio.h>
    #include "tokens.h"
    #include <list>
    using namespace std;

    int pushInclude(char * fileName);
    int popInclude();
    char *yyfilename;

    typedef struct inlcudeStack{
        struct inlcudeStack *prev;
        YY_BUFFER_STATE bs;
        FILE *file;
        char *filename;
        int lineno;
    } includeStack_t ;

    includeStack_t * st = NULL;

    list<int> spaces;
    bool expectedIndent = false;


%}

%x newlineState

%%
[ \t]   {}
"#".*   {}
"+"     {return OP_ADD;}
"-"     {return OP_SUB;}
"%"     {return OP_MOD;}
"**"    {return OP_EXP;}
"*"     {return OP_MULT;}
"/"     {return OP_DIV;}
"<"     {return OP_LT;}
"<="    {return OP_LTE;}
">"     {return OP_GT;}
">="    {return OP_GTE;}
"!="    {return OP_NEQ;}
"=="    {return OP_EQ;}
"="     {return OP_ASSGN;}
"("     {return PAR_LEFT;}
")"     {return PAR_RIGHT;}
":"     {return TK_SEMICOLON;}
","     {return TK_COMMA;}
"print" {return TK_PRINT;}
"while" {return TK_WHILE;}
"if"    {return TK_IF;}
"else"  {return TK_ELSE;}
"for"   {return TK_FOR;}
"in"    {return TK_IN;}
"range" {return TK_RANGE;}
"pass"  {return TK_PASS;}
"input" {return TK_INPUT;}
\"(\\.|[^"\\])*\"  {yylval.string_t= new string(yytext); return LIT_STRING;}
[0-9]+  {yylval.int_t=atoi(yytext); return LIT_NUM;}
[_a-zA-z][_a-zA-z0-9]* {yylval.string_t= new string(yytext); return TK_ID;}
\n      { expectedIndent = true; BEGIN(newlineState);}
<INITIAL><<EOF>> {
                    int result = popInclude();
                    if(result != 0) {
                        yyterminate();
                    }
                    
                 }
.       {printf("Invalid Character: %s\n",yytext); return TK_ERROR;}

<newlineState>"#".*   {}
<newlineState>\n      {}
<newlineState>^" "+   {
                            int currentIndent = spaces.back();
                            if (yyleng > currentIndent) {
                                spaces.push_back(yyleng);
                                BEGIN(INITIAL);
                                return OPEN_INDENT;
                            } else if (yyleng < currentIndent) {
                                spaces.pop_back();
                                unput('\n');
                                return CLOSE_INDENT;
                            } else {
                                expectedIndent = false;
                            }

                      }
<newlineState>.       {
                            unput(yytext[0]);
                            int currentIndent = spaces.back();
                            BEGIN(INITIAL);
                            if (expectedIndent && currentIndent > 0) {
                                spaces.pop_back();
                                unput('\n');
                                return CLOSE_INDENT;
                            } else {
                                return TK_EOL;
                            }
                      }
<newlineState><<EOF>> {
                            int currentIndent = spaces.back();
                            BEGIN(INITIAL);
                            if (expectedIndent && currentIndent > 0) {
                                spaces.pop_back();
                                return CLOSE_INDENT;
                            } else {
                                return TK_EOL;
                            }
                      } 
%%

int pushInclude(char * fileName){
    FILE *file =fopen(fileName,"r");

    if(file == NULL){
        fprintf(stderr,"File %s not found.\n",fileName);
        return 1;
    }

    includeStack_t * tmpStack = new includeStack_t;
    if(tmpStack == NULL){
        fprintf(stderr,"Out of memory.\n");
        return 1;
    }

    tmpStack->file =file;
    tmpStack->lineno=yylineno;
    tmpStack->filename=yyfilename;
    tmpStack->bs = yy_create_buffer(file,YY_BUF_SIZE);
    tmpStack->prev = st;

    st=tmpStack;
    yyfilename=fileName;
    yylineno=1;
    yy_switch_to_buffer(tmpStack->bs);
 
    return 0;
}

int popInclude(){
    includeStack_t * prev_st =  st-> prev;
    fclose(st->file);
    yy_delete_buffer(st->bs);
    yylineno=st->lineno;
    yyfilename=st->filename;

    if(prev_st == NULL) 
        return 1;

    yy_switch_to_buffer(prev_st->bs);
    st = prev_st;
    return 0;
}