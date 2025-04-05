%{
#include "compute.h"
%}

%%
compute         { return COMPUTE; }
M               { return M; }
=               { return EQUALS; }
A               { return A; }
\*              { return MULTIPLY; }
B               { return B; }
;               { return END; }
[ \t\n]+        ; // Ignore whitespace
.               { printf("Unknown character: %s\n", yytext); }
%%
int yywrap() {
    return 1;
}
