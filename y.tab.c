/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"

    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    void yyerror(const char* s);
    extern int yylex(void);
    extern int yylineno;
    extern FILE* yyin;
    extern FILE* out;

#line 82 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_DATATYPE = 5,                   /* DATATYPE  */
  YYSYMBOL_MATRIX = 6,                     /* MATRIX  */
  YYSYMBOL_DF = 7,                         /* DF  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELIF = 9,                       /* ELIF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CONT = 13,                      /* CONT  */
  YYSYMBOL_ID = 14,                        /* ID  */
  YYSYMBOL_OBRAK = 15,                     /* OBRAK  */
  YYSYMBOL_CBRAK = 16,                     /* CBRAK  */
  YYSYMBOL_OSQA = 17,                      /* OSQA  */
  YYSYMBOL_CSQA = 18,                      /* CSQA  */
  YYSYMBOL_OBRACE = 19,                    /* OBRACE  */
  YYSYMBOL_CBRACE = 20,                    /* CBRACE  */
  YYSYMBOL_DOT = 21,                       /* DOT  */
  YYSYMBOL_NEG = 22,                       /* NEG  */
  YYSYMBOL_COL = 23,                       /* COL  */
  YYSYMBOL_SEMICOL = 24,                   /* SEMICOL  */
  YYSYMBOL_POST = 25,                      /* POST  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_STRING = 27,                    /* STRING  */
  YYSYMBOL_CHAR = 28,                      /* CHAR  */
  YYSYMBOL_SHIFT = 29,                     /* SHIFT  */
  YYSYMBOL_COMP = 30,                      /* COMP  */
  YYSYMBOL_LOG = 31,                       /* LOG  */
  YYSYMBOL_ASSGN = 32,                     /* ASSGN  */
  YYSYMBOL_ARTHASSGN = 33,                 /* ARTHASSGN  */
  YYSYMBOL_MATRIX_TYPE = 34,               /* MATRIX_TYPE  */
  YYSYMBOL_BIT_OP = 35,                    /* BIT_OP  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_PRINT = 38,                     /* PRINT  */
  YYSYMBOL_MAIN = 39,                      /* MAIN  */
  YYSYMBOL_NULL = 40,                      /* NULL  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_SORT = 42,                      /* SORT  */
  YYSYMBOL_ARTH = 43,                      /* ARTH  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_S = 45,                         /* S  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_Main = 47,                      /* Main  */
  YYSYMBOL_GlobalDecl = 48,                /* GlobalDecl  */
  YYSYMBOL_stmt = 49,                      /* stmt  */
  YYSYMBOL_stmtL = 50,                     /* stmtL  */
  YYSYMBOL_stmtD = 51,                     /* stmtD  */
  YYSYMBOL_declstmt = 52,                  /* declstmt  */
  YYSYMBOL_IDL = 53,                       /* IDL  */
  YYSYMBOL_IDLAssgn = 54,                  /* IDLAssgn  */
  YYSYMBOL_ARRL = 55,                      /* ARRL  */
  YYSYMBOL_constL = 56,                    /* constL  */
  YYSYMBOL_MatrixDecl = 57,                /* MatrixDecl  */
  YYSYMBOL_numL = 58,                      /* numL  */
  YYSYMBOL_MatrixL = 59,                   /* MatrixL  */
  YYSYMBOL_FuncDecl = 60,                  /* FuncDecl  */
  YYSYMBOL_FuncHead = 61,                  /* FuncHead  */
  YYSYMBOL_params = 62,                    /* params  */
  YYSYMBOL_parameter = 63,                 /* parameter  */
  YYSYMBOL_FuncBody = 64,                  /* FuncBody  */
  YYSYMBOL_varL = 65,                      /* varL  */
  YYSYMBOL_call_expression = 66,           /* call_expression  */
  YYSYMBOL_callstmt = 67,                  /* callstmt  */
  YYSYMBOL_rhs = 68,                       /* rhs  */
  YYSYMBOL_pred = 69,                      /* pred  */
  YYSYMBOL_predD = 70,                     /* predD  */
  YYSYMBOL_arg = 71,                       /* arg  */
  YYSYMBOL_access = 72,                    /* access  */
  YYSYMBOL_uni = 73,                       /* uni  */
  YYSYMBOL_bin = 74,                       /* bin  */
  YYSYMBOL_expr = 75,                      /* expr  */
  YYSYMBOL_exprstmt = 76,                  /* exprstmt  */
  YYSYMBOL_condstmt = 77,                  /* condstmt  */
  YYSYMBOL_elif_list = 78,                 /* elif_list  */
  YYSYMBOL_loop = 79,                      /* loop  */
  YYSYMBOL_break = 80,                     /* break  */
  YYSYMBOL_continue = 81,                  /* continue  */
  YYSYMBOL_returnstmt = 82,                /* returnstmt  */
  YYSYMBOL_printstmt = 83                  /* printstmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    15,    15,    18,    19,    20,    23,    25,    29,    30,
      33,    34,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    51,    52,    53,    54,    55,    56,    59,    60,    63,
      64,    67,    68,    71,    72,    73,    74,    75,    76,    77,
      78,    81,    82,    83,    84,    87,    88,    91,    92,    96,
      99,   102,   103,   106,   107,   108,   111,   114,   115,   118,
     119,   122,   126,   130,   131,   132,   133,   137,   138,   139,
     140,   143,   144,   145,   146,   147,   148,   149,   152,   153,
     156,   157,   160,   163,   164,   165,   166,   169,   173,   174,
     177,   178,   182,   183,   184,   185,   186,   190,   194,   198,
     202
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "FLOAT",
  "DATATYPE", "MATRIX", "DF", "IF", "ELIF", "ELSE", "RETURN", "BREAK",
  "CONT", "ID", "OBRAK", "CBRAK", "OSQA", "CSQA", "OBRACE", "CBRACE",
  "DOT", "NEG", "COL", "SEMICOL", "POST", "COMMA", "STRING", "CHAR",
  "SHIFT", "COMP", "LOG", "ASSGN", "ARTHASSGN", "MATRIX_TYPE", "BIT_OP",
  "FOR", "WHILE", "PRINT", "MAIN", "NULL", "BOOL", "SORT", "ARTH",
  "$accept", "S", "Decl", "Main", "GlobalDecl", "stmt", "stmtL", "stmtD",
  "declstmt", "IDL", "IDLAssgn", "ARRL", "constL", "MatrixDecl", "numL",
  "MatrixL", "FuncDecl", "FuncHead", "params", "parameter", "FuncBody",
  "varL", "call_expression", "callstmt", "rhs", "pred", "predD", "arg",
  "access", "uni", "bin", "expr", "exprstmt", "condstmt", "elif_list",
  "loop", "break", "continue", "returnstmt", "printstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,    14,    27,    19,    76,    48,  -131,  -131,    48,    51,
      52,    96,   101,   106,   113,  -131,   116,    48,  -131,  -131,
     155,   118,   139,    57,  -131,  -131,  -131,    78,    21,  -131,
     144,   131,   156,   145,  -131,  -131,   129,   141,  -131,    -5,
    -131,  -131,   148,  -131,    57,    57,   149,   146,  -131,    99,
     173,  -131,    82,   164,   165,    57,   157,   159,    72,   167,
     169,   174,   168,   160,    21,  -131,   166,  -131,   171,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,   176,   177,   178,   155,
     123,   137,  -131,  -131,   179,   170,   137,    -7,  -131,   185,
      57,   137,   137,   137,   175,   184,   180,   186,    91,    57,
     114,  -131,  -131,   137,    57,    57,    71,    57,   181,  -131,
      21,  -131,  -131,  -131,   200,  -131,    21,  -131,  -131,    64,
     163,    -1,    17,   193,  -131,  -131,   182,  -131,  -131,   163,
     163,   163,   173,   187,  -131,    12,   190,    15,  -131,     0,
    -131,  -131,    57,    57,    39,   196,   195,   198,  -131,   197,
    -131,   137,     5,   192,   194,   189,   199,   201,   202,   204,
    -131,  -131,  -131,   203,   205,   207,   130,   124,   125,   209,
     206,    21,  -131,  -131,   163,   137,  -131,  -131,    12,    12,
    -131,    12,    12,   208,   137,   186,  -131,    21,    57,    57,
      97,   136,    21,  -131,  -131,     7,  -131,  -131,  -131,  -131,
    -131,  -131,   211,  -131,  -131,    86,   214,   218,   216,   220,
     217,   221,  -131,    21,   222,    21,   223,  -131,   158,   219,
      21,   224,    21,   225,   226,  -131,   227,  -131,   228,    57,
      21,  -131,  -131,    67,   229,   231,  -131,    21,   232,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     3,     7,    26,     3,     0,
      28,     0,     0,     0,     0,     1,     0,     3,     4,     5,
       0,     0,     0,     0,    21,    23,    22,     0,    11,     2,
       0,     0,     0,    52,    75,    76,    71,     0,    74,     0,
      73,    72,    28,    27,     0,     0,    30,    62,    66,    67,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    11,    12,     0,    14,     0,    13,
      15,    16,    19,    20,    17,    18,    53,     0,     0,     0,
       0,     0,    80,    77,     0,    32,     0,     0,    65,     0,
       0,     0,     0,     0,    46,     0,     0,     0,    28,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     6,
      11,    10,    61,    87,     0,    54,    11,    51,    60,     0,
      57,     0,     0,     0,    82,    64,     0,    29,    63,    69,
      68,    70,     0,     0,    42,     0,     0,     0,    99,     0,
      83,    84,     0,     0,     0,     0,     0,     0,    56,     0,
      59,     0,    79,    37,    38,     0,    39,    40,     0,     0,
      31,    45,    43,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    55,    49,    58,     0,    81,    78,     0,     0,
      25,     0,     0,     0,     0,    48,    44,    11,     0,     0,
       0,     0,    11,   100,     8,     0,    33,    34,    35,    36,
      24,    47,     0,    85,    86,     0,     0,     0,     0,     0,
       0,    79,    90,    11,     0,    11,     0,    96,    88,     0,
      11,     0,    11,     0,     0,    95,     0,    93,     0,     0,
      11,    94,    92,     0,     0,     0,    89,    11,     0,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,    89,  -131,  -131,  -106,   191,  -131,     6,   234,
     135,   120,  -130,  -131,    87,    61,  -131,  -131,   172,  -131,
    -131,  -131,   -28,  -131,   -97,   -43,  -131,   -18,   230,  -131,
    -131,   -21,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    17,     5,    62,    63,    64,    65,    11,
      12,    13,   158,     7,    95,   136,     8,     9,    32,    33,
     149,   119,    38,    67,    46,    47,    48,    49,   177,    40,
      41,    68,    69,    70,   218,    71,    72,    73,    74,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    87,    88,    39,   146,   163,     6,   140,   141,   125,
     148,     6,   100,    85,     6,   153,   154,   152,   166,    15,
     153,   154,   175,     6,    90,   211,    53,     2,    10,    54,
     176,   165,    55,    56,    57,    58,    66,   155,    86,   156,
     157,    14,    86,    86,   156,   157,    90,   128,   196,   197,
      86,   198,   199,     1,     2,   169,   137,    59,    60,    61,
      34,    35,   120,   121,   144,   194,    20,   -50,   124,    21,
      90,    36,    44,   129,   130,   131,    53,     2,    22,    45,
     150,   202,    66,   235,    23,   139,   210,    80,    66,   103,
     151,   203,   204,    50,    18,   142,    96,    19,    90,   167,
     168,    97,    51,   103,   104,   105,    29,   219,    21,   221,
      52,   205,   143,   206,   226,    16,   228,    22,   104,   105,
      24,    34,    35,    23,   234,    25,    34,    35,    91,    92,
      26,   238,    36,   174,    93,    28,    37,    36,   138,   118,
      34,    35,    86,    66,    80,    90,    81,    27,   190,   191,
     205,    36,   208,    42,    82,    90,    90,   195,    76,    66,
      30,    31,   188,   189,    66,    77,    39,   223,   224,   207,
     209,    79,    78,    84,    22,    89,    94,    90,    98,   110,
      99,   101,   106,   102,   107,    66,   233,    66,   109,   108,
     112,   115,    66,   114,    66,   113,   123,   116,   122,   126,
     133,   132,    66,   147,   134,   135,    86,   159,   145,    66,
     164,   162,   170,   180,    23,   171,   172,   173,   178,   161,
     179,   184,   183,   185,   127,   181,   187,   182,   192,   186,
     193,   212,   200,   213,   214,   215,   216,   217,   175,   225,
     229,   220,   222,   160,   227,   230,   201,   231,   232,   236,
     237,   117,   239,     0,     0,   111,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83
};

static const yytype_int16 yycheck[] =
{
      28,    44,    45,    21,   110,   135,     0,   104,   105,    16,
     116,     5,    55,    18,     8,     3,     4,    18,    18,     0,
       3,     4,    17,    17,    31,    18,     5,     6,    14,     8,
      25,    16,    11,    12,    13,    14,    64,    20,    43,    27,
      28,    14,    43,    43,    27,    28,    31,    90,   178,   179,
      43,   181,   182,     5,     6,    16,    99,    36,    37,    38,
       3,     4,    80,    81,   107,   171,    15,    15,    86,    17,
      31,    14,    15,    91,    92,    93,     5,     6,    26,    22,
      16,   187,   110,    16,    32,   103,   192,    15,   116,    17,
      26,   188,   189,    15,     5,    24,    14,     8,    31,   142,
     143,    19,    24,    17,    32,    33,    17,   213,    17,   215,
      32,    14,   106,    16,   220,    39,   222,    26,    32,    33,
      24,     3,     4,    32,   230,    24,     3,     4,    29,    30,
      24,   237,    14,   151,    35,    19,    18,    14,    24,    16,
       3,     4,    43,   171,    15,    31,    17,    34,    24,    24,
      14,    14,    16,    14,    25,    31,    31,   175,    14,   187,
       5,     6,    32,    33,   192,    34,   184,     9,    10,   190,
     191,    26,    16,    32,    26,    26,     3,    31,    14,    19,
      15,    24,    15,    24,    15,   213,   229,   215,    20,    15,
      24,    14,   220,    17,   222,    24,    26,    19,    19,    14,
      16,    26,   230,     3,    24,    19,    43,    14,    27,   237,
      20,    24,    16,    24,    32,    20,    18,    20,    26,   132,
      26,    17,    20,    20,    89,    26,    19,    26,    19,    24,
      24,    20,    24,    19,    16,    19,    16,    20,    17,    20,
      15,    19,    19,   123,    20,    19,   185,    20,    20,    20,
      19,    79,    20,    -1,    -1,    64,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    45,    46,    48,    52,    57,    60,    61,
      14,    53,    54,    55,    14,     0,    39,    47,    46,    46,
      15,    17,    26,    32,    24,    24,    24,    34,    19,    46,
       5,     6,    62,    63,     3,     4,    14,    18,    66,    71,
      73,    74,    14,    53,    15,    22,    68,    69,    70,    71,
      15,    24,    32,     5,     8,    11,    12,    13,    14,    36,
      37,    38,    49,    50,    51,    52,    66,    67,    75,    76,
      77,    79,    80,    81,    82,    83,    14,    34,    16,    26,
      15,    17,    25,    72,    32,    18,    43,    69,    69,    26,
      31,    29,    30,    35,     3,    58,    14,    19,    14,    15,
      69,    24,    24,    17,    32,    33,    15,    15,    15,    20,
      19,    50,    24,    24,    17,    14,    19,    62,    16,    65,
      71,    71,    19,    26,    71,    16,    14,    54,    69,    71,
      71,    71,    26,    16,    24,    19,    59,    69,    24,    71,
      68,    68,    24,    52,    69,    27,    49,     3,    49,    64,
      16,    26,    18,     3,     4,    20,    27,    28,    56,    14,
      55,    58,    24,    56,    20,    16,    18,    69,    69,    16,
      16,    20,    18,    20,    71,    17,    25,    72,    26,    26,
      24,    26,    26,    20,    17,    20,    24,    19,    32,    33,
      24,    24,    19,    24,    49,    71,    56,    56,    56,    56,
      24,    59,    49,    68,    68,    14,    16,    75,    16,    75,
      49,    18,    20,    19,    16,    19,    16,    20,    78,    49,
      19,    49,    19,     9,    10,    20,    49,    20,    49,    15,
      19,    20,    20,    69,    49,    16,    20,    19,    49,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    47,    48,    49,    49,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    62,    62,    63,    63,    63,    64,    65,    65,    66,
      66,    67,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    75,    75,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    79,    79,    79,    80,    81,    82,
      83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     2,     4,     1,     5,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     9,     8,     1,     3,     1,     5,
       3,     6,     4,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     6,     7,     8,     3,     1,     4,     3,     7,
       2,     3,     1,     2,     3,     5,     1,     1,     3,     4,
       3,     2,     1,     3,     3,     2,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     2,     4,     3,
       2,     5,     3,     3,     3,     6,     6,     2,     8,    12,
       0,     8,    10,     9,    10,     9,     7,     2,     2,     3,
       5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* S: Decl Main Decl  */
#line 15 "parse.y"
                   {}
#line 1435 "y.tab.c"
    break;

  case 4: /* Decl: GlobalDecl Decl  */
#line 19 "parse.y"
                   {}
#line 1441 "y.tab.c"
    break;

  case 7: /* GlobalDecl: declstmt  */
#line 25 "parse.y"
                      {}
#line 1447 "y.tab.c"
    break;

  case 8: /* stmt: stmtL OBRACE stmt CBRACE stmt  */
#line 29 "parse.y"
                                     {}
#line 1453 "y.tab.c"
    break;

  case 9: /* stmt: stmtL  */
#line 30 "parse.y"
            {}
#line 1459 "y.tab.c"
    break;

  case 10: /* stmtL: stmtD stmtL  */
#line 33 "parse.y"
                    {}
#line 1465 "y.tab.c"
    break;

  case 11: /* stmtL: %empty  */
#line 34 "parse.y"
      {}
#line 1471 "y.tab.c"
    break;

  case 21: /* declstmt: DATATYPE IDL SEMICOL  */
#line 51 "parse.y"
                                {}
#line 1477 "y.tab.c"
    break;

  case 22: /* declstmt: DATATYPE ARRL SEMICOL  */
#line 52 "parse.y"
                            {}
#line 1483 "y.tab.c"
    break;

  case 23: /* declstmt: DATATYPE IDLAssgn SEMICOL  */
#line 53 "parse.y"
                                {}
#line 1489 "y.tab.c"
    break;

  case 24: /* declstmt: DATATYPE ID OSQA CSQA ASSGN OBRACE constL CBRACE SEMICOL  */
#line 54 "parse.y"
                                                                {}
#line 1495 "y.tab.c"
    break;

  case 25: /* declstmt: DATATYPE ID OSQA CSQA ASSGN OBRACE CBRACE SEMICOL  */
#line 55 "parse.y"
                                                         {}
#line 1501 "y.tab.c"
    break;

  case 27: /* IDL: ID COMMA IDL  */
#line 59 "parse.y"
                   {}
#line 1507 "y.tab.c"
    break;

  case 28: /* IDL: ID  */
#line 60 "parse.y"
         {}
#line 1513 "y.tab.c"
    break;

  case 29: /* IDLAssgn: ID ASSGN rhs COMMA IDLAssgn  */
#line 63 "parse.y"
                                       {}
#line 1519 "y.tab.c"
    break;

  case 30: /* IDLAssgn: ID ASSGN rhs  */
#line 64 "parse.y"
                        {}
#line 1525 "y.tab.c"
    break;

  case 31: /* ARRL: ID OSQA arg CSQA COMMA ARRL  */
#line 67 "parse.y"
                                   {}
#line 1531 "y.tab.c"
    break;

  case 32: /* ARRL: ID OSQA arg CSQA  */
#line 68 "parse.y"
                       {}
#line 1537 "y.tab.c"
    break;

  case 33: /* constL: NUM COMMA constL  */
#line 71 "parse.y"
                          {}
#line 1543 "y.tab.c"
    break;

  case 34: /* constL: FLOAT COMMA constL  */
#line 72 "parse.y"
                         {}
#line 1549 "y.tab.c"
    break;

  case 35: /* constL: STRING COMMA constL  */
#line 73 "parse.y"
                          {}
#line 1555 "y.tab.c"
    break;

  case 36: /* constL: CHAR COMMA constL  */
#line 74 "parse.y"
                        {}
#line 1561 "y.tab.c"
    break;

  case 41: /* MatrixDecl: MATRIX ID MATRIX_TYPE SEMICOL  */
#line 81 "parse.y"
                                           {}
#line 1567 "y.tab.c"
    break;

  case 42: /* MatrixDecl: MATRIX ID MATRIX_TYPE ASSGN ID SEMICOL  */
#line 82 "parse.y"
                                             {}
#line 1573 "y.tab.c"
    break;

  case 43: /* MatrixDecl: MATRIX ID MATRIX_TYPE OBRAK numL CBRAK SEMICOL  */
#line 83 "parse.y"
                                                     {}
#line 1579 "y.tab.c"
    break;

  case 44: /* MatrixDecl: MATRIX ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE SEMICOL  */
#line 84 "parse.y"
                                                                {}
#line 1585 "y.tab.c"
    break;

  case 62: /* rhs: pred  */
#line 126 "parse.y"
           {}
#line 1591 "y.tab.c"
    break;

  case 63: /* pred: pred LOG pred  */
#line 130 "parse.y"
                     { }
#line 1597 "y.tab.c"
    break;

  case 64: /* pred: OBRAK pred CBRAK  */
#line 131 "parse.y"
                       { }
#line 1603 "y.tab.c"
    break;

  case 66: /* pred: predD  */
#line 133 "parse.y"
            { }
#line 1609 "y.tab.c"
    break;

  case 67: /* predD: arg  */
#line 137 "parse.y"
            { }
#line 1615 "y.tab.c"
    break;

  case 68: /* predD: arg COMP arg  */
#line 138 "parse.y"
                     { }
#line 1621 "y.tab.c"
    break;

  case 71: /* arg: ID  */
#line 143 "parse.y"
         {}
#line 1627 "y.tab.c"
    break;

  case 72: /* arg: bin  */
#line 144 "parse.y"
          {}
#line 1633 "y.tab.c"
    break;

  case 73: /* arg: uni  */
#line 145 "parse.y"
          {}
#line 1639 "y.tab.c"
    break;

  case 74: /* arg: call_expression  */
#line 146 "parse.y"
                      {}
#line 1645 "y.tab.c"
    break;

  case 78: /* access: OSQA arg CSQA access  */
#line 152 "parse.y"
                              {}
#line 1651 "y.tab.c"
    break;

  case 79: /* access: OSQA arg CSQA  */
#line 153 "parse.y"
                       {}
#line 1657 "y.tab.c"
    break;

  case 83: /* expr: ID ASSGN rhs  */
#line 163 "parse.y"
                    {}
#line 1663 "y.tab.c"
    break;

  case 84: /* expr: ID ARTHASSGN rhs  */
#line 164 "parse.y"
                       {}
#line 1669 "y.tab.c"
    break;

  case 85: /* expr: ID OSQA arg CSQA ASSGN rhs  */
#line 165 "parse.y"
                                 {}
#line 1675 "y.tab.c"
    break;

  case 86: /* expr: ID OSQA arg CSQA ARTHASSGN rhs  */
#line 166 "parse.y"
                                     {}
#line 1681 "y.tab.c"
    break;


#line 1685 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 271 "parse.y"

int main(int argc,char** argv)
{
    
    if(argc!= 2)
    {
        printf("provide command line arguments correctly\n");
        return 0;
    }
    FILE* inp = fopen(argv[1],"r");
    if(!inp)
    {
        printf("There was an error opening this input file\n");
        return 0;
    }
    yyin = inp;
    for(int i=0;i<strlen(argv[1]);i++)
    {
         if(argv[1][i]=='.')
         {
            argv[1][i] = '\0'; break;
         }
    }
    char tokf[50];
    snprintf(tokf,sizeof(tokf), "out_%s.txt", argv[1]);
    out = fopen(tokf,"w");   //opeing the output seq tokens file
    // if(!sq)
    // {
    //     printf("There was an error opening the output token file\n");
    //     return 0;
    // }
   yyparse();
   fclose(out); 
   return 1;
}

void yyerror(const char* s)
{
    printf("Error: %s at line %d\n",s,yylineno);
    //fprintf(fp," : invalid statement");
}
