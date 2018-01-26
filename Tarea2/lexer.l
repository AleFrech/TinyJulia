%option noyywrap

%{
    #include <stdio.h>
    #include "tokens.h"
%}

idRegex [_a-zA-z][_a-zA-z0-9]*
%%
[ \t]   { }
"+"     {return OP_ADD;}
"-"     {return OP_SUB;}
"*"     {return OP_MULT;}
"/"     {return OP_DIV;}
"("     {return PAR_LEFT;}
")"     {return PAR_RIGHT;}
[0-9]+  {return LIT_NUM;}
idRegex {return TK_ID;}
"\n"    { }
";"     {return TK_EOS;}
"="     {return OP_ASG;}
<<EOF>> {return TK_EOF;}
.       {return TK_ERROR;}
%%