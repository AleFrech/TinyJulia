%option noyywrap
%option yylineno

%x commentState
%x includeState

%{
    #include <stdio.h>
    #include "tokens.h"

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
%}

%%
[ \t]   { }
^"#"[ \t]*"include"[ \t]*\" {BEGIN(includeState);}
"/*"    {BEGIN(commentState);}
"+"     {return OP_ADD;}
"//".*  {}
"-"     {return OP_SUB;}
"*"     {return OP_MULT;}
"/"     {return OP_DIV;}
"("     {return PAR_LEFT;}
")"     {return PAR_RIGHT;}
[0-9]+  {return LIT_NUM;}
[_a-zA-z][_a-zA-z0-9]* {return TK_ID;}
"\n"    { }
";"     {return TK_EOS;}
"="     {return OP_ASG;}
<INITIAL><<EOF>> {
                    int result = popInclude();
                    printf("result in EOF inital is :%d\n",result);
                    if(result != 0) {
                        return TK_EOF;
                    }
                    
                 }
.       {return TK_ERROR;}

<commentState>"*/" {BEGIN(INITIAL);}
<commentState>.|\n {}
<commentState><<EOF>> {printf("Line %d : unclosed block comment\n",yylineno); return TK_ERROR;}

<includeState>[^\"\n]+ {
                            int counter;
                            while((counter=yyinput()) && counter != '\n');
                            yylineno++;
                            int result = pushInclude(yytext);
                            if(result != 0){
                                yyterminate();
                            }
                            BEGIN(INITIAL);
                        }
<includeState>"\"" {BEGIN(INITIAL);}



%%

int pushInclude(char * fileName){
    FILE *file =fopen(fileName,"r");

    if(file == NULL){
        fprintf(stderr,"File %s not found.\n",fileName);
        return 1;
    }

    auto tmpStack = new inlcudeStack;
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
    yy_switch_to_buffer(st->bs);
 
    return 0;
}

int popInclude(){
    auto prev_st =  st-> prev;
    fclose(st->file);
    yy_delete_buffer(st->bs);
    yylineno=st->lineno;
    yyfilename=st->filename;
    delete st;

    if(prev_st == NULL) 
        return 1;

    yy_switch_to_buffer(prev_st->bs);
    st = prev_st;
    return 0;


}