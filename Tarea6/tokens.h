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
#line 1 "parser.y" /* yacc.c:1909  */

    #include "ast.h"
    #include <string>

#line 49 "tokens.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OP_ADD = 258,
    OP_SUB = 259,
    OP_MULT = 260,
    OP_DIV = 261,
    OP_EXP = 262,
    OP_MOD = 263,
    OP_LT = 264,
    OP_LTE = 265,
    OP_GT = 266,
    OP_GTE = 267,
    OP_NEQ = 268,
    OP_EQ = 269,
    OP_ASSGN = 270,
    PAR_LEFT = 271,
    PAR_RIGHT = 272,
    TK_SEMICOLON = 273,
    TK_PRINT = 274,
    TK_WHILE = 275,
    TK_IF = 276,
    TK_ELSE = 277,
    TK_FOR = 278,
    TK_RANGE = 279,
    TK_SPACE = 280,
    TK_PASS = 281,
    TK_EOL = 282,
    TK_ERROR = 283,
    TK_INPUT = 284,
    TK_COMMA = 285,
    OPEN_INDENT = 286,
    CLOSE_INDENT = 287,
    LIT_NUM = 288,
    LIT_STRING = 289,
    TK_ID = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "parser.y" /* yacc.c:1909  */

    Statement * Statement_t;
    Expr * expr_t;
    int int_t;
    string * string_t;
    list<Expr*> *exprList_t;

#line 105 "tokens.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
