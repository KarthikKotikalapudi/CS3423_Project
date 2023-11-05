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
    MATRIX = 260,                  /* MATRIX  */
    DF = 261,                      /* DF  */
    IF = 262,                      /* IF  */
    ELIF = 263,                    /* ELIF  */
    ELSE = 264,                    /* ELSE  */
    RETURN = 265,                  /* RETURN  */
    BREAK = 266,                   /* BREAK  */
    CONT = 267,                    /* CONT  */
    OBRAK = 268,                   /* OBRAK  */
    CBRAK = 269,                   /* CBRAK  */
    OSQA = 270,                    /* OSQA  */
    CSQA = 271,                    /* CSQA  */
    OBRACE = 272,                  /* OBRACE  */
    CBRACE = 273,                  /* CBRACE  */
    DOT = 274,                     /* DOT  */
    NEG = 275,                     /* NEG  */
    COL = 276,                     /* COL  */
    SEMICOL = 277,                 /* SEMICOL  */
    POST = 278,                    /* POST  */
    COMMA = 279,                   /* COMMA  */
    STRING = 280,                  /* STRING  */
    CHAR = 281,                    /* CHAR  */
    ASSGN = 282,                   /* ASSGN  */
    ARTHASSGN = 283,               /* ARTHASSGN  */
    MATRIX_TYPE = 284,             /* MATRIX_TYPE  */
    FOR = 285,                     /* FOR  */
    WHILE = 286,                   /* WHILE  */
    PRINT = 287,                   /* PRINT  */
    MAIN = 288,                    /* MAIN  */
    CLASS = 289,                   /* CLASS  */
    PRIVATE = 290,                 /* PRIVATE  */
    PROTECTED = 291,               /* PROTECTED  */
    PUBLIC = 292,                  /* PUBLIC  */
    INHERITS = 293,                /* INHERITS  */
    BOOL = 294,                    /* BOOL  */
    NUL = 295,                     /* NUL  */
    SORT = 296,                    /* SORT  */
    SELECT = 297,                  /* SELECT  */
    UPDATE = 298,                  /* UPDATE  */
    DELETE = 299,                  /* DELETE  */
    LOG = 300,                     /* LOG  */
    ARTH = 301,                    /* ARTH  */
    BIT_OP = 302,                  /* BIT_OP  */
    SHIFT = 303,                   /* SHIFT  */
    COMP = 304,                    /* COMP  */
    MINUS = 305,                   /* MINUS  */
    ID = 306,                      /* ID  */
    DATATYPE = 307                 /* DATATYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parse.y"

     struct D{
        string name;
        string type;
        vector<int>dim;
        int scope;
    } datatype;

#line 125 "parse.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
