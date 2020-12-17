digit           [0-9]
letter          [a-zA-Z]

%{
    #include <string.h>
    #include "y.tab.h"
    int count;
    extern int yylineno;
    extern char* yytext;
    void extern yyerror(char*);
    void TokenNotRecognized(char*);
%}

%%

if                                              return IF;
then                                            return THEN;
else                                            return ELSE;
end                                             return END;

while                                           return WHILE;
do                                              return DO;

print                                           return PRINT;

"void"                                          {yylval.dataType = strdup(yytext); return DATA_TYPE;}
"char"                                          {yylval.dataType = strdup(yytext); return DATA_TYPE;}
"int"                                           {yylval.dataType = strdup(yytext); return DATA_TYPE;}
"float"                                         {yylval.dataType = strdup(yytext); return DATA_TYPE;}
"string"                                        {yylval.dataType = strdup(yytext); return DATA_TYPE;}

true                                            return TRUE_STMT;
false                                           return FALSE_STMT;
not                                             return NOT;



";"                                             {return SEMI_COLON;}
","                                             {return COMMA;}
"'"                                             {return SINGLE_QUOTE;}
"\""                                            {return DOUBLE_QUOTE;}
"+"                                             {return PLUS_SIGN;}
"-"                                             {return MINUS_SIGN;}
"*"                                             {return MULTIPLICATION_SIGN;}
"/"                                             {return DIVISION_SIGN;}
"="                                             {return EQUALS_SIGN;}
"=="                                            {return CMPR_EQ;}
"<"                                             {return CMPR_LESS;}
">"                                             {return CMPR_MORE;}
"&"                                             {return AND;}
"|"                                             {return OR;}
"("                                             {return BRACKET_OPEN;}
")"                                             {return BRACKET_CLOSE;}

[-+]?{digit}+                                   {yylval.intVal = atoi(yytext); return INTEGER_VAL;}
[\'].[\']                                       {yylval.charVal = yytext[1]; return  CHARACTER_VAL;}
[-+]?{digit}*\.?{digit}+                        {yylval.floatVal = atof(yytext); return FLOAT_VAL;}
\"(\\.|[^"\\])*\"                               {
                                                char* clean = yytext;
                                                clean++;
                                                clean[strlen(clean) - 1] = 0;
                                                yylval.strVal = clean;
                                                return STRING_VAL;
                                                }
([a-z])({letter}|{digit})*                      {yylval.strVal = strdup(yytext); return IDENTIFIER;}

"/*"(\\.|[^"\\])*"*/"                           ;                   // Ignore comments
[ \t\r\v\f]+                                    ;                   // Ignore whitespace
[\n]+                                           yylineno++;         // Count lines
.                                               {TokenNotRecognized(yytext);}


%%

int yywrap() {
    return 1;
}

void yyerror(char *err) {
    fprintf(stderr, "Encountered an error on line: %d, \"%s\"\n", yylineno, err);
    exit(0);
}

void TokenNotRecognized(char* token)
{
    fprintf(stderr, "Unrecognized token on line: %d, \"%s\"\n", yylineno, token);
    exit(0);
}