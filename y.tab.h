/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINT = 258,
    SEMI_COLON = 259,
    COMMA = 260,
    SINGLE_QUOTE = 261,
    DOUBLE_QUOTE = 262,
    PLUS_SIGN = 263,
    MINUS_SIGN = 264,
    MULTIPLICATION_SIGN = 265,
    DIVISION_SIGN = 266,
    EQUALS_SIGN = 267,
    BRACKET_OPEN = 268,
    BRACKET_CLOSE = 269,
    CMPR_EQ = 270,
    CMPR_LESS = 271,
    CMPR_MORE = 272,
    CMPR_AND = 273,
    CMPR_OR = 274,
    TRUE_STMT = 275,
    FALSE_STMT = 276,
    NOT = 277,
    AND = 278,
    OR = 279,
    IF = 280,
    THEN = 281,
    ELSE = 282,
    WHILE = 283,
    DO = 284,
    END = 285,
    DATA_TYPE = 286,
    CHARACTER_VAL = 287,
    INTEGER_VAL = 288,
    FLOAT_VAL = 289,
    STRING_VAL = 290,
    IDENTIFIER = 291,
    ARRAY_IDENTIFIER = 292
  };
#endif
/* Tokens.  */
#define PRINT 258
#define SEMI_COLON 259
#define COMMA 260
#define SINGLE_QUOTE 261
#define DOUBLE_QUOTE 262
#define PLUS_SIGN 263
#define MINUS_SIGN 264
#define MULTIPLICATION_SIGN 265
#define DIVISION_SIGN 266
#define EQUALS_SIGN 267
#define BRACKET_OPEN 268
#define BRACKET_CLOSE 269
#define CMPR_EQ 270
#define CMPR_LESS 271
#define CMPR_MORE 272
#define CMPR_AND 273
#define CMPR_OR 274
#define TRUE_STMT 275
#define FALSE_STMT 276
#define NOT 277
#define AND 278
#define OR 279
#define IF 280
#define THEN 281
#define ELSE 282
#define WHILE 283
#define DO 284
#define END 285
#define DATA_TYPE 286
#define CHARACTER_VAL 287
#define INTEGER_VAL 288
#define FLOAT_VAL 289
#define STRING_VAL 290
#define IDENTIFIER 291
#define ARRAY_IDENTIFIER 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 64 "mpl.y" /* yacc.c:1909  */

  char* dataType;
  char charVal;
  int intVal;
  float floatVal;
  char* strVal;

#line 136 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
