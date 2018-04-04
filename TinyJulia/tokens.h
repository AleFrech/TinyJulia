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

#line 48 "tokens.h" /* yacc.c:1909  */

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
#line 24 "parser.y" /* yacc.c:1909  */

    char *charPointer_t;
    int  int_t;
    bool bool_t;
    Statement *statement_t;
	BlockStatement *blkstatement_t;
    Expr *expr_t;
    ExprList *exprlist_t;
    primitiveType primitiveType_t;

#line 117 "tokens.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
