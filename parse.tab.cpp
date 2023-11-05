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
    using namespace std;
//global variables
int scope = 0;
vector<unordered_map<string,symtab>> sym_table_list;

#line 86 "parse.tab.cpp"

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
  YYSYMBOL_MATRIX = 5,                     /* MATRIX  */
  YYSYMBOL_DF = 6,                         /* DF  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELIF = 8,                       /* ELIF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONT = 12,                      /* CONT  */
  YYSYMBOL_OBRAK = 13,                     /* OBRAK  */
  YYSYMBOL_CBRAK = 14,                     /* CBRAK  */
  YYSYMBOL_OSQA = 15,                      /* OSQA  */
  YYSYMBOL_CSQA = 16,                      /* CSQA  */
  YYSYMBOL_OBRACE = 17,                    /* OBRACE  */
  YYSYMBOL_CBRACE = 18,                    /* CBRACE  */
  YYSYMBOL_DOT = 19,                       /* DOT  */
  YYSYMBOL_NEG = 20,                       /* NEG  */
  YYSYMBOL_COL = 21,                       /* COL  */
  YYSYMBOL_SEMICOL = 22,                   /* SEMICOL  */
  YYSYMBOL_POST = 23,                      /* POST  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_STRING = 25,                    /* STRING  */
  YYSYMBOL_CHAR = 26,                      /* CHAR  */
  YYSYMBOL_ASSGN = 27,                     /* ASSGN  */
  YYSYMBOL_ARTHASSGN = 28,                 /* ARTHASSGN  */
  YYSYMBOL_MATRIX_TYPE = 29,               /* MATRIX_TYPE  */
  YYSYMBOL_FOR = 30,                       /* FOR  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_PRINT = 32,                     /* PRINT  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_CLASS = 34,                     /* CLASS  */
  YYSYMBOL_PRIVATE = 35,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 36,                 /* PROTECTED  */
  YYSYMBOL_PUBLIC = 37,                    /* PUBLIC  */
  YYSYMBOL_INHERITS = 38,                  /* INHERITS  */
  YYSYMBOL_BOOL = 39,                      /* BOOL  */
  YYSYMBOL_NUL = 40,                       /* NUL  */
  YYSYMBOL_SORT = 41,                      /* SORT  */
  YYSYMBOL_SELECT = 42,                    /* SELECT  */
  YYSYMBOL_UPDATE = 43,                    /* UPDATE  */
  YYSYMBOL_DELETE = 44,                    /* DELETE  */
  YYSYMBOL_LOG = 45,                       /* LOG  */
  YYSYMBOL_ARTH = 46,                      /* ARTH  */
  YYSYMBOL_BIT_OP = 47,                    /* BIT_OP  */
  YYSYMBOL_SHIFT = 48,                     /* SHIFT  */
  YYSYMBOL_COMP = 49,                      /* COMP  */
  YYSYMBOL_MINUS = 50,                     /* MINUS  */
  YYSYMBOL_ID = 51,                        /* ID  */
  YYSYMBOL_DATATYPE = 52,                  /* DATATYPE  */
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
#define YYLAST   569

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
       0,    32,    32,    35,    36,    37,    40,    42,    43,    47,
      48,    51,    52,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    69,    73,    77,    80,    81,    82,    83,    86,
      90,    93,    94,    95,    98,    99,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   114,   115,   116,   119,   120,
     121,   122,   125,   126,   127,   128,   129,   132,   135,   136,
     140,   143,   144,   145,   146,   147,   148,   151,   152,   155,
     156,   157,   158,   159,   162,   165,   166,   169,   170,   171,
     172,   173,   176,   179,   180,   181,   185,   186,   190,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   229,   230,
     234,   235,   238,   239,   242,   243,   246,   247,   253,   254,
     255,   256,   257,   258,   259,   262,   266,   267,   270,   271,
     275,   276,   277,   278,   279,   283,   287,   291,   295,   301,
     302,   307,   307,   310,   311,   312,   313,   318,   319,   322,
     323,   324,   327,   328,   329,   330,   334,   336,   337,   341,
     342,   347,   350,   353,   354,   357
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
  "MATRIX", "DF", "IF", "ELIF", "ELSE", "RETURN", "BREAK", "CONT", "OBRAK",
  "CBRAK", "OSQA", "CSQA", "OBRACE", "CBRACE", "DOT", "NEG", "COL",
  "SEMICOL", "POST", "COMMA", "STRING", "CHAR", "ASSGN", "ARTHASSGN",
  "MATRIX_TYPE", "FOR", "WHILE", "PRINT", "MAIN", "CLASS", "PRIVATE",
  "PROTECTED", "PUBLIC", "INHERITS", "BOOL", "NUL", "SORT", "SELECT",
  "UPDATE", "DELETE", "LOG", "ARTH", "BIT_OP", "SHIFT", "COMP", "MINUS",
  "ID", "DATATYPE", "$accept", "S", "Decl", "Main", "GlobalDecl", "stmt",
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
      52,    -5,   -17,   -11,     4,     8,    49,    57,    52,  -262,
      71,    52,    86,  -262,  -262,    85,  -262,    73,   106,   116,
      -1,   132,   242,   112,   225,   128,  -262,   167,    52,  -262,
     140,   217,  -262,    22,  -262,  -262,   189,   252,  -262,   278,
     255,   236,   322,   279,  -262,   247,   254,   328,   281,    -2,
    -262,   292,  -262,   345,  -262,   297,  -262,   270,   277,   282,
     315,   306,    11,    14,   327,   104,   314,   323,   324,   298,
     326,  -262,   317,   356,   361,   368,    19,   358,  -262,  -262,
    -262,  -262,  -262,  -262,   328,   369,   328,  -262,  -262,  -262,
     382,   287,  -262,  -262,  -262,  -262,   392,  -262,  -262,   159,
     367,   441,  -262,   371,   378,   348,   350,   390,   328,   383,
     387,   391,   397,   404,   406,   379,   377,   400,   412,   345,
    -262,   440,  -262,   442,  -262,   444,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,   272,   438,   448,   454,   462,    22,
     456,   467,   465,  -262,   469,   470,    79,  -262,  -262,  -262,
     460,  -262,   466,   443,   445,   446,    25,   473,   476,    64,
     328,  -262,  -262,  -262,   414,  -262,   477,   369,   328,   328,
     328,   328,   328,   328,   328,  -262,    -2,   472,   479,  -262,
     203,   478,   116,   328,   151,  -262,  -262,   166,   328,   480,
     328,   417,   328,   328,   101,   218,   244,  -262,   345,  -262,
    -262,  -262,  -262,    11,    31,  -262,  -262,   500,   501,   345,
    -262,    11,  -262,   205,   488,   485,  -262,  -262,  -262,  -262,
     278,   175,   434,   484,   486,   487,  -262,    84,  -262,  -262,
    -262,  -262,   496,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   367,  -262,   378,  -262,   489,   490,   491,  -262,
     492,   494,   163,    55,   495,   176,  -262,   328,   468,   328,
     313,   504,   497,   119,  -262,  -262,   328,   328,   502,   508,
     465,    71,   507,   509,  -262,   506,  -262,   510,  -262,  -262,
    -262,  -262,   496,  -262,   475,   481,   328,  -262,   328,  -262,
     478,   205,   205,   205,   205,  -262,  -262,   378,  -262,  -262,
     512,   398,   405,   513,   505,   328,   328,   328,  -262,  -262,
     345,    71,   515,  -262,  -262,  -262,  -262,   511,   514,   516,
     366,  -262,  -262,  -262,  -262,  -262,  -262,   345,    -4,     3,
     345,  -262,   109,  -262,  -262,  -262,  -262,    71,   465,   328,
      76,  -262,   518,   517,   265,   523,   522,   527,   524,   521,
     498,  -262,  -262,   376,   520,   425,  -262,   345,   499,   528,
     345,   529,  -262,  -262,   544,  -262,   328,   328,   206,   531,
     220,   345,   533,   345,   538,   539,   540,   542,   541,  -262,
     543,  -262,   545,   534,  -262,  -262,   328,   345,  -262,  -262,
    -262,   386,   546,   548,  -262,   345,   549,  -262
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     3,     7,
      56,     3,     0,     8,    27,     0,    28,     0,     0,    64,
       0,     0,    62,     0,    33,     0,     1,     0,     3,     4,
       0,     0,     5,     0,   140,    63,    48,     0,   141,   146,
     115,     0,     0,     0,    66,     0,     0,     0,     0,    33,
     113,     0,    65,    12,     2,     0,    26,     0,     0,     0,
       0,    68,     0,     0,     0,   146,     0,     0,     0,     0,
       0,   114,     0,     0,     0,     0,   152,   152,    81,    79,
      80,   149,    34,   102,     0,   111,     0,   105,   104,   103,
       0,    98,   101,    82,   100,   107,     0,    92,    99,    33,
      33,    88,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    12,
      13,     0,    15,     0,   122,     0,    14,    16,    17,    20,
      21,    18,    19,    85,    56,     0,    72,    69,     0,     0,
       0,     0,     0,    49,     0,     0,     0,   143,   145,   144,
     157,   141,   153,     0,     0,     0,     0,     0,     0,     0,
       0,   110,    91,    35,     0,   116,   106,   109,     0,     0,
       0,     0,     0,     0,     0,    29,    33,     0,     0,    23,
       0,    33,     0,     0,     0,   135,   136,     0,     0,     0,
       0,     0,     0,     0,   152,     0,    33,     6,    12,    11,
      83,    84,   125,     0,     0,    52,    70,     0,     0,    12,
      67,     0,    50,     0,     0,     0,   139,   147,   148,   142,
     146,   146,     0,     0,     0,     0,    78,     0,    75,   151,
     150,    90,    86,    87,   117,   108,    89,    96,    95,    94,
      93,    97,    33,    30,     0,    24,    41,    42,    43,    44,
      40,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,     0,     0,    86,   118,   119,     0,     0,     0,     0,
       0,    56,     0,     0,    74,     0,    57,     0,    51,   161,
     158,   156,   155,   154,     0,     0,     0,    77,     0,    31,
      33,     0,     0,     0,     0,    47,    45,     0,    46,    25,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
      12,    56,     0,    53,    73,    71,    60,    59,     0,     0,
       0,    76,    32,    37,    38,    39,    36,    12,     0,     0,
      12,   138,     0,   123,   124,     9,    54,    56,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    58,     0,     0,     0,   128,    12,     0,     0,
      12,     0,   134,   159,     0,   165,     0,     0,   126,     0,
       0,    12,     0,    12,     0,     0,     0,     0,     0,   133,
       0,   131,     0,     0,   164,   163,     0,    12,   132,   130,
     160,     0,     0,     0,   127,    12,     0,   129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,    89,  -262,  -262,  -168,   447,  -262,     7,   -47,
     -59,  -200,   -93,  -262,  -133,   354,  -261,   385,  -262,   420,
    -262,  -262,  -262,    -9,   -49,  -262,   -48,  -130,    -3,  -262,
     -79,  -262,   461,    16,   -53,   -34,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   411,   -57,  -262,  -262,   240,
    -262,   349,  -262,  -262,  -262,  -262,  -262
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,     7,    28,     8,   117,   118,   119,   120,    48,
      92,   251,   298,    10,    31,   141,   214,    11,    12,    60,
      61,   275,   227,    93,    94,   122,    95,   100,   101,    97,
      49,    50,    51,    23,    98,   125,   126,   127,   368,   128,
     129,   130,   131,   132,    13,    65,    69,   219,    14,    43,
      15,    70,   133,    16,    78,    79,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     124,   205,   103,   140,   121,   123,   161,     9,   146,   312,
     343,   181,   166,   277,    82,     9,    38,   346,     9,    21,
     176,    25,    46,    21,    17,  -112,   228,    57,    82,    83,
     268,   142,   156,    77,    19,     9,   195,    39,    84,   226,
      20,   274,    96,    41,   242,    86,    18,   344,   270,    26,
      87,    88,   175,   178,   344,    22,    71,     1,     2,    24,
     262,    90,   264,   265,    89,   143,   124,    73,    74,    75,
     121,   123,   180,    58,    59,    90,    91,   352,   231,    82,
      83,   159,   271,   162,     1,     2,     3,   252,   235,    84,
      27,   323,   324,   325,   326,    30,    86,    29,   287,    33,
      32,    87,    88,     4,     5,   184,    99,    34,   288,   168,
     169,   170,   171,   172,   173,    89,   354,    54,    73,    74,
      75,   250,   145,   349,    35,    41,    90,    91,    42,   243,
       4,     5,   156,   350,   254,    36,   308,   309,   313,    66,
      67,    68,   335,    37,   140,   124,   306,   307,    40,   121,
     123,   290,   276,   217,   250,   233,   124,    96,   321,   342,
     121,   123,   348,    44,   146,   236,   237,   238,   239,   240,
     241,   105,   106,   256,    45,   332,   333,   334,   336,    52,
     255,   296,   233,    46,    53,   260,   174,   297,   257,   369,
     300,    55,   372,   281,   259,   289,   168,   169,   170,   171,
     172,   173,    62,   380,   351,   382,    82,   246,    82,   246,
      66,    67,    68,   283,   377,   378,    63,   258,   116,   392,
     180,   168,   169,   170,   171,   172,   173,   396,   247,   248,
     247,   248,   250,   250,   250,   250,   375,   376,   -61,    56,
      45,   234,   249,   322,   249,   266,   267,   306,   307,    46,
      82,    83,    47,    90,   301,    90,   302,   124,    64,    45,
      84,   121,   123,    85,  -152,   195,    41,    86,    46,    42,
      21,    47,    87,    88,   124,   124,   124,   124,   121,   123,
     160,   121,   123,   320,   358,   203,    89,    72,   165,    73,
      74,    75,   192,   193,   345,   347,    30,    90,    91,   204,
     156,    81,   160,   102,   124,    99,   164,   124,   121,   123,
     165,   121,   123,    66,    67,    68,   157,   158,   124,   104,
     124,   135,   121,   123,   121,   123,   134,   303,   136,   138,
     139,    82,    83,   137,   124,   147,   353,   355,   121,   123,
     144,    84,   124,   151,   148,   149,   121,   123,    86,   150,
     105,   106,   107,    87,    88,   108,   109,   110,   168,   169,
     170,   171,   172,   173,    73,    74,    75,    89,   152,   153,
      73,    74,    75,    76,   154,   111,   112,   113,    90,    91,
     341,   155,    41,   391,   160,   163,   114,    73,    74,    75,
     365,    46,   156,   179,   160,   180,   115,   116,   191,    18,
     393,   182,   165,   183,   187,   185,   192,   193,   167,   186,
     188,   168,   169,   170,   171,   172,   173,   189,   197,   190,
     328,   168,   169,   170,   171,   172,   173,   329,   196,   198,
     194,   168,   169,   170,   171,   172,   173,   168,   169,   170,
     171,   172,   173,   168,   169,   170,   171,   172,   173,   367,
     168,   169,   170,   171,   172,   173,    73,    74,    75,    73,
      74,    75,   200,   207,   201,   232,   202,   206,   263,   208,
     168,   169,   170,   171,   172,   173,    73,    74,    75,   209,
     211,   212,   213,   215,   220,   282,   168,   169,   170,   171,
     172,   173,   216,   222,   223,   229,   224,   225,   230,   244,
     234,   245,   253,   272,   273,   261,   278,   279,   284,   156,
     285,   286,   295,   291,   292,   293,   294,   299,   304,   194,
     310,   305,   311,   314,   316,   315,   318,   331,   317,   327,
     330,   218,   319,   337,   357,   338,   356,   359,   339,   360,
     340,   361,   362,   363,   366,   371,   373,   374,   364,   379,
     370,   381,   383,   384,   385,   386,   390,   269,   387,   210,
     177,   388,   221,   389,   394,   395,   199,   397,     0,   280
};

static const yytype_int16 yycheck[] =
{
      53,   134,    49,    62,    53,    53,    85,     0,    65,   270,
      14,   104,    91,   213,     3,     8,    17,    14,    11,    15,
      99,     5,    24,    15,    29,    27,   156,     5,     3,     4,
     198,    17,    13,    42,    51,    28,   115,    38,    13,    14,
      51,   209,    45,    24,   174,    20,    51,    51,    17,     0,
      25,    26,    99,   100,    51,    51,    40,     5,     6,    51,
     190,    50,   192,   193,    39,    51,   119,    42,    43,    44,
     119,   119,    17,    51,    52,    50,    51,   338,    14,     3,
       4,    84,    51,    86,     5,     6,    34,   180,   167,    13,
      33,   291,   292,   293,   294,    24,    20,     8,    14,    13,
      11,    25,    26,    51,    52,   108,    51,    22,    24,    45,
      46,    47,    48,    49,    50,    39,    40,    28,    42,    43,
      44,   180,    18,    14,    51,    24,    50,    51,    27,   176,
      51,    52,    13,    24,   181,    29,   266,   267,   271,    35,
      36,    37,   310,    27,   203,   198,    27,    28,    16,   198,
     198,   244,   211,   146,   213,   164,   209,   160,   288,   327,
     209,   209,   330,    51,   221,   168,   169,   170,   171,   172,
     173,     5,     6,    22,    15,   305,   306,   307,   311,    51,
     183,    18,   191,    24,    17,   188,    27,    24,    22,   357,
      14,    51,   360,    18,   187,   242,    45,    46,    47,    48,
      49,    50,    13,   371,   337,   373,     3,     4,     3,     4,
      35,    36,    37,   222,     8,     9,    27,    51,    52,   387,
      17,    45,    46,    47,    48,    49,    50,   395,    25,    26,
      25,    26,   291,   292,   293,   294,   366,   367,    13,    22,
      15,    23,    39,   290,    39,    27,    28,    27,    28,    24,
       3,     4,    27,    50,   257,    50,   259,   310,     6,    15,
      13,   310,   310,    16,    22,   344,    24,    20,    24,    27,
      15,    27,    25,    26,   327,   328,   329,   330,   327,   327,
      15,   330,   330,   286,    19,    13,    39,    51,    23,    42,
      43,    44,    27,    28,   328,   329,    24,    50,    51,    27,
      13,    22,    15,    22,   357,    51,    19,   360,   357,   357,
      23,   360,   360,    35,    36,    37,    76,    77,   371,    27,
     373,    51,   371,   371,   373,   373,    29,    14,    51,    14,
      24,     3,     4,    51,   387,    21,   339,   340,   387,   387,
      13,    13,   395,    17,    21,    21,   395,   395,    20,    51,
       5,     6,     7,    25,    26,    10,    11,    12,    45,    46,
      47,    48,    49,    50,    42,    43,    44,    39,    51,    13,
      42,    43,    44,    51,    13,    30,    31,    32,    50,    51,
      14,    13,    24,   386,    15,     3,    41,    42,    43,    44,
      14,    24,    13,    22,    15,    17,    51,    52,    19,    51,
      14,    51,    23,    13,    13,    22,    27,    28,    16,    22,
      13,    45,    46,    47,    48,    49,    50,    13,    18,    13,
      22,    45,    46,    47,    48,    49,    50,    22,    51,    17,
      51,    45,    46,    47,    48,    49,    50,    45,    46,    47,
      48,    49,    50,    45,    46,    47,    48,    49,    50,    24,
      45,    46,    47,    48,    49,    50,    42,    43,    44,    42,
      43,    44,    22,    15,    22,    51,    22,    29,    51,    15,
      45,    46,    47,    48,    49,    50,    42,    43,    44,    17,
      24,    14,    17,    14,    24,    51,    45,    46,    47,    48,
      49,    50,    22,    27,    51,    22,    51,    51,    22,    27,
      23,    22,    24,     3,     3,    25,    18,    22,    24,    13,
      24,    24,    18,    24,    24,    24,    24,    22,    14,    51,
      18,    24,    14,    16,    18,    16,    51,    22,    18,    17,
      17,   146,    51,    18,    17,    24,    18,    14,    24,    17,
      24,    14,    18,    22,    24,    17,    17,     3,    50,    18,
      51,    18,    14,    14,    14,    13,    22,   203,    17,   139,
      99,    18,   151,    18,    18,    17,   119,    18,    -1,   220
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    34,    51,    52,    54,    55,    57,    61,
      66,    70,    71,    97,   101,   103,   106,    29,    51,    51,
      51,    15,    51,    86,    51,    86,     0,    33,    56,    55,
      24,    67,    55,    13,    22,    51,    29,    27,    17,    38,
      16,    24,    27,   102,    51,    15,    24,    27,    62,    83,
      84,    85,    51,    17,    55,    51,    22,     5,    51,    52,
      72,    73,    13,    27,     6,    98,    35,    36,    37,    99,
     104,    86,    51,    42,    43,    44,    51,    76,   107,   108,
     109,    22,     3,     4,    13,    16,    20,    25,    26,    39,
      50,    51,    63,    76,    77,    79,    81,    82,    87,    51,
      80,    81,    22,    62,    27,     5,     6,     7,    10,    11,
      12,    30,    31,    32,    41,    51,    52,    58,    59,    60,
      61,    77,    78,    79,    87,    88,    89,    90,    92,    93,
      94,    95,    96,   105,    29,    51,    51,    51,    14,    24,
      63,    68,    17,    51,    13,    18,    99,    21,    21,    21,
      51,    17,    51,    13,    13,    13,    13,   102,   102,    81,
      15,    83,    81,     3,    19,    23,    83,    16,    45,    46,
      47,    48,    49,    50,    27,    62,    83,    85,    62,    22,
      17,    65,    51,    13,    81,    22,    22,    13,    13,    13,
      13,    19,    27,    28,    51,    83,    51,    18,    17,    59,
      22,    22,    22,    13,    27,    67,    29,    15,    15,    17,
      72,    24,    14,    17,    69,    14,    22,    61,    70,   100,
      24,    98,    27,    51,    51,    51,    14,    75,    80,    22,
      22,    14,    51,    76,    23,    83,    81,    81,    81,    81,
      81,    81,    80,    62,    27,    22,     4,    25,    26,    39,
      63,    64,    65,    24,    62,    81,    22,    22,    51,    61,
      81,    25,    80,    51,    80,    80,    27,    28,    58,    68,
      17,    51,     3,     3,    58,    74,    63,    64,    18,    22,
     104,    18,    51,    76,    24,    24,    24,    14,    24,    62,
      65,    24,    24,    24,    24,    18,    18,    24,    65,    22,
      14,    81,    81,    14,    14,    24,    27,    28,    80,    80,
      18,    14,    69,    67,    16,    16,    18,    18,    51,    51,
      81,    80,    62,    64,    64,    64,    64,    17,    22,    22,
      17,    22,    80,    80,    80,    58,    67,    18,    24,    24,
      24,    14,    58,    14,    51,    88,    14,    88,    58,    14,
      24,    67,    69,    81,    40,    81,    18,    17,    19,    14,
      17,    14,    18,    22,    50,    14,    24,    24,    91,    58,
      51,    17,    58,    17,     3,    80,    80,     8,     9,    18,
      58,    18,    58,    14,    14,    14,    13,    17,    18,    18,
      22,    81,    58,    14,    18,    17,    58,    18
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
#line 32 "parse.y"
                   {}
#line 1476 "parse.tab.cpp"
    break;

  case 4: /* Decl: GlobalDecl Decl  */
#line 36 "parse.y"
                   {}
#line 1482 "parse.tab.cpp"
    break;

  case 8: /* GlobalDecl: class_decl  */
#line 43 "parse.y"
                         {}
#line 1488 "parse.tab.cpp"
    break;

  case 9: /* stmt: stmtL OBRACE stmt CBRACE stmt  */
#line 47 "parse.y"
                                     {}
#line 1494 "parse.tab.cpp"
    break;

  case 10: /* stmt: stmtL  */
#line 48 "parse.y"
            {}
#line 1500 "parse.tab.cpp"
    break;

  case 11: /* stmtL: stmtD stmtL  */
#line 51 "parse.y"
                    {}
#line 1506 "parse.tab.cpp"
    break;

  case 12: /* stmtL: %empty  */
#line 52 "parse.y"
      {}
#line 1512 "parse.tab.cpp"
    break;

  case 22: /* declstmt: DATATYPE ID Multideclstmt SEMICOL  */
#line 69 "parse.y"
                                             { 
                               (yyvsp[-2].datatype).type = (yyvsp[-3].datatype).type;
                               (yyvsp[-1].datatype).type = (yyvsp[-2].datatype).type;           
                                             }
#line 1521 "parse.tab.cpp"
    break;

  case 23: /* declstmt: DATATYPE ID access Multideclstmt SEMICOL  */
#line 73 "parse.y"
                                               {
              (yyvsp[-3].datatype).type = (yyvsp[-4].datatype).type;
              (yyvsp[-1].datatype).type = (yyvsp[-3].datatype).type;  
    }
#line 1530 "parse.tab.cpp"
    break;

  case 24: /* declstmt: DATATYPE ID ASSGN rhs Multideclstmt SEMICOL  */
#line 77 "parse.y"
                                                  {
        
    }
#line 1538 "parse.tab.cpp"
    break;

  case 25: /* declstmt: DATATYPE ID access2 ASSGN MultiDimL Multideclstmt SEMICOL  */
#line 80 "parse.y"
                                                                 {}
#line 1544 "parse.tab.cpp"
    break;

  case 26: /* declstmt: MatrixDecl MultiMatrixDecl SEMICOL  */
#line 81 "parse.y"
                                         {}
#line 1550 "parse.tab.cpp"
    break;

  case 29: /* Multideclstmt: COMMA ID Multideclstmt  */
#line 86 "parse.y"
                                       {
    (yyvsp[-1].datatype).type= (yyval.datatype).type;
    (yyvsp[0].datatype).type= (yyval.datatype).type;
}
#line 1559 "parse.tab.cpp"
    break;

  case 30: /* Multideclstmt: COMMA ID access Multideclstmt  */
#line 90 "parse.y"
                                    {
               
    }
#line 1567 "parse.tab.cpp"
    break;

  case 31: /* Multideclstmt: COMMA ID ASSGN rhs Multideclstmt  */
#line 93 "parse.y"
                                       {}
#line 1573 "parse.tab.cpp"
    break;

  case 32: /* Multideclstmt: COMMA ID access2 ASSGN MultiDimL Multideclstmt  */
#line 94 "parse.y"
                                                     {}
#line 1579 "parse.tab.cpp"
    break;

  case 36: /* constL: numbers COMMA constL  */
#line 102 "parse.y"
                              {}
#line 1585 "parse.tab.cpp"
    break;

  case 37: /* constL: FLOAT COMMA constL  */
#line 103 "parse.y"
                         {}
#line 1591 "parse.tab.cpp"
    break;

  case 38: /* constL: STRING COMMA constL  */
#line 104 "parse.y"
                          {}
#line 1597 "parse.tab.cpp"
    break;

  case 39: /* constL: CHAR COMMA constL  */
#line 105 "parse.y"
                        {}
#line 1603 "parse.tab.cpp"
    break;

  case 48: /* MatrixDecl: MATRIX ID MATRIX_TYPE  */
#line 119 "parse.y"
                                   {}
#line 1609 "parse.tab.cpp"
    break;

  case 49: /* MatrixDecl: MATRIX ID MATRIX_TYPE ASSGN ID  */
#line 120 "parse.y"
                                    {}
#line 1615 "parse.tab.cpp"
    break;

  case 50: /* MatrixDecl: MATRIX ID MATRIX_TYPE OBRAK numL CBRAK  */
#line 121 "parse.y"
                                            {}
#line 1621 "parse.tab.cpp"
    break;

  case 51: /* MatrixDecl: MATRIX ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE  */
#line 122 "parse.y"
                                                       {}
#line 1627 "parse.tab.cpp"
    break;

  case 52: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE MultiMatrixDecl  */
#line 125 "parse.y"
                                                       {}
#line 1633 "parse.tab.cpp"
    break;

  case 53: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE ASSGN ID MultiMatrixDecl  */
#line 126 "parse.y"
                                                    {}
#line 1639 "parse.tab.cpp"
    break;

  case 54: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE OBRAK numL CBRAK MultiMatrixDecl  */
#line 127 "parse.y"
                                                            {}
#line 1645 "parse.tab.cpp"
    break;

  case 55: /* MultiMatrixDecl: COMMA ID MATRIX_TYPE ASSGN OBRACE MatrixL CBRACE MultiMatrixDecl  */
#line 128 "parse.y"
                                                                       {}
#line 1651 "parse.tab.cpp"
    break;

  case 88: /* rhs: pred  */
#line 190 "parse.y"
           {}
#line 1657 "parse.tab.cpp"
    break;

  case 89: /* pred: pred LOG pred  */
#line 194 "parse.y"
                     { }
#line 1663 "parse.tab.cpp"
    break;

  case 90: /* pred: OBRAK pred CBRAK  */
#line 195 "parse.y"
                       { }
#line 1669 "parse.tab.cpp"
    break;

  case 92: /* pred: arg  */
#line 197 "parse.y"
          { }
#line 1675 "parse.tab.cpp"
    break;

  case 93: /* pred: pred COMP pred  */
#line 198 "parse.y"
                     { }
#line 1681 "parse.tab.cpp"
    break;

  case 94: /* pred: pred SHIFT pred  */
#line 199 "parse.y"
                      { }
#line 1687 "parse.tab.cpp"
    break;

  case 95: /* pred: pred BIT_OP pred  */
#line 200 "parse.y"
                       { }
#line 1693 "parse.tab.cpp"
    break;

  case 96: /* pred: pred ARTH pred  */
#line 201 "parse.y"
                     { }
#line 1699 "parse.tab.cpp"
    break;

  case 97: /* pred: pred MINUS pred  */
#line 202 "parse.y"
                      { }
#line 1705 "parse.tab.cpp"
    break;

  case 98: /* arg: ID  */
#line 217 "parse.y"
         {}
#line 1711 "parse.tab.cpp"
    break;

  case 99: /* arg: uni  */
#line 218 "parse.y"
          {}
#line 1717 "parse.tab.cpp"
    break;

  case 100: /* arg: call_expression  */
#line 219 "parse.y"
                      {}
#line 1723 "parse.tab.cpp"
    break;

  case 109: /* access: OSQA pred CSQA  */
#line 230 "parse.y"
                        {}
#line 1729 "parse.tab.cpp"
    break;

  case 111: /* access_assgn: OSQA CSQA  */
#line 235 "parse.y"
                    {}
#line 1735 "parse.tab.cpp"
    break;

  case 115: /* access_retn: OSQA CSQA  */
#line 243 "parse.y"
                    {}
#line 1741 "parse.tab.cpp"
    break;

  case 118: /* expr: ID ASSGN rhs  */
#line 253 "parse.y"
                    {}
#line 1747 "parse.tab.cpp"
    break;

  case 119: /* expr: ID ARTHASSGN rhs  */
#line 254 "parse.y"
                       {}
#line 1753 "parse.tab.cpp"
    break;

  case 120: /* expr: ID access ASSGN rhs  */
#line 255 "parse.y"
                          {}
#line 1759 "parse.tab.cpp"
    break;

  case 121: /* expr: ID access ARTHASSGN rhs  */
#line 256 "parse.y"
                              {}
#line 1765 "parse.tab.cpp"
    break;

  case 122: /* expr: uni  */
#line 257 "parse.y"
          {}
#line 1771 "parse.tab.cpp"
    break;

  case 123: /* expr: ID DOT ID ASSGN rhs  */
#line 258 "parse.y"
                          {}
#line 1777 "parse.tab.cpp"
    break;

  case 124: /* expr: ID DOT ID ARTHASSGN rhs  */
#line 259 "parse.y"
                              {}
#line 1783 "parse.tab.cpp"
    break;


#line 1787 "parse.tab.cpp"

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

#line 360 "parse.y"

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
