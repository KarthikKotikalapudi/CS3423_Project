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

    #include"global.hpp"
    #include<bits/stdc++.h>
    #include "helper_functions.hpp"
    void yyerror(const char* s);
    extern int yylex(void);
    extern int yylineno;
    extern FILE* yyin;
    extern FILE* out;
//global variables
int scope = 0;
vector<unordered_map<string,x*>> sym_table_list;

#line 85 "parse.tab.cpp"

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

#include "parse.tab.hpp"
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
  YYSYMBOL_ASSGN = 29,                     /* ASSGN  */
  YYSYMBOL_ARTHASSGN = 30,                 /* ARTHASSGN  */
  YYSYMBOL_MATRIX_TYPE = 31,               /* MATRIX_TYPE  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_PRINT = 34,                     /* PRINT  */
  YYSYMBOL_MAIN = 35,                      /* MAIN  */
  YYSYMBOL_CLASS = 36,                     /* CLASS  */
  YYSYMBOL_PRIVATE = 37,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 38,                 /* PROTECTED  */
  YYSYMBOL_PUBLIC = 39,                    /* PUBLIC  */
  YYSYMBOL_INHERITS = 40,                  /* INHERITS  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_NUL = 42,                       /* NUL  */
  YYSYMBOL_SORT = 43,                      /* SORT  */
  YYSYMBOL_SELECT = 44,                    /* SELECT  */
  YYSYMBOL_UPDATE = 45,                    /* UPDATE  */
  YYSYMBOL_DELETE = 46,                    /* DELETE  */
  YYSYMBOL_LOG = 47,                       /* LOG  */
  YYSYMBOL_ARTH = 48,                      /* ARTH  */
  YYSYMBOL_BIT_OP = 49,                    /* BIT_OP  */
  YYSYMBOL_SHIFT = 50,                     /* SHIFT  */
  YYSYMBOL_COMP = 51,                      /* COMP  */
  YYSYMBOL_MINUS = 52,                     /* MINUS  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_S = 54,                         /* S  */
  YYSYMBOL_Decl = 55,                      /* Decl  */
  YYSYMBOL_Main = 56,                      /* Main  */
  YYSYMBOL_GlobalDecl = 57,                /* GlobalDecl  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_stmtL = 59,                     /* stmtL  */
  YYSYMBOL_stmtD = 60,                     /* stmtD  */
  YYSYMBOL_declstmt = 61,                  /* declstmt  */
  YYSYMBOL_Multideclstmt = 62,             /* Multideclstmt  */
  YYSYMBOL_numbers = 63,                   /* numbers  */
  YYSYMBOL_constL = 64,                    /* constL  */
  YYSYMBOL_MultiDimL = 65,                 /* MultiDimL  */
  YYSYMBOL_MatrixDecl = 66,                /* MatrixDecl  */
  YYSYMBOL_MultiMatrixDecl = 67,           /* MultiMatrixDecl  */
  YYSYMBOL_numL = 68,                      /* numL  */
  YYSYMBOL_MatrixL = 69,                   /* MatrixL  */
  YYSYMBOL_FuncDecl = 70,                  /* FuncDecl  */
  YYSYMBOL_FuncHead = 71,                  /* FuncHead  */
  YYSYMBOL_params = 72,                    /* params  */
  YYSYMBOL_parameter = 73,                 /* parameter  */
  YYSYMBOL_FuncBody = 74,                  /* FuncBody  */
  YYSYMBOL_varL = 75,                      /* varL  */
  YYSYMBOL_function_call = 76,             /* function_call  */
  YYSYMBOL_call_expression = 77,           /* call_expression  */
  YYSYMBOL_callstmt = 78,                  /* callstmt  */
  YYSYMBOL_class_arg = 79,                 /* class_arg  */
  YYSYMBOL_rhs = 80,                       /* rhs  */
  YYSYMBOL_pred = 81,                      /* pred  */
  YYSYMBOL_arg = 82,                       /* arg  */
  YYSYMBOL_access = 83,                    /* access  */
  YYSYMBOL_access_assgn = 84,              /* access_assgn  */
  YYSYMBOL_access2 = 85,                   /* access2  */
  YYSYMBOL_access_retn = 86,               /* access_retn  */
  YYSYMBOL_uni = 87,                       /* uni  */
  YYSYMBOL_expr = 88,                      /* expr  */
  YYSYMBOL_exprstmt = 89,                  /* exprstmt  */
  YYSYMBOL_condstmt = 90,                  /* condstmt  */
  YYSYMBOL_elif_list = 91,                 /* elif_list  */
  YYSYMBOL_loop = 92,                      /* loop  */
  YYSYMBOL_break = 93,                     /* break  */
  YYSYMBOL_continue = 94,                  /* continue  */
  YYSYMBOL_returnstmt = 95,                /* returnstmt  */
  YYSYMBOL_printstmt = 96,                 /* printstmt  */
  YYSYMBOL_class_decl = 97,                /* class_decl  */
  YYSYMBOL_class_body = 98,                /* class_body  */
  YYSYMBOL_access_specifier = 99,          /* access_specifier  */
  YYSYMBOL_section_body = 100,             /* section_body  */
  YYSYMBOL_object_decl = 101,              /* object_decl  */
  YYSYMBOL_Multiobj = 102,                 /* Multiobj  */
  YYSYMBOL_Inheritance = 103,              /* Inheritance  */
  YYSYMBOL_PARENT_LIST = 104,              /* PARENT_LIST  */
  YYSYMBOL_SORT_FUN = 105,                 /* SORT_FUN  */
  YYSYMBOL_DF_DECL = 106,                  /* DF_DECL  */
  YYSYMBOL_DF_DELETEROW = 107,             /* DF_DELETEROW  */
  YYSYMBOL_DF_UPDATECOL = 108,             /* DF_UPDATECOL  */
  YYSYMBOL_DF_SELECT = 109                 /* DF_SELECT  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   572

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  398

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    19,    19,    22,    23,    24,    27,    29,    30,    34,
      35,    38,    39,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    56,    57,    58,    59,    60,    61,    62,    65,
      66,    67,    68,    69,    72,    73,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    88,    89,    90,    93,    94,
      95,    96,    99,   100,   101,   102,   103,   106,   109,   110,
     114,   117,   118,   119,   120,   121,   122,   125,   126,   129,
     130,   131,   132,   133,   136,   139,   140,   143,   144,   145,
     146,   147,   150,   153,   154,   155,   159,   160,   164,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   203,   204,
     208,   209,   212,   213,   216,   217,   220,   221,   227,   228,
     229,   230,   231,   232,   233,   236,   240,   241,   244,   245,
     249,   250,   251,   252,   253,   257,   261,   265,   269,   275,
     276,   281,   281,   284,   285,   286,   287,   292,   293,   296,
     297,   298,   301,   302,   303,   304,   308,   310,   311,   315,
     316,   321,   324,   327,   328,   331
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
  "ASSGN", "ARTHASSGN", "MATRIX_TYPE", "FOR", "WHILE", "PRINT", "MAIN",
  "CLASS", "PRIVATE", "PROTECTED", "PUBLIC", "INHERITS", "BOOL", "NUL",
  "SORT", "SELECT", "UPDATE", "DELETE", "LOG", "ARTH", "BIT_OP", "SHIFT",
  "COMP", "MINUS", "$accept", "S", "Decl", "Main", "GlobalDecl", "stmt",
  "stmtL", "stmtD", "declstmt", "Multideclstmt", "numbers", "constL",
  "MultiDimL", "MatrixDecl", "MultiMatrixDecl", "numL", "MatrixL",
  "FuncDecl", "FuncHead", "params", "parameter", "FuncBody", "varL",
  "function_call", "call_expression", "callstmt", "class_arg", "rhs",
  "pred", "arg", "access", "access_assgn", "access2", "access_retn", "uni",
  "expr", "exprstmt", "condstmt", "elif_list", "loop", "break", "continue",
  "returnstmt", "printstmt", "class_decl", "class_body",
  "access_specifier", "section_body", "object_decl", "Multiobj",
  "Inheritance", "PARENT_LIST", "SORT_FUN", "DF_DECL", "DF_DELETEROW",
  "DF_UPDATECOL", "DF_SELECT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-262)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-153)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     191,   131,     2,    17,   192,    35,    21,    40,   191,  -262,
      56,   191,    71,  -262,  -262,   106,  -262,   390,   119,   140,
     143,   173,   193,    -7,   206,    -6,  -262,   213,   191,  -262,
     230,   245,  -262,   232,  -262,    44,   263,   365,   260,   100,
    -262,   276,   272,  -262,    98,  -262,   304,   298,    90,   289,
    -262,  -262,   179,   228,  -262,   292,  -262,   303,   310,   314,
     316,   308,  -262,  -262,   440,   365,   313,   365,  -262,  -262,
    -262,   322,   325,   331,   338,  -262,  -262,  -262,  -262,   373,
    -262,  -262,  -262,  -262,  -262,    12,   323,   428,  -262,   330,
     341,  -262,    11,   189,   335,   347,    58,   336,  -262,     5,
     342,   358,   359,   350,   364,   356,   370,   381,   379,   365,
     384,   389,   439,   382,   399,   418,   419,   395,   444,   228,
    -262,   435,  -262,   443,  -262,   458,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,    66,   466,   453,   468,   469,   232,
     311,   365,   137,  -262,   461,    60,  -262,  -262,   473,   475,
     476,  -262,   313,   365,   365,   365,   365,   365,   365,   365,
    -262,   100,   462,   470,  -262,    42,   471,   472,   477,  -262,
     480,   479,   463,   478,   481,   482,   467,  -262,  -262,  -262,
     474,  -262,    88,   193,   365,   380,  -262,  -262,   241,   147,
     365,   365,   160,   286,   365,   483,   365,  -262,   228,  -262,
    -262,  -262,  -262,    11,   229,  -262,   493,  -262,   498,   228,
    -262,  -262,    24,  -262,   488,  -262,  -262,  -262,   485,   486,
     487,  -262,  -262,  -262,  -262,  -262,  -262,  -262,   323,  -262,
     341,  -262,   489,   490,   491,  -262,   492,   484,   142,   269,
     495,    11,  -262,   112,   494,   496,   180,  -262,  -262,  -262,
    -262,  -262,  -262,   179,   227,   128,  -262,    49,  -262,  -262,
     365,   365,   507,   365,   365,   203,   506,   497,   504,   509,
      56,   480,   508,   510,  -262,   511,  -262,   365,   513,   515,
     365,  -262,   471,   112,   112,   112,   112,  -262,  -262,   341,
    -262,  -262,  -262,   512,  -262,  -262,   488,  -262,  -262,  -262,
     514,   365,   365,  -262,  -262,   388,   394,   516,   517,   365,
     228,    56,  -262,   518,  -262,  -262,  -262,  -262,   519,   520,
     247,  -262,  -262,  -262,  -262,  -262,   521,   228,  -262,  -262,
     156,   186,   228,  -262,   116,  -262,  -262,    56,   365,   344,
    -262,   480,   522,   441,   524,   523,   525,   532,   529,   526,
     455,  -262,   326,   527,   400,  -262,  -262,   537,   228,   533,
     228,   535,  -262,  -262,   505,  -262,   365,   365,    92,   257,
     536,   228,   538,   228,   539,   541,   543,   545,   542,  -262,
     544,  -262,   546,   547,  -262,  -262,   365,   228,  -262,  -262,
    -262,   351,   548,   550,  -262,   228,   552,  -262
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     3,     7,
      56,     3,     0,     8,    27,     0,    28,    33,     0,     0,
       0,     0,    64,    62,     0,     0,     1,     0,     3,     4,
       0,     0,     5,     0,   140,     0,     0,     0,     0,    33,
     113,     0,   115,    65,    48,    63,     0,     0,     0,     0,
      66,   141,   146,    12,     2,     0,    26,     0,     0,     0,
       0,    68,    34,   102,    98,     0,   111,     0,   105,   104,
     103,     0,     0,     0,     0,   101,    82,   100,   107,     0,
      92,    99,    81,    79,    80,    33,    33,    88,    22,     0,
       0,   114,     0,     0,     0,     0,   152,   152,   149,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    12,
      13,     0,    15,     0,   122,     0,    14,    16,    17,    20,
      21,    18,    19,    85,    56,    69,     0,    72,     0,     0,
       0,     0,     0,   116,   106,     0,   110,    91,     0,     0,
       0,    35,   109,     0,     0,     0,     0,     0,     0,     0,
      29,    33,     0,     0,    23,     0,    33,     0,     0,    49,
       0,     0,   153,     0,     0,     0,     0,   143,   145,   144,
     157,   141,    33,     0,     0,     0,   135,   136,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     6,    12,    11,
      83,    84,   125,     0,     0,    52,     0,    70,     0,    12,
      67,    78,     0,    75,    86,    87,   117,    90,     0,     0,
       0,   108,    89,    96,    95,    94,    93,    97,    33,    30,
       0,    24,    41,    42,    43,    44,    40,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,   151,   150,   139,
     147,   148,   142,   146,   146,     0,   137,    86,   118,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,    74,     0,    77,     0,     0,     0,
       0,    31,    33,     0,     0,     0,     0,    47,    45,     0,
      46,    25,    57,     0,    51,   161,   155,   154,   158,   156,
       0,     0,     0,   120,   121,     0,     0,     0,     0,     0,
      12,    56,    53,     0,    71,    73,    60,    76,     0,     0,
       0,    32,    37,    38,    39,    36,    59,    12,   123,   124,
       0,     0,    12,   138,     0,     9,    54,    56,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,    58,   128,     0,    12,     0,
      12,     0,   134,   159,     0,   165,     0,     0,   126,     0,
       0,    12,     0,    12,     0,     0,     0,     0,     0,   133,
       0,   131,     0,     0,   164,   163,     0,    12,   132,   130,
     160,     0,     0,     0,   127,    12,     0,   129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,     7,  -262,  -262,  -172,   411,  -262,    28,   -33,
     -72,  -186,   -78,  -262,  -127,   306,  -261,   360,  -262,   398,
    -262,  -262,  -262,   -39,   -51,  -262,   -42,  -136,   -35,  -262,
     -61,  -262,   449,    23,   -52,   -74,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   386,   -91,  -262,  -262,   205,
    -262,   287,  -262,  -262,  -262,  -262,  -262
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,     7,    28,     8,   117,   118,   119,   120,    38,
      75,   237,   290,    10,    31,   168,   244,    11,    12,    60,
      61,   275,   212,    76,    77,   122,    78,    86,    87,    80,
      39,    40,    41,    19,    81,   125,   126,   127,   368,   128,
     129,   130,   131,   132,    13,    99,   103,   252,    14,    49,
      15,   104,   133,    16,    82,    83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,   124,   121,   144,   213,   146,    89,   205,   176,    97,
     313,   123,   166,    51,    62,    29,    20,  -152,    32,    47,
     167,    26,    48,   228,   161,   175,   268,    24,     9,    35,
     145,    22,   147,    21,    52,    54,     9,   274,    36,     9,
     276,   159,   100,   101,   102,    62,   232,    62,    63,    25,
     277,   192,   160,   163,   258,   259,     9,   293,    64,    65,
     267,   165,    66,    74,   140,    91,    67,   124,   121,   233,
     234,    68,    69,   140,   185,    27,   217,   123,   301,   302,
     355,   203,    30,   235,    47,    70,    33,   238,    71,    72,
      73,   221,    30,   236,    74,   204,    74,   322,   323,   324,
     325,   377,   378,   215,    96,    35,    79,   153,   154,   155,
     156,   157,   158,    92,    36,    62,   232,    37,   222,   223,
     224,   225,   226,   227,   303,   304,    36,    93,   229,  -112,
      34,   167,   349,   240,    71,    72,    73,    42,   335,   233,
     234,   317,   350,   312,   300,    17,   124,   121,    18,   255,
     215,   214,   282,   235,    43,   342,   123,   124,   121,   265,
     348,   257,   288,   176,    74,   328,   329,   123,   289,   292,
     343,   236,   344,   334,    44,   153,   154,   155,   156,   157,
     158,    71,    72,    73,   336,   216,   370,    45,   372,   260,
     261,    71,    72,    73,   296,   281,     1,     2,     3,   380,
     343,   382,   346,   169,   250,     4,    23,   297,   170,    18,
     351,   236,   236,   236,   236,   392,   100,   101,   102,   307,
      50,   264,    46,   396,    71,    72,    73,     5,   305,   306,
     375,   376,    53,   105,   106,   107,   108,    57,    58,   109,
     110,   111,   112,   270,    55,   320,    59,   299,   271,   321,
     153,   154,   155,   156,   157,   158,   345,   347,   124,   121,
     113,   114,   115,   340,   100,   101,   102,    47,   123,    56,
      48,   116,    71,    72,    73,   124,   121,    85,   124,   124,
     124,   121,   192,    85,    88,   123,   301,   302,   165,    18,
     123,   105,   106,   107,   153,   154,   155,   156,   157,   158,
     262,   173,   174,   352,   354,    90,   124,   121,   124,   121,
     263,    94,    95,    98,    62,    63,   123,   135,   123,   124,
     121,   124,   121,   134,   136,    64,    65,   211,   137,   123,
     141,   123,   138,    67,   139,   124,   121,   148,    68,    69,
     149,   151,   365,   124,   121,   123,   150,    62,    63,    36,
     171,   391,    70,   123,   164,    71,    72,    73,    64,    65,
     165,   172,    47,    74,   180,   177,    67,   393,    62,    63,
     182,    68,    69,   153,   154,   155,   156,   157,   158,    64,
      65,   178,   179,   181,    20,    70,   353,    67,    71,    72,
      73,   152,    68,    69,   184,   183,    74,   193,   153,   154,
     155,   156,   157,   158,   256,   -61,    70,    35,   186,    71,
      72,    73,   330,   187,   194,   197,    36,    74,   331,    37,
     153,   154,   155,   156,   157,   158,   367,   153,   154,   155,
     156,   157,   158,   195,   196,   153,   154,   155,   156,   157,
     158,   153,   154,   155,   156,   157,   158,   153,   154,   155,
     156,   157,   158,   188,   140,   140,   141,   141,   141,   200,
     189,   142,   357,   198,   143,   143,   143,   201,   190,   191,
     190,   191,     1,     2,     3,   153,   154,   155,   156,   157,
     158,     4,   202,   206,   207,   208,   216,   218,   209,   219,
     220,   230,   246,   242,   231,   245,   272,   239,   241,   243,
     253,   273,   247,   140,   287,   248,   249,   364,   374,   269,
     266,   278,   279,   280,   294,   283,   284,   285,   286,   291,
     295,   188,   308,   309,   310,   311,   314,   318,   315,   319,
     199,   316,   326,   327,   162,   332,   251,   210,   337,   359,
     298,   333,   356,   358,   360,   338,   339,   341,   361,   362,
     363,   369,   371,   366,   373,   383,   379,   384,   381,   385,
     386,   387,     0,     0,   388,     0,   389,   254,   394,   395,
       0,   390,   397
};

static const yytype_int16 yycheck[] =
{
      35,    53,    53,    64,   140,    66,    39,   134,    99,    48,
     271,    53,    90,    19,     3,     8,    14,    24,    11,    26,
      92,     0,    29,   159,    85,    20,   198,     4,     0,    17,
      65,    14,    67,    31,    40,    28,     8,   209,    26,    11,
      16,    29,    37,    38,    39,     3,     4,     3,     4,    14,
      26,   112,    85,    86,   190,   191,    28,   243,    14,    15,
     196,    19,    18,    52,    15,    42,    22,   119,   119,    27,
      28,    27,    28,    15,   109,    35,    16,   119,    29,    30,
     341,    15,    26,    41,    26,    41,    15,   165,    44,    45,
      46,   152,    26,   165,    52,    29,    52,   283,   284,   285,
     286,     9,    10,   142,    14,    17,   141,    47,    48,    49,
      50,    51,    52,    15,    26,     3,     4,    29,   153,   154,
     155,   156,   157,   158,   260,   261,    26,    29,   161,    29,
      24,   203,    16,   166,    44,    45,    46,    18,   310,    27,
      28,   277,    26,   270,    16,    14,   198,   198,    17,   184,
     189,    14,   230,    41,    14,   327,   198,   209,   209,   194,
     332,    14,    20,   254,    52,   301,   302,   209,    26,   241,
      14,   243,    16,   309,    31,    47,    48,    49,    50,    51,
      52,    44,    45,    46,   311,    25,   358,    14,   360,    29,
      30,    44,    45,    46,    14,   228,     5,     6,     7,   371,
      14,   373,    16,    14,   176,    14,    14,   246,    19,    17,
     337,   283,   284,   285,   286,   387,    37,    38,    39,    16,
      14,   193,    29,   395,    44,    45,    46,    36,   263,   264,
     366,   367,    19,     5,     6,     7,     8,     5,     6,    11,
      12,    13,    14,    14,    14,   280,    14,    20,    19,   282,
      47,    48,    49,    50,    51,    52,   330,   331,   310,   310,
      32,    33,    34,    16,    37,    38,    39,    26,   310,    24,
      29,    43,    44,    45,    46,   327,   327,    14,   330,   331,
     332,   332,   343,    14,    24,   327,    29,    30,    19,    17,
     332,     5,     6,     7,    47,    48,    49,    50,    51,    52,
      14,    96,    97,   338,   339,    29,   358,   358,   360,   360,
      24,     7,    14,    24,     3,     4,   358,    14,   360,   371,
     371,   373,   373,    31,    14,    14,    15,    16,    14,   371,
      17,   373,    16,    22,    26,   387,   387,    15,    27,    28,
      15,     3,    16,   395,   395,   387,    15,     3,     4,    26,
      15,   386,    41,   395,    24,    44,    45,    46,    14,    15,
      19,    14,    26,    52,    14,    23,    22,    16,     3,     4,
      14,    27,    28,    47,    48,    49,    50,    51,    52,    14,
      15,    23,    23,    19,    14,    41,    42,    22,    44,    45,
      46,    18,    27,    28,    15,    14,    52,    15,    47,    48,
      49,    50,    51,    52,    24,    15,    41,    17,    24,    44,
      45,    46,    24,    24,    15,    20,    26,    52,    24,    29,
      47,    48,    49,    50,    51,    52,    26,    47,    48,    49,
      50,    51,    52,    15,    15,    47,    48,    49,    50,    51,
      52,    47,    48,    49,    50,    51,    52,    47,    48,    49,
      50,    51,    52,    14,    15,    15,    17,    17,    17,    24,
      21,    21,    21,    19,    25,    25,    25,    24,    29,    30,
      29,    30,     5,     6,     7,    47,    48,    49,    50,    51,
      52,    14,    24,    17,    31,    17,    25,    14,    19,    14,
      14,    29,    29,    16,    24,    16,     3,    26,    26,    19,
      26,     3,    24,    15,    20,    24,    24,    52,     3,   203,
      27,    26,    26,    26,    20,    26,    26,    26,    26,    24,
      24,    14,    16,    26,    20,    16,    18,    14,    18,    14,
     119,    20,    20,    19,    85,    19,   176,   139,    20,    16,
     253,    24,    20,    19,    19,    26,    26,    26,    16,    20,
      24,    14,    19,    26,    19,    16,    20,    16,    20,    16,
      15,    19,    -1,    -1,    20,    -1,    20,   181,    20,    19,
      -1,    24,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,    14,    36,    54,    55,    57,    61,
      66,    70,    71,    97,   101,   103,   106,    14,    17,    86,
      14,    31,    14,    14,    86,    14,     0,    35,    56,    55,
      26,    67,    55,    15,    24,    17,    26,    29,    62,    83,
      84,    85,    18,    14,    31,    14,    29,    26,    29,   102,
      14,    19,    40,    19,    55,    14,    24,     5,     6,    14,
      72,    73,     3,     4,    14,    15,    18,    22,    27,    28,
      41,    44,    45,    46,    52,    63,    76,    77,    79,    81,
      82,    87,   107,   108,   109,    14,    80,    81,    24,    62,
      29,    86,    15,    29,     7,    14,    14,    76,    24,    98,
      37,    38,    39,    99,   104,     5,     6,     7,     8,    11,
      12,    13,    14,    32,    33,    34,    43,    58,    59,    60,
      61,    77,    78,    79,    87,    88,    89,    90,    92,    93,
      94,    95,    96,   105,    31,    14,    14,    14,    16,    26,
      15,    17,    21,    25,    83,    81,    83,    81,    15,    15,
      15,     3,    18,    47,    48,    49,    50,    51,    52,    29,
      62,    83,    85,    62,    24,    19,    65,    63,    68,    14,
      19,    15,    14,   102,   102,    20,    99,    23,    23,    23,
      14,    19,    14,    14,    15,    81,    24,    24,    14,    21,
      29,    30,    83,    15,    15,    15,    15,    20,    19,    59,
      24,    24,    24,    15,    29,    67,    17,    31,    17,    19,
      72,    16,    75,    80,    14,    76,    25,    16,    14,    14,
      14,    83,    81,    81,    81,    81,    81,    81,    80,    62,
      29,    24,     4,    27,    28,    41,    63,    64,    65,    26,
      62,    26,    16,    19,    69,    16,    29,    24,    24,    24,
      61,    70,   100,    26,    98,    81,    24,    14,    80,    80,
      29,    30,    14,    24,    61,    81,    27,    80,    58,    68,
      14,    19,     3,     3,    58,    74,    16,    26,    26,    26,
      26,    62,    65,    26,    26,    26,    26,    20,    20,    26,
      65,    24,    63,    64,    20,    24,    14,    76,   104,    20,
      16,    29,    30,    80,    80,    81,    81,    16,    16,    26,
      20,    16,    67,    69,    18,    18,    20,    80,    14,    14,
      81,    62,    64,    64,    64,    64,    20,    19,    80,    80,
      24,    24,    19,    24,    80,    58,    67,    20,    26,    26,
      16,    26,    58,    14,    16,    88,    16,    88,    58,    16,
      26,    67,    81,    42,    81,    69,    20,    21,    19,    16,
      19,    16,    20,    24,    52,    16,    26,    26,    91,    14,
      58,    19,    58,    19,     3,    80,    80,     9,    10,    20,
      58,    20,    58,    16,    16,    16,    15,    19,    20,    20,
      24,    81,    58,    16,    20,    19,    58,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    74,    75,    75,    76,    76,    76,
      76,    76,    77,    78,    78,    78,    79,    79,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    93,    94,    95,    96,    97,
      97,    98,    98,    99,    99,    99,    99,   100,   100,   101,
     101,   101,   102,   102,   102,   102,   103,   104,   104,   105,
     105,   106,   107,   108,   108,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     2,     4,     1,     1,     5,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     6,     7,     3,     1,     1,     3,
       4,     5,     6,     0,     1,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     5,
       6,     7,     4,     6,     7,     8,     0,     3,     5,     3,
       7,     2,     2,     3,     2,     3,     3,     3,     1,     2,
       3,     5,     2,     5,     1,     1,     3,     4,     3,     1,
       1,     1,     1,     2,     2,     1,     3,     3,     1,     3,
       3,     2,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     3,
       3,     2,     1,     1,     3,     2,     2,     3,     3,     3,
       4,     4,     1,     5,     5,     2,     8,    12,     0,     8,
      10,     9,    10,     9,     7,     2,     2,     3,     5,     6,
       2,     0,     3,     2,     2,     2,     0,     1,     1,     4,
       6,     6,     0,     3,     5,     5,     7,     2,     4,     7,
      10,     7,     6,    10,    10,     8
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
#line 19 "parse.y"
                   {}
#line 1477 "parse.tab.cpp"
    break;

  case 4: /* Decl: GlobalDecl Decl  */
#line 23 "parse.y"
                   {}
#line 1483 "parse.tab.cpp"
    break;

  case 8: /* GlobalDecl: class_decl  */
#line 30 "parse.y"
                         {}
#line 1489 "parse.tab.cpp"
    break;

  case 9: /* stmt: stmtL OBRACE stmt CBRACE stmt  */
#line 34 "parse.y"
                                     {}
#line 1495 "parse.tab.cpp"
    break;

  case 10: /* stmt: stmtL  */
#line 35 "parse.y"
            {}
#line 1501 "parse.tab.cpp"
    break;

  case 11: /* stmtL: stmtD stmtL  */
#line 38 "parse.y"
                    {}
#line 1507 "parse.tab.cpp"
    break;

  case 12: /* stmtL: %empty  */
#line 39 "parse.y"
      {}
#line 1513 "parse.tab.cpp"
    break;

  case 22: /* declstmt: DATATYPE ID Multideclstmt SEMICOL  */
#line 56 "parse.y"
                                             {}
#line 1519 "parse.tab.cpp"
    break;

  case 23: /* declstmt: DATATYPE ID access Multideclstmt SEMICOL  */
#line 57 "parse.y"
                                               {}
#line 1525 "parse.tab.cpp"
    break;

  case 24: /* declstmt: DATATYPE ID ASSGN rhs Multideclstmt SEMICOL  */
#line 58 "parse.y"
                                                  {}
#line 1531 "parse.tab.cpp"
    break;

  case 25: /* declstmt: DATATYPE ID access2 ASSGN MultiDimL Multideclstmt SEMICOL  */
#line 59 "parse.y"
                                                                 {}
#line 1537 "parse.tab.cpp"
    break;

  case 26: /* declstmt: MatrixDecl MultiMatrixDecl SEMICOL  */
#line 60 "parse.y"
                                         {}
#line 1543 "parse.tab.cpp"
    break;

  case 29: /* Multideclstmt: COMMA ID Multideclstmt  */
#line 65 "parse.y"
                                       {}
#line 1549 "parse.tab.cpp"
    break;

  case 30: /* Multideclstmt: COMMA ID access Multideclstmt  */
#line 66 "parse.y"
                                    {}
#line 1555 "parse.tab.cpp"
    break;

  case 31: /* Multideclstmt: COMMA ID ASSGN rhs Multideclstmt  */
#line 67 "parse.y"
                                       {}
#line 1561 "parse.tab.cpp"
    break;

  case 32: /* Multideclstmt: COMMA ID access2 ASSGN MultiDimL Multideclstmt  */
#line 68 "parse.y"
                                                     {}
#line 1567 "parse.tab.cpp"
    break;

  case 36: /* constL: numbers COMMA constL  */
#line 76 "parse.y"
                              {}
#line 1573 "parse.tab.cpp"
    break;

  case 37: /* constL: FLOAT COMMA constL  */
#line 77 "parse.y"
                         {}
#line 1579 "parse.tab.cpp"
    break;

  case 38: /* constL: STRING COMMA constL  */
#line 78 "parse.y"
                          {}
#line 1585 "parse.tab.cpp"
    break;

  case 39: /* constL: CHAR COMMA constL  */
#line 79 "parse.y"
                        {}
#line 1591 "parse.tab.cpp"
    break;

  case 48: /* MatrixDecl: MATRIX ID MATRIX_TYPE  */
#line 93 "parse.y"
                                   {}
#line 1597 "parse.tab.cpp"
    break;

  case 49: /* MatrixDecl: MATRIX ID MATRIX_TYPE ASSGN ID  */
#line 94 "parse.y"
                                    {}
#line 1603 "parse.tab.cpp"
    break;

  case 50: /* MatrixDecl: MATRIX ID MATRIX_TYPE OBRAK numL CBRAK  */
#line 95 "parse.y"
                                            {}
#line 1609 "parse.tab.cpp"
    break;

  case 51: /* MatrixDecl: MATRIX ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE  */
#line 96 "parse.y"
                                                       {}
#line 1615 "parse.tab.cpp"
    break;

  case 52: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE MultiMatrixDecl  */
#line 99 "parse.y"
                                                       {}
#line 1621 "parse.tab.cpp"
    break;

  case 53: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE ASSGN ID MultiMatrixDecl  */
#line 100 "parse.y"
                                                    {}
#line 1627 "parse.tab.cpp"
    break;

  case 54: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE OBRAK numL CBRAK MultiMatrixDecl  */
#line 101 "parse.y"
                                                            {}
#line 1633 "parse.tab.cpp"
    break;

  case 55: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE MultiMatrixDecl  */
#line 102 "parse.y"
                                                                       {}
#line 1639 "parse.tab.cpp"
    break;

  case 88: /* rhs: pred  */
#line 164 "parse.y"
           {}
#line 1645 "parse.tab.cpp"
    break;

  case 89: /* pred: pred LOG pred  */
#line 168 "parse.y"
                     { }
#line 1651 "parse.tab.cpp"
    break;

  case 90: /* pred: OBRAK pred CBRAK  */
#line 169 "parse.y"
                       { }
#line 1657 "parse.tab.cpp"
    break;

  case 92: /* pred: arg  */
#line 171 "parse.y"
          { }
#line 1663 "parse.tab.cpp"
    break;

  case 93: /* pred: pred COMP pred  */
#line 172 "parse.y"
                     { }
#line 1669 "parse.tab.cpp"
    break;

  case 94: /* pred: pred SHIFT pred  */
#line 173 "parse.y"
                      { }
#line 1675 "parse.tab.cpp"
    break;

  case 95: /* pred: pred BIT_OP pred  */
#line 174 "parse.y"
                       { }
#line 1681 "parse.tab.cpp"
    break;

  case 96: /* pred: pred ARTH pred  */
#line 175 "parse.y"
                     { }
#line 1687 "parse.tab.cpp"
    break;

  case 97: /* pred: pred MINUS pred  */
#line 176 "parse.y"
                      { }
#line 1693 "parse.tab.cpp"
    break;

  case 98: /* arg: ID  */
#line 191 "parse.y"
         {}
#line 1699 "parse.tab.cpp"
    break;

  case 99: /* arg: uni  */
#line 192 "parse.y"
          {}
#line 1705 "parse.tab.cpp"
    break;

  case 100: /* arg: call_expression  */
#line 193 "parse.y"
                      {}
#line 1711 "parse.tab.cpp"
    break;

  case 109: /* access: OSQA pred CSQA  */
#line 204 "parse.y"
                        {}
#line 1717 "parse.tab.cpp"
    break;

  case 111: /* access_assgn: OSQA CSQA  */
#line 209 "parse.y"
                    {}
#line 1723 "parse.tab.cpp"
    break;

  case 115: /* access_retn: OSQA CSQA  */
#line 217 "parse.y"
                    {}
#line 1729 "parse.tab.cpp"
    break;

  case 118: /* expr: ID ASSGN rhs  */
#line 227 "parse.y"
                    {}
#line 1735 "parse.tab.cpp"
    break;

  case 119: /* expr: ID ARTHASSGN rhs  */
#line 228 "parse.y"
                       {}
#line 1741 "parse.tab.cpp"
    break;

  case 120: /* expr: ID access ASSGN rhs  */
#line 229 "parse.y"
                          {}
#line 1747 "parse.tab.cpp"
    break;

  case 121: /* expr: ID access ARTHASSGN rhs  */
#line 230 "parse.y"
                              {}
#line 1753 "parse.tab.cpp"
    break;

  case 122: /* expr: uni  */
#line 231 "parse.y"
          {}
#line 1759 "parse.tab.cpp"
    break;

  case 123: /* expr: ID DOT ID ASSGN rhs  */
#line 232 "parse.y"
                          {}
#line 1765 "parse.tab.cpp"
    break;

  case 124: /* expr: ID DOT ID ARTHASSGN rhs  */
#line 233 "parse.y"
                              {}
#line 1771 "parse.tab.cpp"
    break;


#line 1775 "parse.tab.cpp"

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

#line 334 "parse.y"

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

   if(!yyparse())
   {
     printf("The parsing was successful\n");
   }
   fclose(out); 
   return 1;
}

void yyerror(const char* s)
{
    printf("Error: %s at line %d\n",s,yylineno);
    //fprintf(fp," : invalid statement");
}
