/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    FLOAT = 259,                   /* FLOAT  */
    DATATYPE = 260,                /* DATATYPE  */
    MATRIX = 261,                  /* MATRIX  */
    DF = 262,                      /* DF  */
    IF = 263,                      /* IF  */
    ELIF = 264,                    /* ELIF  */
    ELSE = 265,                    /* ELSE  */
    RETURN = 266,                  /* RETURN  */
    BREAK = 267,                   /* BREAK  */
    CONT = 268,                    /* CONT  */
    ID = 269,                      /* ID  */
    OBRAK = 270,                   /* OBRAK  */
    CBRAK = 271,                   /* CBRAK  */
    OSQA = 272,                    /* OSQA  */
    CSQA = 273,                    /* CSQA  */
    OBRACE = 274,                  /* OBRACE  */
    CBRACE = 275,                  /* CBRACE  */
    DOT = 276,                     /* DOT  */
    NEG = 277,                     /* NEG  */
    COL = 278,                     /* COL  */
    SEMICOL = 279,                 /* SEMICOL  */
    POST = 280,                    /* POST  */
    COMMA = 281,                   /* COMMA  */
    STRING = 282,                  /* STRING  */
    CHAR = 283,                    /* CHAR  */
    SHIFT = 284,                   /* SHIFT  */
    COMP = 285,                    /* COMP  */
    LOG = 286,                     /* LOG  */
    ASSGN = 287,                   /* ASSGN  */
    ARTHASSGN = 288,               /* ARTHASSGN  */
    MATRIX_TYPE = 289,             /* MATRIX_TYPE  */
    BIT_OP = 290,                  /* BIT_OP  */
    FOR = 291,                     /* FOR  */
    WHILE = 292,                   /* WHILE  */
    PRINT = 293,                   /* PRINT  */
    MAIN = 294,                    /* MAIN  */
    NULL = 295,                    /* NULL  */
    BOOL = 296,                    /* BOOL  */
    SORT = 297,                    /* SORT  */
    ARTH = 298                     /* ARTH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define FLOAT 259
#define DATATYPE 260
#define MATRIX 261
#define DF 262
#define IF 263
#define ELIF 264
#define ELSE 265
#define RETURN 266
#define BREAK 267
#define CONT 268
#define ID 269
#define OBRAK 270
#define CBRAK 271
#define OSQA 272
#define CSQA 273
#define OBRACE 274
#define CBRACE 275
#define DOT 276
#define NEG 277
#define COL 278
#define SEMICOL 279
#define POST 280
#define COMMA 281
#define STRING 282
#define CHAR 283
#define SHIFT 284
#define COMP 285
#define LOG 286
#define ASSGN 287
#define ARTHASSGN 288
#define MATRIX_TYPE 289
#define BIT_OP 290
#define FOR 291
#define WHILE 292
#define PRINT 293
#define MAIN 294
#define NULL 295
#define BOOL 296
#define SORT 297
#define ARTH 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
