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

#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
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
    ASSGN = 284,                   /* ASSGN  */
    ARTHASSGN = 285,               /* ARTHASSGN  */
    MATRIX_TYPE = 286,             /* MATRIX_TYPE  */
    FOR = 287,                     /* FOR  */
    WHILE = 288,                   /* WHILE  */
    PRINT = 289,                   /* PRINT  */
    MAIN = 290,                    /* MAIN  */
    CLASS = 291,                   /* CLASS  */
    PRIVATE = 292,                 /* PRIVATE  */
    PROTECTED = 293,               /* PROTECTED  */
    PUBLIC = 294,                  /* PUBLIC  */
    INHERITS = 295,                /* INHERITS  */
    BOOL = 296,                    /* BOOL  */
    NUL = 297,                     /* NUL  */
    SORT = 298,                    /* SORT  */
    SELECT = 299,                  /* SELECT  */
    UPDATE = 300,                  /* UPDATE  */
    DELETE = 301,                  /* DELETE  */
    LOG = 302,                     /* LOG  */
    ARTH = 303,                    /* ARTH  */
    BIT_OP = 304,                  /* BIT_OP  */
    SHIFT = 305,                   /* SHIFT  */
    COMP = 306,                    /* COMP  */
    MINUS = 307                    /* MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
