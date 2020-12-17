%{
  #include <stdio.h>
  #include <malloc.h>
  #include <string.h>
  #include <stdlib.h>

  extern int yylex();
  extern int yylineno;
  extern void yyerror();
  char DataTypeBuffer[8];

  char* GetStoredDataType();
  void SetStoredDataType(char *);
  void ClearStoredDataType();
  int CheckStoredDataType(char *);
  int IsDuplicate(char *);
  void CreateVar(char *, char *);
  int SetChar(char*, char);
  int SetInt(char*, int);
  int SetFloat(char*, float);
  int SetString(char*, char*);
  void SetLastVarname(char*);
  char* GetLastVarname();
  void ResetLastVarname();
  void* GetVarData(char*);
  char* GetVarType(char*);
  void CreateTemp(char*);
  void DestroyTemps();
  void rand_str(char *, const int);
  void OperationUnavailable(char, char*);
  void VariablesDifferentType(char*, char*);
  void WrongTypeAssignment(char *, char *);
  void UndeclaredVariableUsed(char *);

  int top();
  void push(int);
  void pop();
  int bools[50], bCount = 0;
  int last = 1;

  int TIS = 0;
  char isTrue = 'A';
  char tmpRand[6];
  char tmpName[11];

  struct VARIABLE_STRUCT {
    char* varName;
    char* dataType;
    void* data;

    struct VARIABLE_STRUCT* next;
  };

  struct TEMPVAR_HOLDER {
    char* name;

    struct TEMPVAR_HOLDER* next;
  };
  char* LAST_VAR = NULL;
  struct VARIABLE_STRUCT* VARIABLES = NULL;
  struct TEMPVAR_HOLDER* TEMPS = NULL;
%}

%union {
  char* dataType;
  char charVal;
  int intVal;
  float floatVal;
  char* strVal;
}

%token PRINT
%token SEMI_COLON COMMA SINGLE_QUOTE DOUBLE_QUOTE PLUS_SIGN MINUS_SIGN MULTIPLICATION_SIGN DIVISION_SIGN EQUALS_SIGN BRACKET_OPEN BRACKET_CLOSE
%token CMPR_EQ CMPR_LESS CMPR_MORE CMPR_AND CMPR_OR

%token TRUE_STMT FALSE_STMT NOT
%token AND OR

%token IF THEN ELSE
%token WHILE DO

%token END

%token <dataType> DATA_TYPE
%token <charVal> CHARACTER_VAL
%token <intVal> INTEGER_VAL
%token <floatVal> FLOAT_VAL
%token <strVal> STRING_VAL
%token <strVal> IDENTIFIER ARRAY_IDENTIFIER

%type <strVal> DECLERATION
%type <strVal> EXPRESSION
%type <charVal> BOOLEAN
%type <strVal> DATA

%type <strVal> IFELSE
%type <strVal> WHILEDO
%type <strVal> DECLOOP

%type <strVal> TEXT

%left PLUS_SIGN MINUS_SIGN
%left MULTIPLICATION_SIGN DIVISION_SIGN

%%

DECLERATION     : EXPRESSION SEMI_COLON                       {}
                | DECLERATION EXPRESSION SEMI_COLON           {}
                | EXPRESSION                                  {yyerror("There must be a semicolon ';' after every expression");}
                | DECLERATION EXPRESSION                      {yyerror("There must be a semicolon ';' after every expression");}
                | IFELSE                                      {}
                | DECLERATION IFELSE                          {}
                | WHILEDO                                     {}
                | DECLERATION WHILEDO                         {}
                | SEMI_COLON                                  {}
                | error                                       {}
                | error SEMI_COLON                            {}
                | error END                                   {}
                ;

IFELSE          : IF BOOLEAN THEN {if (top() == 1) {if ($2 == 'B') push(1); else push(0);} else {last = 0; push(0);}} DECLERATION
                  ELSE {if(last == 1){if (top() != 1) push(1); else push(0);} else {push(0);last = 1;}} DECLERATION {pop(); pop();} END {}
                ;

WHILEDO         : WHILE BOOLEAN DO DECLOOP END {}
                ;

DECLOOP         : DECLERATION             {}
                | DECLOOP DECLERATION     {}
                ;

BOOLEAN         : TRUE_STMT                                   {$$ = 'B';}
                | FALSE_STMT                                  {$$ = 'A';}
                | DATA CMPR_EQ DATA                           {
                                                                char* type = GetVarType($1);
                                                                char* type2 = GetVarType($3);
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "char") == 0)
                                                                {
                                                                  if (*(char *)GetVarData($1) == *(char *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "int") == 0)
                                                                {
                                                                  if (*(int *)GetVarData($1) == *(int *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "float") == 0)
                                                                {
                                                                  if (*(float *)GetVarData($1) == *(float *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "string") == 0)
                                                                {
                                                                  if (strcmp((char *)GetVarData($1), (char *)GetVarData($3)) == 0) $$ = 'B'; else $$ = 'A';
                                                                }
                                                              }
                | DATA CMPR_MORE DATA                         {
                                                                char* type = GetVarType($1);
                                                                char* type2 = GetVarType($3);
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "char") == 0)
                                                                {
                                                                  if (*(char *)GetVarData($1) > *(char *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "int") == 0)
                                                                {
                                                                  if (*(int *)GetVarData($1) > *(int *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "float") == 0)
                                                                {
                                                                  if (*(float *)GetVarData($1) > *(float *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "string") == 0)
                                                                {
                                                                  OperationUnavailable('>', "string");
                                                                }
                                                              }
                | DATA CMPR_LESS DATA                         {
                                                                char* type = GetVarType($1);
                                                                char* type2 = GetVarType($3);
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "char") == 0)
                                                                {
                                                                  if (*(char *)GetVarData($1) < *(char *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "int") == 0)
                                                                {
                                                                  if (*(int *)GetVarData($1) < *(int *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "float") == 0)
                                                                {
                                                                  if (*(float *)GetVarData($1) < *(float *)GetVarData($3)) $$ = 'B'; else $$ = 'A';
                                                                }
                                                                else if (strcmp(type, "string"))
                                                                {
                                                                  OperationUnavailable('<', "string");
                                                                }
                                                              }
                | BOOLEAN AND BOOLEAN                         {if ($1 == 'B' && $3 == 'B') $$ = 'B'; else $$ = 'A';}
                | BOOLEAN OR BOOLEAN                          {if ($1 == 'B' || $3 == 'B') $$ = 'B'; else $$ = 'A';}
                | NOT BOOLEAN                                 {if ($2 == 'A') $$ = 'B'; else $$ = 'A';}
                | BRACKET_OPEN BOOLEAN BRACKET_CLOSE          {$$ = $2;}
                ;

EXPRESSION      : DATA_TYPE IDENTIFIER                        {
                                                                if (top() == 1)
                                                                {
                                                                  if (!IsDuplicate($2))
                                                                  {
                                                                    ClearStoredDataType();
                                                                    SetStoredDataType($1);
                                                                    CreateVar($2, $1);
                                                                    SetLastVarname($2);
                                                                  }
                                                                }
                                                              }
                | IDENTIFIER                                  {
                                                                if (top() == 1)
                                                                {
                                                                  if (IsDuplicate($1))
                                                                  {
                                                                    ClearStoredDataType();
                                                                    SetStoredDataType(GetVarType($1));
                                                                    SetLastVarname($1);
                                                                  }
                                                                }
                                                              }
                | EXPRESSION COMMA IDENTIFIER                 {
                                                                if (top() == 1)
                                                                {
                                                                  if (!IsDuplicate($3))
                                                                  {
                                                                    CreateVar($3, GetStoredDataType());
                                                                    SetLastVarname($3);
                                                                  }
                                                                }
                                                              }
                | EXPRESSION EQUALS_SIGN DATA                {
                                                                if (top() == 1)
                                                                {
                                                                  char* type = GetVarType($3);
                                                                  char* expType = GetStoredDataType();
                                                                  if (strcmp(expType, type) != 0) WrongTypeAssignment(expType, type);

                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    SetChar(GetLastVarname(), *(char*)GetVarData($3));
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    SetInt(GetLastVarname(), *(int*)GetVarData($3));
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    SetFloat(GetLastVarname(), *(float*)GetVarData($3));
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    SetString(GetLastVarname(), (char*)GetVarData($3));
                                                                  }
                                                                }
                                                                if (TEMPS != NULL) DestroyTemps();
                                                              }
                | PRINT TEXT                                  {
                                                                if (top() == 1) 
                                                                {
                                                                  char* txt = $2;
                                                                  int ln = strlen(txt);

                                                                  int i = 0;
                                                                  for (i = 0; i < ln; i++)
                                                                  {
                                                                    if (txt[i] == '\\')
                                                                    {
                                                                      if (txt[++i] == 'n')
                                                                      {
                                                                        printf("\n");
                                                                      }
                                                                      else if (txt[i] == 't')
                                                                      {
                                                                        printf("\t");
                                                                      }
                                                                      else
                                                                      {
                                                                        yyerror("'\\' was used but there was no special character after it.");
                                                                      }
                                                                    }
                                                                    else
                                                                    {
                                                                      printf("%c", txt[i]);
                                                                    }
                                                                  }
                                                                }
                                                              }
                ;

TEXT            : CHARACTER_VAL                               {
                                                                char str[2];
                                                                sprintf(str, "%c", $1);
                                                                $$ = str;
                                                              }
                | INTEGER_VAL                                 {
                                                                int len = 0;
                                                                int dec = $1;
                                                                while (dec > 0)
                                                                {
                                                                  len++;
                                                                  dec /= 10;
                                                                }
                                                                char str[len + 1];
                                                                sprintf(str, "%d", $1);
                                                                $$ = str;
                                                              }
                | FLOAT_VAL                                   {
                                                                int len = 0;
                                                                int dec = (int)$1;
                                                                while (dec > 0)
                                                                {
                                                                  len++;
                                                                  dec /= 10;
                                                                }
                                                                char str[len + 12];
                                                                sprintf(str, "%.10f", $1);
                                                                $$ = str;
                                                              }
                | STRING_VAL                                  {;}
                | IDENTIFIER                                  {
                                                                char* type = GetVarType($1);
                                                                if (strcmp(type, "notex") != 0)
                                                                {
                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    char* str = (char *)malloc(sizeof(char) * 2);
                                                                    sprintf(str, "%c", *(char*)GetVarData($1));
                                                                    $$ = str;
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    int len = 0;
                                                                    int dec = *(int*)GetVarData($1);
                                                                    while (dec > 0)
                                                                    {
                                                                      len++;
                                                                      dec /= 10;
                                                                    }
                                                                    char* str = (char *)malloc(sizeof(char) * (len + 6));
                                                                    sprintf(str, "%d", *(int*)GetVarData($1));
                                                                    $$ = str;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    int len = 0;
                                                                    int dec = (int)*(float*)GetVarData($1);
                                                                    while (dec > 0)
                                                                    {
                                                                      len++;
                                                                      dec /= 10;
                                                                    }
                                                                    char* str = (char *)malloc(sizeof(char) * (len + 12));
                                                                    sprintf(str, "%.10f", *(float*)GetVarData($1));
                                                                    $$ = str;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    $$ = (char*)GetVarData($1);
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  UndeclaredVariableUsed($1);
                                                                }
                                                              }
                | TEXT PLUS_SIGN TEXT                         {
                                                                char* endS = $1;
                                                                strcat(endS, $3);
                                                                $$ = endS;
                                                              }
                ;

DATA           : IDENTIFIER                                   {
                                                                char* type = GetVarType($1);
                                                                if (strcmp(type, "notex") != 0)
                                                                {
                                                                  $$ = $1;
                                                                }
                                                                else
                                                                {
                                                                  UndeclaredVariableUsed($1);
                                                                }
                                                              }
                | CHARACTER_VAL                               {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "char");
                                                                SetChar(tmpName, $1);
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                $$ = tempVarName;
                                                              }
                | INTEGER_VAL                                 {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "int");
                                                                SetInt(tmpName, $1);
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                $$ = tempVarName;
                                                              }
                | FLOAT_VAL                                   {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "float");
                                                                SetFloat(tmpName, $1);
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                $$ = tempVarName;
                                                              }
                | STRING_VAL                                  {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "string");
                                                                SetString(tmpName, $1);
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                $$ = tempVarName;
                                                              }
                | DATA PLUS_SIGN DATA                         {
                                                                char* type = GetVarType($1);
                                                                char* type2 = GetVarType($3);
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "notex") != 0 && strcmp(type2, "notex") != 0)
                                                                {
                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    char c = *(char *)GetVarData($1) + *(char *)GetVarData($3);

                                                                    SetChar(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "int");
                                                                    CreateTemp(tmpName);

                                                                    int c = *(int *)GetVarData($1) + *(int *)GetVarData($3);
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "float");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData($1) + *(float *)GetVarData($3);
                                                                    
                                                                    SetFloat(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    char *c = (char *)GetVarData($1);
                                                                    strcat(c, (char *)GetVarData($3));
                                                                    
                                                                    SetString(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                }
                                                              }
                | DATA MINUS_SIGN DATA                        {
                                                                char* type = GetVarType($1);
                                                                char* type2 = GetVarType($3);
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "notex") != 0 && strcmp(type2, "notex") != 0)
                                                                {
                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    char c = *(char *)GetVarData($1) - *(char *)GetVarData($3);

                                                                    SetChar(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "int");
                                                                    CreateTemp(tmpName);

                                                                    int c = *(int *)GetVarData($1) - *(int *)GetVarData($3);
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData($1) - *(float *)GetVarData($3);
                                                                    
                                                                    SetChar(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    OperationUnavailable('-', "string");
                                                                  }
                                                                }
                                                              }
                | DATA MULTIPLICATION_SIGN DATA               {
                                                                char* type = GetVarType($1);
                                                                char* type2 = GetVarType($3);
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "notex") != 0 && strcmp(type2, "notex") != 0)
                                                                {
                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    OperationUnavailable('*', "char");
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "int");
                                                                    CreateTemp(tmpName);

                                                                    int c = *(int *)GetVarData($1) * *(int *)GetVarData($3);
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData($1) * *(float *)GetVarData($3);
                                                                    
                                                                    SetChar(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    OperationUnavailable('*', "string");
                                                                  }
                                                                }
                                                              }
                | DATA DIVISION_SIGN DATA                     {
                                                                char* type = GetVarType($1);
                                                                char* type2 = GetVarType($3);
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "notex") != 0 && strcmp(type2, "notex") != 0)
                                                                {
                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    OperationUnavailable('/', "char");
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "int");
                                                                    CreateTemp(tmpName);

                                                                    int c = *(int *)GetVarData($1) / *(int *)GetVarData($3);
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData($1) / *(float *)GetVarData($3);
                                                                    
                                                                    SetChar(tmpName, c);
                                                                    $$ = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    OperationUnavailable('/', "string");
                                                                  }
                                                                }
                                                              }
                | BRACKET_OPEN DATA BRACKET_CLOSE             {$$ = $2;}
                ;
%%

int main(void)
{
  yyparse();
  return 0;
}

char* GetStoredDataType()
{
  return DataTypeBuffer;
}

void SetStoredDataType(char* type)
{
  strcpy(DataTypeBuffer, type);
}

void ClearStoredDataType()
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    DataTypeBuffer[i] = '\0';
  }
}

int CheckStoredDataType(char* type)
{
  if (strcmp(DataTypeBuffer, type) == 0) return 1;
  return 0;
}

int IsDuplicate(char* varName)
{
  struct VARIABLE_STRUCT* selectedIdentifier = VARIABLES;
  while (selectedIdentifier != NULL)
  {
    if (selectedIdentifier->varName == varName) return 1;
    selectedIdentifier = selectedIdentifier->next;
  }
  return 0;
}

int SetChar(char* varName, char value)
{
  struct VARIABLE_STRUCT* selectedIdentifier = VARIABLES;
  while (selectedIdentifier != NULL)
  {
    if (strcmp(selectedIdentifier->varName, varName) == 0)
    {
      if (strcmp(selectedIdentifier->dataType, "char") == 0)
      {
        *((char*)selectedIdentifier->data) = value;
        return 1;
      }
      else return 0;
    }
    selectedIdentifier = selectedIdentifier->next;
  }
  return 0;
}

int SetInt(char* varName, int value)
{
  struct VARIABLE_STRUCT* selectedIdentifier = VARIABLES;
  while (selectedIdentifier != NULL)
  {
    if (strcmp(selectedIdentifier->varName, varName) == 0)
    {
      if (strcmp(selectedIdentifier->dataType, "int") == 0)
      {
        *((int*)selectedIdentifier->data) = value;
        return 1;
      }
      else return 0;
    }
    selectedIdentifier = selectedIdentifier->next;
  }
  return 0;
}

int SetFloat(char* varName, float value)
{
  struct VARIABLE_STRUCT* selectedIdentifier = VARIABLES;
  while (selectedIdentifier != NULL)
  {
    if (strcmp(selectedIdentifier->varName, varName) == 0)
    {
      if (strcmp(selectedIdentifier->dataType, "float") == 0)
      {
        *((float*)selectedIdentifier->data) = value;
        return 1;
      }
      else return 0;
    }
    selectedIdentifier = selectedIdentifier->next;
  }
  return 0;
}

int SetString(char* varName, char* value)
{
  struct VARIABLE_STRUCT* selectedIdentifier = VARIABLES;
  while (selectedIdentifier != NULL)
  {
    if (strcmp(selectedIdentifier->varName, varName) == 0)
    {
      if (strcmp(selectedIdentifier->dataType, "string") == 0)
      {
        free(selectedIdentifier->data);
        selectedIdentifier->data = malloc(sizeof(char) * (strlen(value) + 1));
        strcpy((char*)(selectedIdentifier->data), value);
        return 1;
      }
      else return 0;
    }
    selectedIdentifier = selectedIdentifier->next;
  }
  return 0;
}

void CreateVar(char* varName, char* dataType)
{
  struct VARIABLE_STRUCT* newVariable = (struct VARIABLE_STRUCT*)malloc(sizeof(struct VARIABLE_STRUCT));
  newVariable->varName = (char*)malloc((strlen(varName) + 1) * sizeof(char));
  strcpy(newVariable->varName, varName);
  newVariable->dataType = dataType;
  
  if (strcmp(dataType, "char"))
  {
    newVariable->data = malloc(sizeof(char));
  }
  else if (strcmp(dataType, "int"))
  {
    newVariable->data = malloc(sizeof(int));
  }
  else if (strcmp(dataType, "float"))
  {
    newVariable->data = malloc(sizeof(float));
  }
  else if (strcmp(dataType, "string"))
  {
    newVariable->data = malloc(sizeof(char));
  }
  newVariable->next = NULL;

  struct VARIABLE_STRUCT** selectedVariable = &VARIABLES;
  while (1)
  {
    if (*selectedVariable == NULL)
    {
      *selectedVariable = newVariable;
      return;
    }
    else
    {
      selectedVariable = &(*selectedVariable)->next;
    }
  }
}

void DeleteVar(char* varName)
{
  struct VARIABLE_STRUCT* cur = VARIABLES, *prev; 
  
  if (cur != NULL && strcmp(cur->varName, varName) == 0) 
  { 
    VARIABLES = cur->next;
    free(cur);
    return; 
  }
  while (cur != NULL && strcmp(cur->varName, varName) != 0) 
  { 
      prev = cur; 
      cur = cur->next; 
  } 
  if (cur == NULL) return; 
  prev->next = cur->next; 

  free(cur);
}

void SetLastVarname (char* name)
{
  LAST_VAR = malloc((1 + strlen(name)) * sizeof(char*));
  strcpy (LAST_VAR, name);
}

char* GetLastVarname ()
{
  if (LAST_VAR == NULL) return '\0';
  return LAST_VAR;
}

void ResetLastVarname ()
{
  free (LAST_VAR);
}

void* GetVarData(char* name)
{
  struct VARIABLE_STRUCT* selectedIdentifier = VARIABLES;
  while (selectedIdentifier != NULL)
  {
    if (strcmp(selectedIdentifier->varName, name) == 0)
    {
      return selectedIdentifier->data;
    }
    selectedIdentifier = selectedIdentifier->next;
  }
  return NULL;
}

char* GetVarType(char* name)
{
  struct VARIABLE_STRUCT* selectedIdentifier = VARIABLES;
  while (selectedIdentifier != NULL)
  {
    if (strcmp(selectedIdentifier->varName, name) == 0)
    {
      return selectedIdentifier->dataType;
    }
    selectedIdentifier = selectedIdentifier->next;
  }
  return "notex";
}

void CreateTemp(char* tmpName)
{
  struct TEMPVAR_HOLDER* newTemp = (struct TEMPVAR_HOLDER*)malloc(sizeof(struct TEMPVAR_HOLDER));
  newTemp->name = tmpName;
  newTemp->next = NULL;

  struct TEMPVAR_HOLDER** selectedTemp = &TEMPS;
  while (1)
  {
    if (*selectedTemp == NULL)
    {
      *selectedTemp = newTemp;
      return;
    }
    else
    {
      selectedTemp = &(*selectedTemp)->next;
    }
  }
}

void DestroyTemps()
{
  
  struct TEMPVAR_HOLDER** selectedTemp = &TEMPS;
  struct TEMPVAR_HOLDER* nextHolder = NULL;
  while (1)
  {
    if (*selectedTemp == NULL)
    {
      return;
    }
    else
    {
      DeleteVar((*selectedTemp)->name);
      nextHolder = (*selectedTemp)->next;
      free(*selectedTemp);
      *selectedTemp = nextHolder;
    }
  }
}

void rand_str(char *s, const int len) {
  static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < len; ++i) {
      s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
  }

  s[len] = 0;
}

int top()
{
  if (bCount == 0) return 1;
  return bools[bCount - 1];
}

void push(int i)
{
  bools[bCount++] = i;
}

void pop()
{
  bools[--bCount] = -1;
}

void WrongTypeAssignment(char* expected, char* received)
{
  char errMsg[100];
  sprintf(errMsg, "Can't assign %s value to %s", received, expected);
  yyerror(errMsg);
}

void VariablesDifferentType(char* type1, char* type2)
{
  char errMsg[100];
  sprintf(errMsg, "Can't do operations between different types of variables. Type1: %s, Type2: %s", type1, type2);
  yyerror(errMsg);
}

void OperationUnavailable(char op, char* type)
{
  char errMsg[100];
  sprintf(errMsg, "Can't use %c operator for %s", op, type);
  yyerror(errMsg);
}

void UndeclaredVariableUsed(char* varName)
{
  char errMsg[100];
  sprintf(errMsg, "Variable %s is not declared and cannot be used", varName);
  yyerror(errMsg);
}

void UndeclaredType()
{
  yyerror("Have to declare type first");
}