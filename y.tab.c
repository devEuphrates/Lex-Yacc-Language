/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mpl.y" /* yacc.c:339  */

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

#line 129 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 64 "mpl.y" /* yacc.c:355  */

  char* dataType;
  char charVal;
  int intVal;
  float floatVal;
  char* strVal;

#line 251 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 268 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  83

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   121,   122,   122,   121,   125,   128,
     129,   132,   133,   134,   156,   178,   200,   201,   202,   203,
     206,   218,   229,   239,   265,   298,   303,   315,   327,   328,
     374,   381,   392,   402,   412,   422,   432,   498,   553,   598,
     643
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "SEMI_COLON", "COMMA",
  "SINGLE_QUOTE", "DOUBLE_QUOTE", "PLUS_SIGN", "MINUS_SIGN",
  "MULTIPLICATION_SIGN", "DIVISION_SIGN", "EQUALS_SIGN", "BRACKET_OPEN",
  "BRACKET_CLOSE", "CMPR_EQ", "CMPR_LESS", "CMPR_MORE", "CMPR_AND",
  "CMPR_OR", "TRUE_STMT", "FALSE_STMT", "NOT", "AND", "OR", "IF", "THEN",
  "ELSE", "WHILE", "DO", "END", "DATA_TYPE", "CHARACTER_VAL",
  "INTEGER_VAL", "FLOAT_VAL", "STRING_VAL", "IDENTIFIER",
  "ARRAY_IDENTIFIER", "$accept", "DECLERATION", "IFELSE", "$@1", "$@2",
  "$@3", "WHILEDO", "DECLOOP", "BOOLEAN", "EXPRESSION", "TEXT", "DATA", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      56,     7,   121,   -36,    85,    85,   -26,   -36,    18,   -36,
     -36,     4,   -36,   -36,   -36,   -36,   -36,   -36,   -36,    16,
      85,   -36,   -36,    85,   -36,   -36,   -36,   -36,   -36,    54,
     124,   123,   -36,   -36,   -36,   -36,    51,   -36,   -24,    77,
     121,   -10,   114,   -18,    85,    85,   -36,    77,    77,    77,
      77,    77,    77,    77,    56,   -36,   -36,    77,   150,   -36,
     -36,   -36,   -18,   -18,    56,    17,    17,   -36,   -36,   150,
     150,   150,    72,    22,   134,    58,   -36,    72,   -36,    56,
      72,   -15,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     0,    10,     0,     0,     0,    31,     0,     6,
       8,     4,    12,    13,    35,    36,    37,    38,    39,    34,
       0,    21,    22,     0,    42,    43,    44,    45,    41,     0,
       0,     0,    30,     1,     7,     9,     5,     2,     0,     0,
       0,     0,     0,    28,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     3,    32,     0,    33,    40,
      29,    50,    26,    27,     0,    46,    47,    48,    49,    23,
      25,    24,    19,     0,     0,     0,    18,    20,    15,     0,
      16,     0,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -35,    -8,   -36,   -36,   -36,    -7,   -36,    -3,    -1,
       5,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    64,    79,    81,    10,    73,    29,    11,
      19,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    35,    31,    42,    60,    44,    45,    36,    37,    38,
      32,    12,    56,    44,    45,    82,    39,    41,    33,    72,
      43,     2,    58,     1,    40,     2,     3,    49,    50,    75,
      65,    66,    67,    68,    69,    70,    71,    13,    77,     0,
      74,    62,    63,     4,    80,    59,     5,     4,     0,     6,
       5,     0,    76,     6,     7,    55,    38,     1,     7,     2,
       3,     2,     0,    39,    34,    35,     0,    34,    35,    34,
      35,    36,    34,    35,    36,     2,    36,    44,    45,    36,
      46,     4,     0,     4,     5,    78,     5,     6,     0,     6,
      57,     0,     7,     0,     7,     0,     0,     4,    20,     0,
       5,     0,     0,     6,     0,    21,    22,    23,     7,    24,
      25,    26,    27,    28,     0,     0,     0,    24,    25,    26,
      27,    28,    47,    48,    49,    50,     0,     0,    61,    51,
      52,    53,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    47,    48,    49,    50,    44,    45,    61,     0,
       0,     0,    54,    14,    15,    16,    17,    18,    47,    48,
      49,    50
};

static const yytype_int8 yycheck[] =
{
       8,     8,     5,    20,    14,    23,    24,     8,     4,     5,
      36,     4,    36,    23,    24,    30,    12,    20,     0,    54,
      23,     3,    39,     1,     8,     3,     4,    10,    11,    64,
      47,    48,    49,    50,    51,    52,    53,    30,    73,    -1,
      57,    44,    45,    25,    79,    40,    28,    25,    -1,    31,
      28,    -1,    30,    31,    36,     4,     5,     1,    36,     3,
       4,     3,    -1,    12,    72,    72,    -1,    75,    75,    77,
      77,    72,    80,    80,    75,     3,    77,    23,    24,    80,
      26,    25,    -1,    25,    28,    27,    28,    31,    -1,    31,
      13,    -1,    36,    -1,    36,    -1,    -1,    25,    13,    -1,
      28,    -1,    -1,    31,    -1,    20,    21,    22,    36,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    32,    33,    34,
      35,    36,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,     8,     9,    10,    11,    23,    24,    14,    -1,
      -1,    -1,    29,    32,    33,    34,    35,    36,     8,     9,
      10,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,    25,    28,    31,    36,    39,    40,
      44,    47,     4,    30,    32,    33,    34,    35,    36,    48,
      13,    20,    21,    22,    32,    33,    34,    35,    36,    46,
      49,    46,    36,     0,    40,    44,    47,     4,     5,    12,
       8,    46,    49,    46,    23,    24,    26,     8,     9,    10,
      11,    15,    16,    17,    29,     4,    36,    13,    49,    48,
      14,    14,    46,    46,    41,    49,    49,    49,    49,    49,
      49,    49,    39,    45,    49,    39,    30,    39,    27,    42,
      39,    43,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    41,    42,    43,    40,    44,    45,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     1,     2,     2,     0,     0,     0,    10,     5,     1,
       2,     1,     1,     3,     3,     3,     3,     3,     2,     3,
       2,     1,     3,     3,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 107 "mpl.y" /* yacc.c:1646  */
    {}
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "mpl.y" /* yacc.c:1646  */
    {}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "mpl.y" /* yacc.c:1646  */
    {yyerror("There must be a semicolon ';' after every expression");}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 110 "mpl.y" /* yacc.c:1646  */
    {yyerror("There must be a semicolon ';' after every expression");}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 111 "mpl.y" /* yacc.c:1646  */
    {}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "mpl.y" /* yacc.c:1646  */
    {}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "mpl.y" /* yacc.c:1646  */
    {}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "mpl.y" /* yacc.c:1646  */
    {}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "mpl.y" /* yacc.c:1646  */
    {}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "mpl.y" /* yacc.c:1646  */
    {}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "mpl.y" /* yacc.c:1646  */
    {}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "mpl.y" /* yacc.c:1646  */
    {}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 121 "mpl.y" /* yacc.c:1646  */
    {if (top() == 1) {if ((yyvsp[-1].charVal) == 'B') push(1); else push(0);} else {last = 0; push(0);}}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 122 "mpl.y" /* yacc.c:1646  */
    {if(last == 1){if (top() != 1) push(1); else push(0);} else {push(0);last = 1;}}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "mpl.y" /* yacc.c:1646  */
    {pop(); pop();}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 122 "mpl.y" /* yacc.c:1646  */
    {}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "mpl.y" /* yacc.c:1646  */
    {}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 128 "mpl.y" /* yacc.c:1646  */
    {}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 129 "mpl.y" /* yacc.c:1646  */
    {}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 132 "mpl.y" /* yacc.c:1646  */
    {(yyval.charVal) = 'B';}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "mpl.y" /* yacc.c:1646  */
    {(yyval.charVal) = 'A';}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 134 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[-2].strVal));
                                                                char* type2 = GetVarType((yyvsp[0].strVal));
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "char") == 0)
                                                                {
                                                                  if (*(char *)GetVarData((yyvsp[-2].strVal)) == *(char *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "int") == 0)
                                                                {
                                                                  if (*(int *)GetVarData((yyvsp[-2].strVal)) == *(int *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "float") == 0)
                                                                {
                                                                  if (*(float *)GetVarData((yyvsp[-2].strVal)) == *(float *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "string") == 0)
                                                                {
                                                                  if (strcmp((char *)GetVarData((yyvsp[-2].strVal)), (char *)GetVarData((yyvsp[0].strVal))) == 0) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                              }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[-2].strVal));
                                                                char* type2 = GetVarType((yyvsp[0].strVal));
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "char") == 0)
                                                                {
                                                                  if (*(char *)GetVarData((yyvsp[-2].strVal)) > *(char *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "int") == 0)
                                                                {
                                                                  if (*(int *)GetVarData((yyvsp[-2].strVal)) > *(int *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "float") == 0)
                                                                {
                                                                  if (*(float *)GetVarData((yyvsp[-2].strVal)) > *(float *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "string") == 0)
                                                                {
                                                                  OperationUnavailable('>', "string");
                                                                }
                                                              }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 178 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[-2].strVal));
                                                                char* type2 = GetVarType((yyvsp[0].strVal));
                                                                if (strcmp(type, type2) != 0) VariablesDifferentType(type, type2);

                                                                if (strcmp(type, "char") == 0)
                                                                {
                                                                  if (*(char *)GetVarData((yyvsp[-2].strVal)) < *(char *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "int") == 0)
                                                                {
                                                                  if (*(int *)GetVarData((yyvsp[-2].strVal)) < *(int *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "float") == 0)
                                                                {
                                                                  if (*(float *)GetVarData((yyvsp[-2].strVal)) < *(float *)GetVarData((yyvsp[0].strVal))) (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';
                                                                }
                                                                else if (strcmp(type, "string"))
                                                                {
                                                                  OperationUnavailable('<', "string");
                                                                }
                                                              }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 200 "mpl.y" /* yacc.c:1646  */
    {if ((yyvsp[-2].charVal) == 'B' && (yyvsp[0].charVal) == 'B') (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "mpl.y" /* yacc.c:1646  */
    {if ((yyvsp[-2].charVal) == 'B' || (yyvsp[0].charVal) == 'B') (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 202 "mpl.y" /* yacc.c:1646  */
    {if ((yyvsp[0].charVal) == 'A') (yyval.charVal) = 'B'; else (yyval.charVal) = 'A';}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 203 "mpl.y" /* yacc.c:1646  */
    {(yyval.charVal) = (yyvsp[-1].charVal);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 206 "mpl.y" /* yacc.c:1646  */
    {
                                                                if (top() == 1)
                                                                {
                                                                  if (!IsDuplicate((yyvsp[0].strVal)))
                                                                  {
                                                                    ClearStoredDataType();
                                                                    SetStoredDataType((yyvsp[-1].dataType));
                                                                    CreateVar((yyvsp[0].strVal), (yyvsp[-1].dataType));
                                                                    SetLastVarname((yyvsp[0].strVal));
                                                                  }
                                                                }
                                                              }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 218 "mpl.y" /* yacc.c:1646  */
    {
                                                                if (top() == 1)
                                                                {
                                                                  if (IsDuplicate((yyvsp[0].strVal)))
                                                                  {
                                                                    ClearStoredDataType();
                                                                    SetStoredDataType(GetVarType((yyvsp[0].strVal)));
                                                                    SetLastVarname((yyvsp[0].strVal));
                                                                  }
                                                                }
                                                              }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 229 "mpl.y" /* yacc.c:1646  */
    {
                                                                if (top() == 1)
                                                                {
                                                                  if (!IsDuplicate((yyvsp[0].strVal)))
                                                                  {
                                                                    CreateVar((yyvsp[0].strVal), GetStoredDataType());
                                                                    SetLastVarname((yyvsp[0].strVal));
                                                                  }
                                                                }
                                                              }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 239 "mpl.y" /* yacc.c:1646  */
    {
                                                                if (top() == 1)
                                                                {
                                                                  char* type = GetVarType((yyvsp[0].strVal));
                                                                  char* expType = GetStoredDataType();
                                                                  if (strcmp(expType, type) != 0) WrongTypeAssignment(expType, type);

                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    SetChar(GetLastVarname(), *(char*)GetVarData((yyvsp[0].strVal)));
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    SetInt(GetLastVarname(), *(int*)GetVarData((yyvsp[0].strVal)));
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    SetFloat(GetLastVarname(), *(float*)GetVarData((yyvsp[0].strVal)));
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    SetString(GetLastVarname(), (char*)GetVarData((yyvsp[0].strVal)));
                                                                  }
                                                                }
                                                                if (TEMPS != NULL) DestroyTemps();
                                                              }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 265 "mpl.y" /* yacc.c:1646  */
    {
                                                                if (top() == 1) 
                                                                {
                                                                  char* txt = (yyvsp[0].strVal);
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
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 298 "mpl.y" /* yacc.c:1646  */
    {
                                                                char str[2];
                                                                sprintf(str, "%c", (yyvsp[0].charVal));
                                                                (yyval.strVal) = str;
                                                              }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 303 "mpl.y" /* yacc.c:1646  */
    {
                                                                int len = 0;
                                                                int dec = (yyvsp[0].intVal);
                                                                while (dec > 0)
                                                                {
                                                                  len++;
                                                                  dec /= 10;
                                                                }
                                                                char str[len + 1];
                                                                sprintf(str, "%d", (yyvsp[0].intVal));
                                                                (yyval.strVal) = str;
                                                              }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 315 "mpl.y" /* yacc.c:1646  */
    {
                                                                int len = 0;
                                                                int dec = (int)(yyvsp[0].floatVal);
                                                                while (dec > 0)
                                                                {
                                                                  len++;
                                                                  dec /= 10;
                                                                }
                                                                char str[len + 12];
                                                                sprintf(str, "%.10f", (yyvsp[0].floatVal));
                                                                (yyval.strVal) = str;
                                                              }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 327 "mpl.y" /* yacc.c:1646  */
    {;}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 328 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[0].strVal));
                                                                if (strcmp(type, "notex") != 0)
                                                                {
                                                                  if (strcmp(type, "char") == 0)
                                                                  {
                                                                    char* str = (char *)malloc(sizeof(char) * 2);
                                                                    sprintf(str, "%c", *(char*)GetVarData((yyvsp[0].strVal)));
                                                                    (yyval.strVal) = str;
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    int len = 0;
                                                                    int dec = *(int*)GetVarData((yyvsp[0].strVal));
                                                                    while (dec > 0)
                                                                    {
                                                                      len++;
                                                                      dec /= 10;
                                                                    }
                                                                    char* str = (char *)malloc(sizeof(char) * (len + 6));
                                                                    sprintf(str, "%d", *(int*)GetVarData((yyvsp[0].strVal)));
                                                                    (yyval.strVal) = str;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    int len = 0;
                                                                    int dec = (int)*(float*)GetVarData((yyvsp[0].strVal));
                                                                    while (dec > 0)
                                                                    {
                                                                      len++;
                                                                      dec /= 10;
                                                                    }
                                                                    char* str = (char *)malloc(sizeof(char) * (len + 12));
                                                                    sprintf(str, "%.10f", *(float*)GetVarData((yyvsp[0].strVal)));
                                                                    (yyval.strVal) = str;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    (yyval.strVal) = (char*)GetVarData((yyvsp[0].strVal));
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  UndeclaredVariableUsed((yyvsp[0].strVal));
                                                                }
                                                              }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 374 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* endS = (yyvsp[-2].strVal);
                                                                strcat(endS, (yyvsp[0].strVal));
                                                                (yyval.strVal) = endS;
                                                              }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 381 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[0].strVal));
                                                                if (strcmp(type, "notex") != 0)
                                                                {
                                                                  (yyval.strVal) = (yyvsp[0].strVal);
                                                                }
                                                                else
                                                                {
                                                                  UndeclaredVariableUsed((yyvsp[0].strVal));
                                                                }
                                                              }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "mpl.y" /* yacc.c:1646  */
    {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "char");
                                                                SetChar(tmpName, (yyvsp[0].charVal));
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                (yyval.strVal) = tempVarName;
                                                              }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 402 "mpl.y" /* yacc.c:1646  */
    {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "int");
                                                                SetInt(tmpName, (yyvsp[0].intVal));
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                (yyval.strVal) = tempVarName;
                                                              }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 412 "mpl.y" /* yacc.c:1646  */
    {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "float");
                                                                SetFloat(tmpName, (yyvsp[0].floatVal));
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                (yyval.strVal) = tempVarName;
                                                              }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 422 "mpl.y" /* yacc.c:1646  */
    {
                                                                rand_str(tmpRand, 5);
                                                                sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                CreateVar(tmpName, "string");
                                                                SetString(tmpName, (yyvsp[0].strVal));
                                                                char * tempVarName = (char *)malloc((strlen(tmpName) + 1) * sizeof(char));
                                                                strcpy(tempVarName, tmpName);
                                                                CreateTemp(tempVarName);
                                                                (yyval.strVal) = tempVarName;
                                                              }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 432 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[-2].strVal));
                                                                char* type2 = GetVarType((yyvsp[0].strVal));
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

                                                                    char c = *(char *)GetVarData((yyvsp[-2].strVal)) + *(char *)GetVarData((yyvsp[0].strVal));

                                                                    SetChar(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "int");
                                                                    CreateTemp(tmpName);

                                                                    int c = *(int *)GetVarData((yyvsp[-2].strVal)) + *(int *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "float");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData((yyvsp[-2].strVal)) + *(float *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetFloat(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    char *c = (char *)GetVarData((yyvsp[-2].strVal));
                                                                    strcat(c, (char *)GetVarData((yyvsp[0].strVal)));
                                                                    
                                                                    SetString(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                }
                                                              }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 498 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[-2].strVal));
                                                                char* type2 = GetVarType((yyvsp[0].strVal));
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

                                                                    char c = *(char *)GetVarData((yyvsp[-2].strVal)) - *(char *)GetVarData((yyvsp[0].strVal));

                                                                    SetChar(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "int") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "int");
                                                                    CreateTemp(tmpName);

                                                                    int c = *(int *)GetVarData((yyvsp[-2].strVal)) - *(int *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData((yyvsp[-2].strVal)) - *(float *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetChar(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    OperationUnavailable('-', "string");
                                                                  }
                                                                }
                                                              }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 553 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[-2].strVal));
                                                                char* type2 = GetVarType((yyvsp[0].strVal));
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

                                                                    int c = *(int *)GetVarData((yyvsp[-2].strVal)) * *(int *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData((yyvsp[-2].strVal)) * *(float *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetChar(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    OperationUnavailable('*', "string");
                                                                  }
                                                                }
                                                              }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 598 "mpl.y" /* yacc.c:1646  */
    {
                                                                char* type = GetVarType((yyvsp[-2].strVal));
                                                                char* type2 = GetVarType((yyvsp[0].strVal));
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

                                                                    int c = *(int *)GetVarData((yyvsp[-2].strVal)) / *(int *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetInt(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "float") == 0)
                                                                  {
                                                                    char tmpRand[6];
                                                                    rand_str(tmpRand, 5);
                                                                    char tmpName[11];
                                                                    sprintf(tmpName, "%s%s", "TEMP_", tmpRand);
                                                                    CreateVar(tmpName, "char");
                                                                    CreateTemp(tmpName);

                                                                    float c = *(float *)GetVarData((yyvsp[-2].strVal)) / *(float *)GetVarData((yyvsp[0].strVal));
                                                                    
                                                                    SetChar(tmpName, c);
                                                                    (yyval.strVal) = tmpName;
                                                                  }
                                                                  else if (strcmp(type, "string") == 0)
                                                                  {
                                                                    OperationUnavailable('/', "string");
                                                                  }
                                                                }
                                                              }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 643 "mpl.y" /* yacc.c:1646  */
    {(yyval.strVal) = (yyvsp[-1].strVal);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2188 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 645 "mpl.y" /* yacc.c:1906  */


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
