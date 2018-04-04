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
#line 5 "parser.y" /* yacc.c:339  */

#include "ast.h"
#include <stdio.h>
#include <list>
#include <iostream>
#include <string>
using namespace std;
int yylex();
extern int yylineno;

void yyerror(const char* msg){
    printf("%s  in Line : %d\n",msg,yylineno);
}

BlockStatement *statement;

#define YYERROR_VERBOSE 1  

#line 85 "parser.cpp" /* yacc.c:339  */

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
   by #include "tokens.h".  */
#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y" /* yacc.c:355  */

    #include "ast.h"

#line 119 "parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_NUM = 258,
    TK_TRUE = 259,
    TK_FALSE = 260,
    TK_ID = 261,
    STRING_LITERAL = 262,
    TK_EOL = 263,
    TK_INC = 264,
    TK_DEC = 265,
    TK_SHIFT_RIGHT = 266,
    TK_SHIFT_LEFT = 267,
    TK_EQUALS = 268,
    TK_NOT_EQUALS = 269,
    TK_LESS_THAN_EQUALS = 270,
    TK_GREATER_THAN_EQUALS = 271,
    TK_IN = 272,
    TK_LOGICAL_AND = 273,
    TL_LOGICAL_OR = 274,
    TK_DOUBLE_COLON = 275,
    TK_ADD_ASGN = 276,
    TK_SUB_ASGN = 277,
    TK_MULT_ASGN = 278,
    TK_DIV_ASGN = 279,
    TK_MOD_ASGN = 280,
    TK_POW_ASGN = 281,
    TK_BIT_AND_ASGN = 282,
    TK_PRINT = 283,
    TK_PRINTLN = 284,
    TK_BOOL = 285,
    TK_INT = 286,
    TK_IF = 287,
    TK_ELSE = 288,
    TK_ELSEIF = 289,
    TK_WHILE = 290,
    TK_FOR = 291,
    TK_FUNCTION = 292,
    TK_RETURN = 293,
    TK_BIT_XOR_ASGN = 294,
    TK_BIT_OR_ASGN = 295,
    TK_ARRAY = 296,
    TK_END = 297,
    TK_ERROR = 298,
    TK_BREAK = 299,
    TK_CONTINUE = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "parser.y" /* yacc.c:355  */

    char *charPointer_t;
    int  int_t;
    bool bool_t;
    Statement *statement_t;
	BlockStatement *blkstatement_t;
    Expr *expr_t;
    ExprList *exprlist_t;
    primitiveType primitiveType_t;

#line 188 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 205 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,     2,    57,    65,    58,     2,
      47,    48,    63,    62,    49,    61,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    46,
      60,    50,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    56,    54,    67,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    57,    58,    59,    62,    63,    67,    68,
      71,    72,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    98,   101,   104,   107,   110,   111,   113,   114,   117,
     118,   121,   124,   125,   129,   130,   133,   134,   137,   138,
     141,   144,   145,   146,   149,   152,   153,   156,   159,   160,
     163,   164,   167,   168,   171,   172,   175,   178,   179,   182,
     185,   186,   187,   188,   189,   190,   191,   192,   195,   196,
     199,   200,   203,   204,   207,   208,   211,   212,   214,   215,
     216,   217,   218,   219,   220,   223,   224,   225,   228,   229,
     230,   233,   234,   235,   236,   239,   240,   243,   244,   245,
     246,   247,   250,   251,   252,   253,   256,   257,   258,   259,
     260
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_TRUE", "TK_FALSE", "TK_ID",
  "STRING_LITERAL", "TK_EOL", "TK_INC", "TK_DEC", "TK_SHIFT_RIGHT",
  "TK_SHIFT_LEFT", "TK_EQUALS", "TK_NOT_EQUALS", "TK_LESS_THAN_EQUALS",
  "TK_GREATER_THAN_EQUALS", "TK_IN", "TK_LOGICAL_AND", "TL_LOGICAL_OR",
  "TK_DOUBLE_COLON", "TK_ADD_ASGN", "TK_SUB_ASGN", "TK_MULT_ASGN",
  "TK_DIV_ASGN", "TK_MOD_ASGN", "TK_POW_ASGN", "TK_BIT_AND_ASGN",
  "TK_PRINT", "TK_PRINTLN", "TK_BOOL", "TK_INT", "TK_IF", "TK_ELSE",
  "TK_ELSEIF", "TK_WHILE", "TK_FOR", "TK_FUNCTION", "TK_RETURN",
  "TK_BIT_XOR_ASGN", "TK_BIT_OR_ASGN", "TK_ARRAY", "TK_END", "TK_ERROR",
  "TK_BREAK", "TK_CONTINUE", "';'", "'('", "')'", "','", "'='", "'['",
  "']'", "'{'", "'}'", "':'", "'|'", "'$'", "'&'", "'>'", "'<'", "'-'",
  "'+'", "'*'", "'/'", "'%'", "'^'", "'~'", "'!'", "$accept", "start",
  "new_line", "opEols", "statementList", "function_statement_list",
  "statement", "fun_statement", "return_statement", "break_statement",
  "continue_statement", "function_statement", "function_type",
  "op_param_list", "param_list", "param", "declaration_statement",
  "op_decAsgn", "arr_type", "type", "if_statement", "elseif",
  "for_statement", "for_tk", "while_statement", "block_statement",
  "print_statement", "print_arguments", "print_argument",
  "expression_statement", "argument_expression_list", "expression",
  "assign_exp", "conditional_or_exp", "conditional_and_exp", "bit_or_exp",
  "bit_xor_exp", "bit_and_exp", "relational_expr", "aritmethic",
  "shift_exp", "term", "exponent", "unary_exp", "post_id", "factor", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    59,    40,    41,    44,
      61,    91,    93,   123,   125,    58,   124,    36,    38,    62,
      60,    45,    43,    42,    47,    37,    94,   126,    33
};
# endif

#define YYPACT_NINF -138

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-138)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,  -138,  -138,    18,    21,   121,  -138,  -138,  -138,  -138,
    -138,   -12,    -5,    51,    48,    48,    95,    97,    48,  -138,
    -138,    48,    48,    48,    48,    48,    -3,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
      89,    94,    65,    75,    83,    33,   -35,    22,   -27,    80,
    -138,   231,  -138,   -11,   130,    48,   117,   119,   157,   157,
     -26,   168,   168,     0,   134,  -138,   142,  -138,  -138,  -138,
    -138,  -138,    52,  -138,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    -138,  -138,   153,  -138,   131,  -138,   161,   166,    48,  -138,
    -138,   136,  -138,  -138,   138,    -3,   -10,   180,  -138,  -138,
      48,   217,  -138,  -138,    94,    65,    75,    83,    33,   -35,
     -35,   -35,   -35,   -35,   -35,    22,    22,   -27,   -27,    80,
      80,    80,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
     163,  -138,    48,  -138,    48,  -138,  -138,   157,  -138,   204,
     168,    48,  -138,  -138,  -138,   171,   207,   182,   188,  -138,
     177,   184,  -138,   -21,  -138,    -3,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,   199,   168,    48,   170,
    -138,   207,   217,  -138,  -138,  -138,   167,  -138,  -138,   -10,
     168,   168,  -138,  -138,  -138,  -138,   201,   202,  -138,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     4,     5,     0,     6,     0,     1,     3,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,     0,     0,     0,     7,     9,    21,    19,
      20,    14,    13,    18,    17,    16,    12,    15,    66,    69,
      77,    79,    81,    83,    85,    87,    94,    97,   100,   104,
     106,   111,   112,     0,     0,     0,     0,    45,     0,     0,
     119,     0,     0,     0,     0,    31,     0,   107,   111,   109,
     108,   110,     6,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,    48,     0,   114,     0,    68,     0,     0,     0,    42,
      64,     0,    63,    65,     0,     7,     0,     0,    56,    55,
       0,    38,   120,     8,    78,    80,    82,    84,    86,    88,
      89,    93,    92,    90,    91,    95,    96,    99,    98,   101,
     102,   103,   105,    71,    72,    73,    74,    75,    76,    70,
       0,   113,     0,   115,     0,    44,    60,     0,    61,    59,
       0,     0,    53,    50,    57,     0,     0,     0,    37,    40,
       0,     0,    67,     0,    62,     7,    11,    30,    28,    29,
      23,    27,    26,    25,    22,    24,     0,     0,     0,     0,
      41,    36,     0,    47,    46,    43,     6,    58,    52,     0,
       0,     0,    35,    39,    10,    51,     0,     0,    54,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,   -23,   -24,  -138,  -138,   173,    50,  -137,   -74,
     -73,  -138,  -138,  -138,  -138,    55,   -59,  -138,  -138,   -84,
     -57,    68,   -54,  -138,   -48,   -56,   -42,   191,   111,   -41,
     115,   -14,   165,  -138,   196,   205,   203,   206,   208,   194,
     135,   128,    39,    -9,   -13,  -138
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    26,   175,    27,   176,    28,    29,
      30,    31,   201,   167,   168,   169,    32,   109,    56,    57,
      33,   163,    34,   120,    35,   116,    36,   111,   112,    37,
     104,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    62,    73,    72,    65,     1,   117,    66,    53,    68,
      68,    68,    68,    67,    69,    70,    71,   118,     6,   100,
     101,    54,   177,   160,   161,    55,    85,    86,   152,     7,
     102,   195,   162,    87,    88,    54,    89,    90,    91,    55,
     105,   106,    58,     2,   113,   113,    79,    80,    81,    82,
     119,     8,     9,    10,    60,     8,     9,    10,    11,   177,
       7,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      12,    13,   190,   142,    14,   178,   179,    15,    16,    17,
      18,   159,    83,    84,   155,    21,    19,    20,    59,    21,
     180,    63,   181,    64,   186,   182,   165,   202,    74,    22,
      23,   183,    75,    22,    23,    24,    25,   184,   185,    24,
      25,    76,   178,   179,     8,     9,    10,    11,   139,   140,
     141,   199,    77,     8,     9,    10,    60,   180,   172,   181,
     105,    78,   182,   113,   206,   207,    92,   187,   183,    12,
      13,   197,   196,    14,   184,   185,    15,    16,    17,    18,
       8,     9,    10,    60,   110,    19,    20,   107,    21,   108,
       8,     9,    10,    11,   200,     7,   115,    21,   103,   151,
     152,   121,    22,    23,   156,   157,   158,   157,    24,    25,
     122,    22,    23,   170,   171,    12,    13,    24,    25,    14,
     100,   101,    15,    16,    21,    18,   150,     8,     9,    10,
      11,    19,    20,   153,    21,   137,   138,   154,    22,    23,
     135,   136,   164,   166,    24,    25,   188,   189,    22,    23,
     191,   193,    12,    13,    24,    25,    14,   192,   194,    15,
      16,   198,    18,   208,   209,   123,   204,   203,    19,    20,
     114,    21,    93,    94,    95,    96,    97,    98,   143,   144,
     145,   146,   147,   148,   149,    22,    23,   205,   174,   173,
     124,    24,    25,   129,   130,   131,   132,   133,   134,   126,
     125,    99,     0,   127,     0,     0,   128
};

static const yytype_int16 yycheck[] =
{
      14,    15,    26,    26,    18,     8,    62,    21,    20,    22,
      23,    24,    25,    22,    23,    24,    25,    17,     0,    30,
      31,    47,   159,    33,    34,    51,    61,    62,    49,     8,
      41,    52,    42,    11,    12,    47,    63,    64,    65,    51,
      54,    55,    47,    46,    58,    59,    13,    14,    15,    16,
      50,     3,     4,     5,     6,     3,     4,     5,     6,   196,
       8,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      28,    29,   166,    92,    32,   159,   159,    35,    36,    37,
      38,   115,    59,    60,   108,    47,    44,    45,    47,    47,
     159,     6,   159,     6,   160,   159,   120,   191,    19,    61,
      62,   159,    18,    61,    62,    67,    68,   159,   159,    67,
      68,    56,   196,   196,     3,     4,     5,     6,    89,    90,
      91,   187,    57,     3,     4,     5,     6,   196,   152,   196,
     154,    58,   196,   157,   200,   201,    66,   161,   196,    28,
      29,   175,   175,    32,   196,   196,    35,    36,    37,    38,
       3,     4,     5,     6,     7,    44,    45,    50,    47,    50,
       3,     4,     5,     6,   188,     8,     8,    47,    48,    48,
      49,    47,    61,    62,    48,    49,    48,    49,    67,    68,
      48,    61,    62,    30,    31,    28,    29,    67,    68,    32,
      30,    31,    35,    36,    47,    38,    53,     3,     4,     5,
       6,    44,    45,    52,    47,    87,    88,    51,    61,    62,
      85,    86,    42,     6,    67,    68,    55,    20,    61,    62,
      48,    54,    28,    29,    67,    68,    32,    49,    54,    35,
      36,    42,    38,    42,    42,    72,   196,   192,    44,    45,
      59,    47,    21,    22,    23,    24,    25,    26,    93,    94,
      95,    96,    97,    98,    99,    61,    62,   199,   157,   154,
      74,    67,    68,    79,    80,    81,    82,    83,    84,    76,
      75,    50,    -1,    77,    -1,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    46,    70,    71,    72,     0,     8,     3,     4,
       5,     6,    28,    29,    32,    35,    36,    37,    38,    44,
      45,    47,    61,    62,    67,    68,    73,    75,    77,    78,
      79,    80,    85,    89,    91,    93,    95,    98,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    20,    47,    51,    87,    88,    47,    47,
       6,   100,   100,     6,     6,   100,   100,   112,   113,   112,
     112,   112,    71,    72,    19,    18,    56,    57,    58,    13,
      14,    15,    16,    59,    60,    61,    62,    11,    12,    63,
      64,    65,    66,    21,    22,    23,    24,    25,    26,    50,
      30,    31,    41,    48,    99,   100,   100,    50,    50,    86,
       7,    96,    97,   100,    96,     8,    94,    94,    17,    50,
      92,    47,    48,    75,   103,   104,   105,   106,   107,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   112,   101,   101,   101,   101,   101,   101,   101,
      53,    48,    49,    52,    51,   100,    48,    49,    48,    72,
      33,    34,    42,    90,    42,   100,     6,    82,    83,    84,
      30,    31,   100,    99,    97,    74,    76,    77,    78,    79,
      85,    89,    91,    93,    95,    98,    94,   100,    55,    20,
      88,    48,    49,    54,    54,    52,    71,    72,    42,    94,
     100,    81,    88,    84,    76,    90,    94,    94,    42,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    78,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      89,    90,    90,    90,    91,    92,    92,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    98,    99,    99,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   113,   113,   113,   113,   114,   114,   114,   114,
     114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     8,     1,     0,     1,     0,     3,
       1,     2,     3,     6,     2,     0,     5,     5,     2,     2,
       4,     4,     3,     1,     8,     1,     1,     4,     4,     2,
       4,     4,     3,     1,     1,     1,     1,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     2,     2,     2,
       2,     1,     1,     4,     3,     4,     1,     1,     1,     1,
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
#line 54 "parser.y" /* yacc.c:1646  */
    {statement = (yyvsp[-1].blkstatement_t);}
#line 1462 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 67 "parser.y" /* yacc.c:1646  */
    { (yyval.blkstatement_t) = (yyvsp[-2].blkstatement_t); (yyval.blkstatement_t)->add((yyvsp[0].statement_t)); }
#line 1468 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 68 "parser.y" /* yacc.c:1646  */
    { (yyval.blkstatement_t) = new BlockStatement; (yyval.blkstatement_t)->add((yyvsp[0].statement_t)); }
#line 1474 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "parser.y" /* yacc.c:1646  */
    { (yyval.blkstatement_t) = (yyvsp[-2].blkstatement_t); (yyval.blkstatement_t)->add((yyvsp[0].statement_t)); }
#line 1480 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 72 "parser.y" /* yacc.c:1646  */
    { (yyval.blkstatement_t) = new BlockStatement; (yyval.blkstatement_t)->add((yyvsp[0].statement_t));}
#line 1486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 75 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1498 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1504 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1516 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1522 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1534 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1546 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1552 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1564 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new ReturnStatement((yyvsp[0].expr_t)); }
#line 1606 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new BreakStatement();}
#line 1612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new ContinueStatement();}
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.statement_t) = new FunctionStatement(string((yyvsp[-6].charPointer_t)),(yyvsp[-4].exprlist_t),(yyvsp[-2].primitiveType_t),(yyvsp[-1].statement_t)); delete (yyvsp[-6].charPointer_t);}
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.primitiveType_t) = (yyvsp[0].primitiveType_t);}
#line 1630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.primitiveType_t) =primitiveType::VOID_TYPE; }
#line 1636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.exprlist_t) = (yyvsp[0].exprlist_t);}
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.exprlist_t) =new ExprList;}
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].exprlist_t)->push_back((yyvsp[0].expr_t)); (yyval.exprlist_t)=(yyvsp[-2].exprlist_t);}
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 118 "parser.y" /* yacc.c:1646  */
    {auto exl= new ExprList; exl->push_back((yyvsp[0].expr_t)); (yyval.exprlist_t)=exl;}
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new ParamExpr(string((yyvsp[-1].charPointer_t)),(yyvsp[0].primitiveType_t)); delete (yyvsp[-1].charPointer_t);}
#line 1666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new DeclarationStatement(string((yyvsp[-2].charPointer_t)),(yyvsp[-1].primitiveType_t),(yyvsp[0].expr_t)); delete (yyvsp[-2].charPointer_t);}
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new DeclarationStatement(string((yyvsp[-5].charPointer_t)),(yyvsp[-4].primitiveType_t),new ArrayExpr((yyvsp[-1].exprlist_t))); delete (yyvsp[-5].charPointer_t);}
#line 1678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new NumberExpr(0);}
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.primitiveType_t) = primitiveType::ARRAY_INT_TYPE;}
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.primitiveType_t) = primitiveType::ARRAY_BOOL_TYPE;}
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.primitiveType_t) = primitiveType::INT_TYPE;}
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.primitiveType_t) = primitiveType::BOOL_TYPE;}
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new IfStatement((yyvsp[-2].expr_t),(yyvsp[-1].statement_t),(yyvsp[0].statement_t));}
#line 1720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new IfStatement((yyvsp[-2].expr_t),(yyvsp[-1].statement_t),(yyvsp[0].statement_t));}
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[-1].statement_t);}
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t)=NULL;}
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t)= new ForStatement(string((yyvsp[-6].charPointer_t)),(yyvsp[-4].expr_t),(yyvsp[-2].expr_t),(yyvsp[-1].statement_t)); delete (yyvsp[-6].charPointer_t);}
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new WhileStatement((yyvsp[-2].expr_t),(yyvsp[-1].statement_t));}
#line 1750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = (yyvsp[-1].blkstatement_t);}
#line 1756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 160 "parser.y" /* yacc.c:1646  */
    { auto bs = new BlockStatement(); bs->stList = list<Statement*>(); (yyval.statement_t) = new BlockStatement();}
#line 1762 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new PrintStatement((yyvsp[-1].exprlist_t),false);}
#line 1768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new PrintStatement((yyvsp[-1].exprlist_t),true);}
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].exprlist_t)->push_back((yyvsp[0].expr_t)); (yyval.exprlist_t)=(yyvsp[-2].exprlist_t); }
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 168 "parser.y" /* yacc.c:1646  */
    {auto exl= new ExprList; exl->push_back((yyvsp[0].expr_t)); (yyval.exprlist_t)=exl;}
#line 1786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new StringExpr(string((yyvsp[0].charPointer_t))); delete (yyvsp[0].charPointer_t);}
#line 1792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_t) = new ExprStatement((yyvsp[0].expr_t));}
#line 1804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].exprlist_t)->push_back((yyvsp[0].expr_t)); (yyval.exprlist_t)=(yyvsp[-2].exprlist_t); }
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 179 "parser.y" /* yacc.c:1646  */
    {auto exl= new ExprList; exl->push_back((yyvsp[0].expr_t)); (yyval.exprlist_t)=exl;}
#line 1816 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1822 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t),new AddExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t)));}
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t),new SubExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t)));}
#line 1840 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t),new MulExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t)));}
#line 1846 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t),new DivExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t)));}
#line 1852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 190 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t),new ModExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t)));}
#line 1858 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AssignExpr((yyvsp[-2].expr_t),new ExponentExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t)));}
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LogicalOrExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) =(yyvsp[0].expr_t);}
#line 1882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LogicalAndExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BitOrExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) =(yyvsp[0].expr_t);}
#line 1906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BitXorExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1912 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) =(yyvsp[0].expr_t);}
#line 1918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BitAndExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new EqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1936 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new NotEqualExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1942 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new GreaterThanExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1948 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LessThanExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new GreaterThanEqualsExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LessThanEqualsExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1966 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) =(yyvsp[0].expr_t);}
#line 1972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new SubExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AddExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LeftShiftExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1996 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 229 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new RightShiftExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2002 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t);}
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new MulExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2014 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new DivExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2020 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t) = new ModExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2026 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 2032 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new ExponentExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2038 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 2044 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new UnarySubExpr(new MulExpr((yyvsp[0].expr_t),new NumberExpr(-1)));}
#line 2050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new UnaryNotExpr((yyvsp[0].expr_t));}
#line 2056 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new UnaryAddExpr((yyvsp[0].expr_t));}
#line 2062 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new UnaryDistintExpr((yyvsp[0].expr_t));}
#line 2068 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 2074 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 2080 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new ParenthesisPosIdExpr(string((yyvsp[-3].charPointer_t)),(yyvsp[-1].exprlist_t)); delete (yyvsp[-3].charPointer_t);}
#line 2086 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new ParenthesisPosIdExpr(string((yyvsp[-2].charPointer_t))); delete (yyvsp[-2].charPointer_t);}
#line 2092 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BracketPostIdExpr(string((yyvsp[-3].charPointer_t)),(yyvsp[-1].expr_t)); delete (yyvsp[-3].charPointer_t);}
#line 2098 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new NumberExpr((yyvsp[0].int_t));}
#line 2104 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BoolExpr(true);}
#line 2110 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 258 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new BoolExpr(false);}
#line 2116 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new VarExpr(string((yyvsp[0].charPointer_t))); delete (yyvsp[0].charPointer_t);}
#line 2122 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[-1].expr_t);}
#line 2128 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2132 "parser.cpp" /* yacc.c:1646  */
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
#line 262 "parser.y" /* yacc.c:1906  */

