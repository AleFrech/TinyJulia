%option noywrap

%{
    #include <stdio.h>
    #include "tokens.h"
%}

%%
[ \t]   {/* Nothing */}
"+"     {return OP_ADD;}
"-"     {return OP_SUB;}
"*"     {return OP_MULT;}
"/"     {return OP_DIV;}
"("     {return PAR_LEFT;}
")"     {return PAR_RIGHT;}
[0-9]+  {return LIT_NUM;}
"\n"    {return TK_EOL;}
<<EOF>> {return TK_EOF;}
.       {return TK_ERROR;}
%%