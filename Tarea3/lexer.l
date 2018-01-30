%option noyywrap

%{
    #include <stdio.h>
    #include "tokens.h"
%}

%x commentState

%%
[ \t]   { }
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
<INITIAL><<EOF>> {return TK_EOF;}
.       {return TK_ERROR;}


<commentState>.|\n {}
<commentState>"*/" {BEGIN(INITIAL);}
<commentState><<EOF>> {printf("Line %d : un closed block comment\n",yylineno); return TK_ERROR;}
%%