%option noyywrap
%option yylineno

%{
    #include <stdio.h>
    #include "tokens.h"
    #include <list>
    using namespace std;

    int pushInclude(char * fileName);
    int popInclude();
    int popSpaces();
    int getIndent();
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


%}

%%
\t      {}
^" "+   { int token=getIndent();printf("%d\n",token); if(token!=-1) return token;}
" "     {}
"+"     {return OP_ADD;}
"#".*   {}
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
"range" {return TK_RANGE;}
"pass"  {return TK_PASS;}
"input" {return TK_INPUT;}
L?\"(\\.|[^\\"])*\"  {yylval.string_t= new string(yytext); return LIT_STRING;}
[0-9]+  {yylval.int_t=atoi(yytext); return LIT_NUM;}
[_a-zA-z][_a-zA-z0-9]* {yylval.string_t= new string(yytext); return TK_ID;}
\n    {return TK_EOL;}
<INITIAL><<EOF>> {
                    int result = popInclude();
                    if(result != 0) {
                        yyterminate();
                    }
                    
                 }
.       {return TK_ERROR;}
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

int popSpaces(){
    if(spaces.empty())
        spaces.push_back(0);
    int x = spaces.back();
    spaces.pop_back();
    return x;
}

int getIndent(){
    string text = string(yytext);
    if(text.length() > spaces.back()){
        spaces.push_back(text.length());
        return OPEN_INDENT;
    }
    if(text.length() == spaces.back())
        return -1;
    if(text.length() < spaces.back()){
        int x = popSpaces();
        if(x>0 && text.length()>spaces.back()){
            printf("Error invlaid indentation\n");
            yyterminate();
        }else{
            return CLOSE_INDENT;
        }
    }
}