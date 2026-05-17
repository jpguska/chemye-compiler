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
#line 1 "synan.y"

/* synan.y - Parser final para Chemye++ gerador Raposeitor
 *
 * Compatível com lexan.l (estilo original)
 * Aceita apenas as formas de PRINTF:
 *  - PRONUNTIARE |:"texto":|.
 *  - PRONUNTIARE |:"%d, ", expr [, expr ...] :|.
 *
 * Erros:
 *  - Erro lexico -> produzido no lexer (lexan.l)
 *  - Erro sintatico -> yyerror()
 *  - Erro semantico -> sem_erro()
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include <FlexLexer.h>
yyFlexLexer lexer;
int yylex() { return lexer.yylex(); }

void yyerror(const char *s);

/* Tabela de simbolos */
struct simbolo {
    std::string id;
    int end;
};
std::vector<simbolo> tabsimb;
int auxEnd = 0;

/* Contadores */
int T = 0;  /* temporários %t */
int S = 0;  /* labels R... */

/* Pilhas para rótulos usadas nas ações mid-rule reescritas */
std::stack<int> lbl_stack;
/* Pilha para armazenar o índice %t resultante de reduções de 'condicoes' */
std::stack<int> val_stack;
/* Pilhas específicas para laços (loop / exit) */
std::stack<int> loop_stack;
std::stack<int> exit_stack;
  
/* Funções utilitárias */
int getend(const std::string &id) {
    for (auto &s : tabsimb)
        if (s.id == id) return s.end;
    return -1;
}

void sem_erro(const std::string &msg) {
    std::cerr << "Erro semantico: " << msg << std::endl;
    exit(1);
}


#line 131 "bison.tab.cpp"

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

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_MAIS = 6,                       /* MAIS  */
  YYSYMBOL_MENOS = 7,                      /* MENOS  */
  YYSYMBOL_MULT = 8,                       /* MULT  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_MOD = 10,                       /* MOD  */
  YYSYMBOL_MENOR = 11,                     /* MENOR  */
  YYSYMBOL_MAIOR = 12,                     /* MAIOR  */
  YYSYMBOL_MENORIGUAL = 13,                /* MENORIGUAL  */
  YYSYMBOL_MAIORIGUAL = 14,                /* MAIORIGUAL  */
  YYSYMBOL_IGUAL = 15,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 16,                 /* DIFERENTE  */
  YYSYMBOL_MAISMAIS = 17,                  /* MAISMAIS  */
  YYSYMBOL_MENOSMENOS = 18,                /* MENOSMENOS  */
  YYSYMBOL_LCHAVES = 19,                   /* LCHAVES  */
  YYSYMBOL_RCHAVES = 20,                   /* RCHAVES  */
  YYSYMBOL_LCOLCHETES = 21,                /* LCOLCHETES  */
  YYSYMBOL_RCOLCHETES = 22,                /* RCOLCHETES  */
  YYSYMBOL_PEV = 23,                       /* PEV  */
  YYSYMBOL_VIRGULA = 24,                   /* VIRGULA  */
  YYSYMBOL_DOISPONTOS = 25,                /* DOISPONTOS  */
  YYSYMBOL_ATRIB = 26,                     /* ATRIB  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_INT = 31,                       /* INT  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_CHAR = 33,                      /* CHAR  */
  YYSYMBOL_PRINTF = 34,                    /* PRINTF  */
  YYSYMBOL_SCANF = 35,                     /* SCANF  */
  YYSYMBOL_RETURN = 36,                    /* RETURN  */
  YYSYMBOL_DECLARACAO = 37,                /* DECLARACAO  */
  YYSYMBOL_AND = 38,                       /* AND  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_LPAR_EXPR = 41,                 /* LPAR_EXPR  */
  YYSYMBOL_RPAR_EXPR = 42,                 /* RPAR_EXPR  */
  YYSYMBOL_EMPTY_TEMPLATE = 43,            /* EMPTY_TEMPLATE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_programa = 45,                  /* programa  */
  YYSYMBOL_codigos = 46,                   /* codigos  */
  YYSYMBOL_codigo = 47,                    /* codigo  */
  YYSYMBOL_declara = 48,                   /* declara  */
  YYSYMBOL_atrib = 49,                     /* atrib  */
  YYSYMBOL_expr = 50,                      /* expr  */
  YYSYMBOL_termo = 51,                     /* termo  */
  YYSYMBOL_fator = 52,                     /* fator  */
  YYSYMBOL_condicoes = 53,                 /* condicoes  */
  YYSYMBOL_condicao = 54,                  /* condicao  */
  YYSYMBOL_cremento_for = 55,              /* cremento_for  */
  YYSYMBOL_arglist = 56,                   /* arglist  */
  YYSYMBOL_imprime = 57,                   /* imprime  */
  YYSYMBOL_ler = 58,                       /* ler  */
  YYSYMBOL_opt_template = 59,              /* opt_template  */
  YYSYMBOL_condicional = 60,               /* condicional  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_else_part = 63,                 /* else_part  */
  YYSYMBOL_mid_loop_start = 64,            /* mid_loop_start  */
  YYSYMBOL_mid_loop_jf = 65,               /* mid_loop_jf  */
  YYSYMBOL_laco = 66,                      /* laco  */
  YYSYMBOL_retorno = 67                    /* retorno  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

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
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   107,   109,   113,   114,   115,   116,   117,
     118,   119,   125,   130,   141,   150,   158,   169,   183,   187,
     191,   195,   199,   203,   207,   211,   220,   226,   231,   246,
     247,   252,   257,   265,   269,   273,   277,   281,   285,   294,
     295,   302,   305,   313,   321,   340,   346,   358,   360,   361,
     374,   389,   373,   407,   408,   414,   425,   435,   456,   468
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING", "NUM",
  "MAIS", "MENOS", "MULT", "DIV", "MOD", "MENOR", "MAIOR", "MENORIGUAL",
  "MAIORIGUAL", "IGUAL", "DIFERENTE", "MAISMAIS", "MENOSMENOS", "LCHAVES",
  "RCHAVES", "LCOLCHETES", "RCOLCHETES", "PEV", "VIRGULA", "DOISPONTOS",
  "ATRIB", "IF", "ELSE", "FOR", "WHILE", "INT", "FLOAT", "CHAR", "PRINTF",
  "SCANF", "RETURN", "DECLARACAO", "AND", "OR", "NOT", "LPAR_EXPR",
  "RPAR_EXPR", "EMPTY_TEMPLATE", "$accept", "programa", "codigos",
  "codigo", "declara", "atrib", "expr", "termo", "fator", "condicoes",
  "condicao", "cremento_for", "arglist", "imprime", "ler", "opt_template",
  "condicional", "$@1", "$@2", "else_part", "mid_loop_start",
  "mid_loop_jf", "laco", "retorno", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -75,    27,   100,   -75,    33,    -4,    20,    26,    30,    34,
      43,    -1,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
      -1,     2,    -2,    54,   -75,    -5,    42,    86,     9,   -75,
      -1,    22,    68,   -75,    19,    -1,    67,    -2,   139,    60,
      31,   -75,    -2,   123,   -75,    -7,    -8,    -1,     5,    -1,
      -1,   -75,    -1,    -1,    -1,    79,    14,   -75,   -75,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -2,    -2,    -2,   -75,
     111,    -1,   114,    -1,   133,   135,   -75,    68,    68,   -75,
     -75,   -75,     3,   141,   116,   116,   116,   116,   116,   116,
     -75,   -75,   -75,   -75,   124,   142,     8,   125,   -75,   137,
     -75,   -75,    -1,   109,   -75,   -75,   145,   150,   -75,    -1,
     147,   129,    16,   -75,    52,   155,   -75,   -75,   -75,   149,
     151,   -75,   143,    65,   -75,   -75,   148,   -75,   -75,   131,
     -75,    23,   -75,   156,   136,   -75,   158,   -75,   -75,   -75,
      77,    90,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,    55,     0,     0,     0,    25,    26,
       0,     0,    20,    24,     0,     0,     0,     0,     0,     0,
      29,    55,     0,     0,    12,     0,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,     0,    14,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,    27,    18,    19,    21,
      22,    23,     0,    27,    38,    37,    36,    35,    33,    34,
      50,    31,    30,    56,     0,     0,    41,     0,    43,     0,
      45,    28,     0,     0,    15,     3,     0,     0,    13,     0,
       0,     0,     0,    16,     0,     0,     3,    42,    44,     0,
      27,    51,     0,     0,    46,    17,    54,    39,    40,     0,
      58,    47,    52,     0,     0,    48,     0,     3,    49,     3,
       0,     0,    57,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -74,   -75,   -75,   157,   -11,   113,    95,    72,
     -75,   -75,    70,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     140,    89,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    12,    13,    14,    38,    32,    33,    39,
      40,   129,    97,    15,    16,   136,    17,   105,   126,   132,
      42,    94,    18,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    28,    28,    29,    29,    28,    28,    29,    29,    34,
      36,    49,    50,    73,    49,    50,    43,    71,    44,    48,
      49,    50,    49,    50,    56,    49,    50,     3,    49,    50,
      47,   114,   109,    25,    74,    72,    75,    22,    37,    30,
      30,    55,   123,    35,   102,    51,    45,    76,    84,    85,
      86,    87,    88,    89,    20,     4,    83,     4,   120,    21,
      96,    23,    99,   140,   134,   141,   135,    24,     4,    66,
      67,   103,   121,    49,    50,    26,    52,    53,    54,     5,
       4,     6,     7,     8,    27,   130,     9,    10,    11,    46,
      57,   112,     5,     4,     6,     7,     8,   142,    96,     9,
      10,    11,    65,     4,     5,    82,     6,     7,     8,    58,
     143,     9,    10,    11,    69,    49,    50,     5,    90,     6,
       7,     8,    49,    50,     9,    10,    11,     5,    70,     6,
       7,     8,   113,    95,     9,    10,    11,    98,    91,    92,
      93,    49,    50,    49,    50,    49,    50,    79,    80,    81,
      59,    60,    61,    62,    63,    64,   100,   101,   122,   111,
     127,   128,    77,    78,   104,   108,   107,   110,   115,   116,
     118,   119,   124,   133,   125,   137,   131,   139,   138,   117,
      41,    68,   106
};

static const yytype_uint8 yycheck[] =
{
      11,     3,     3,     5,     5,     3,     3,     5,     5,    20,
      21,     6,     7,    21,     6,     7,    21,    24,    23,    30,
       6,     7,     6,     7,    35,     6,     7,     0,     6,     7,
      21,   105,    24,     3,    42,    42,    47,    41,    40,    41,
      41,    22,   116,    41,    41,    23,     4,    42,    59,    60,
      61,    62,    63,    64,    21,     3,    42,     3,    42,    26,
      71,    41,    73,   137,    41,   139,    43,    41,     3,    38,
      39,    82,    20,     6,     7,    41,     8,     9,    10,    27,
       3,    29,    30,    31,    41,    20,    34,    35,    36,     3,
      23,   102,    27,     3,    29,    30,    31,    20,   109,    34,
      35,    36,    42,     3,    27,    26,    29,    30,    31,    37,
      20,    34,    35,    36,    42,     6,     7,    27,    19,    29,
      30,    31,     6,     7,    34,    35,    36,    27,     5,    29,
      30,    31,    23,    22,    34,    35,    36,    23,    66,    67,
      68,     6,     7,     6,     7,     6,     7,    52,    53,    54,
      11,    12,    13,    14,    15,    16,    23,    22,     3,    22,
      17,    18,    49,    50,    23,    23,    42,    42,    23,    19,
      23,    42,    23,    42,    23,    19,    28,    19,    42,   109,
      23,    41,    93
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     3,    27,    29,    30,    31,    34,
      35,    36,    47,    48,    49,    57,    58,    60,    66,    67,
      21,    26,    41,    41,    41,     3,    41,    41,     3,     5,
      41,    50,    51,    52,    50,    41,    50,    40,    50,    53,
      54,    49,    64,    21,    23,     4,     3,    21,    50,     6,
       7,    23,     8,     9,    10,    22,    50,    23,    53,    11,
      12,    13,    14,    15,    16,    42,    38,    39,    64,    53,
       5,    24,    42,    21,    42,    50,    42,    51,    51,    52,
      52,    52,    26,    42,    50,    50,    50,    50,    50,    50,
      19,    53,    53,    53,    65,    22,    50,    56,    23,    50,
      23,    22,    41,    50,    23,    61,    65,    42,    23,    24,
      42,    22,    50,    23,    46,    23,    19,    56,    23,    42,
      42,    20,     3,    46,    23,    23,    62,    17,    18,    55,
      20,    28,    63,    42,    41,    43,    59,    19,    42,    19,
      46,    46,    20,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      50,    51,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      61,    62,    60,    63,    63,    64,    65,    66,    66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     4,     6,     7,     9,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     3,     4,     1,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     5,     7,     5,     8,     0,     1,     2,
       0,     0,    10,     5,     0,     0,     0,    13,     9,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 12: /* declara: INT ID PEV  */
#line 125 "synan.y"
                 {
            if (getend(*(yyvsp[-1].str_val)) != -1) sem_erro("variavel redeclarada: " + *(yyvsp[-1].str_val));
            tabsimb.push_back({ *(yyvsp[-1].str_val), auxEnd++ });
            delete (yyvsp[-1].str_val);
      }
#line 1555 "bison.tab.cpp"
    break;

  case 13: /* declara: INT ID LCOLCHETES NUM RCOLCHETES PEV  */
#line 130 "synan.y"
                                           {
            if (getend(*(yyvsp[-4].str_val)) != -1) sem_erro("variavel redeclarada: " + *(yyvsp[-4].str_val));
            tabsimb.push_back({ *(yyvsp[-4].str_val), auxEnd });
            auxEnd += (yyvsp[-2].int_val);
            delete (yyvsp[-4].str_val);
      }
#line 1566 "bison.tab.cpp"
    break;

  case 14: /* atrib: ID ATRIB expr PEV  */
#line 141 "synan.y"
                        {
            int e = getend(*(yyvsp[-3].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[-3].str_val));

            std::cout << "mov %r" << e << ", %t" << (yyvsp[-1].int_val) << std::endl;
            delete (yyvsp[-3].str_val);
      }
#line 1578 "bison.tab.cpp"
    break;

  case 15: /* atrib: ID ATRIB LPAR_EXPR expr RPAR_EXPR PEV  */
#line 150 "synan.y"
                                            {
            int e = getend(*(yyvsp[-5].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[-5].str_val));

            std::cout << "mov %r" << e << ", %t" << (yyvsp[-2].int_val) << std::endl;
            delete (yyvsp[-5].str_val);
      }
#line 1590 "bison.tab.cpp"
    break;

  case 16: /* atrib: ID LCOLCHETES expr RCOLCHETES ATRIB expr PEV  */
#line 158 "synan.y"
                                                   {
            int e = getend(*(yyvsp[-6].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[-6].str_val));

            std::cout << "store %t" << (yyvsp[-1].int_val) << ", %t" << (yyvsp[-4].int_val)
                      << "(" << e << ")" << std::endl;

            delete (yyvsp[-6].str_val);
      }
#line 1604 "bison.tab.cpp"
    break;

  case 17: /* atrib: ID LCOLCHETES expr RCOLCHETES ATRIB LPAR_EXPR expr RPAR_EXPR PEV  */
#line 169 "synan.y"
                                                                       {
            int e = getend(*(yyvsp[-8].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[-8].str_val));

            std::cout << "store %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[-6].int_val)
                      << "(" << e << ")" << std::endl;

            delete (yyvsp[-8].str_val);
      }
#line 1618 "bison.tab.cpp"
    break;

  case 18: /* expr: expr MAIS termo  */
#line 183 "synan.y"
                      {
            std::cout << "add %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1627 "bison.tab.cpp"
    break;

  case 19: /* expr: expr MENOS termo  */
#line 187 "synan.y"
                       {
            std::cout << "sub %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1636 "bison.tab.cpp"
    break;

  case 20: /* expr: termo  */
#line 191 "synan.y"
            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1642 "bison.tab.cpp"
    break;

  case 21: /* termo: termo MULT fator  */
#line 195 "synan.y"
                       {
            std::cout << "mult %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1651 "bison.tab.cpp"
    break;

  case 22: /* termo: termo DIV fator  */
#line 199 "synan.y"
                      {
            std::cout << "div %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1660 "bison.tab.cpp"
    break;

  case 23: /* termo: termo MOD fator  */
#line 203 "synan.y"
                      {
            std::cout << "mod %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1669 "bison.tab.cpp"
    break;

  case 24: /* termo: fator  */
#line 207 "synan.y"
            { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1675 "bison.tab.cpp"
    break;

  case 25: /* fator: ID  */
#line 211 "synan.y"
         {
            int e = getend(*(yyvsp[0].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[0].str_val));

            std::cout << "mov %t" << T << ", %r" << e << std::endl;
            (yyval.int_val) = T++;
            delete (yyvsp[0].str_val);
      }
#line 1688 "bison.tab.cpp"
    break;

  case 26: /* fator: NUM  */
#line 220 "synan.y"
          {
            std::cout << "mov %t" << T << ", " << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1697 "bison.tab.cpp"
    break;

  case 27: /* fator: LPAR_EXPR expr RPAR_EXPR  */
#line 226 "synan.y"
                               {
            /* apenas retorna o valor da expressao interna */
            (yyval.int_val) = (yyvsp[-1].int_val);
      }
#line 1706 "bison.tab.cpp"
    break;

  case 28: /* fator: ID LCOLCHETES expr RCOLCHETES  */
#line 231 "synan.y"
                                    {
            int e = getend(*(yyvsp[-3].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[-3].str_val));

            std::cout << "load %t" << T << ", %t" << (yyvsp[-1].int_val)
                      << "(" << e << ")" << std::endl;

            (yyval.int_val) = T++;
            delete (yyvsp[-3].str_val);
      }
#line 1721 "bison.tab.cpp"
    break;

  case 29: /* condicoes: condicao  */
#line 246 "synan.y"
               { (yyval.int_val) = (yyvsp[0].int_val); val_stack.push((yyval.int_val)); }
#line 1727 "bison.tab.cpp"
    break;

  case 30: /* condicoes: condicao OR condicoes  */
#line 247 "synan.y"
                            {
            std::cout << "or %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
            val_stack.push((yyval.int_val));
      }
#line 1737 "bison.tab.cpp"
    break;

  case 31: /* condicoes: condicao AND condicoes  */
#line 252 "synan.y"
                             {
            std::cout << "and %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
            val_stack.push((yyval.int_val));
      }
#line 1747 "bison.tab.cpp"
    break;

  case 32: /* condicoes: NOT condicoes  */
#line 257 "synan.y"
                    {
            std::cout << "not %t" << T << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
            val_stack.push((yyval.int_val));
      }
#line 1757 "bison.tab.cpp"
    break;

  case 33: /* condicao: expr IGUAL expr  */
#line 265 "synan.y"
                      {
            std::cout << "equal %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1766 "bison.tab.cpp"
    break;

  case 34: /* condicao: expr DIFERENTE expr  */
#line 269 "synan.y"
                          {
            std::cout << "diff %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1775 "bison.tab.cpp"
    break;

  case 35: /* condicao: expr MAIORIGUAL expr  */
#line 273 "synan.y"
                           {
            std::cout << "greatereq %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1784 "bison.tab.cpp"
    break;

  case 36: /* condicao: expr MENORIGUAL expr  */
#line 277 "synan.y"
                           {
            std::cout << "lesseq %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1793 "bison.tab.cpp"
    break;

  case 37: /* condicao: expr MAIOR expr  */
#line 281 "synan.y"
                      {
            std::cout << "greater %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1802 "bison.tab.cpp"
    break;

  case 38: /* condicao: expr MENOR expr  */
#line 285 "synan.y"
                      {
            std::cout << "less %t" << T << ", %t" << (yyvsp[-2].int_val) << ", %t" << (yyvsp[0].int_val) << std::endl;
            (yyval.int_val) = T++;
      }
#line 1811 "bison.tab.cpp"
    break;

  case 39: /* cremento_for: MAISMAIS  */
#line 294 "synan.y"
               { (yyval.int_val) = 1; }
#line 1817 "bison.tab.cpp"
    break;

  case 40: /* cremento_for: MENOSMENOS  */
#line 295 "synan.y"
                 { (yyval.int_val) = 2; }
#line 1823 "bison.tab.cpp"
    break;

  case 41: /* arglist: expr  */
#line 302 "synan.y"
           {
            std::cout << "printv %t" << (yyvsp[0].int_val) << std::endl;
      }
#line 1831 "bison.tab.cpp"
    break;

  case 42: /* arglist: expr VIRGULA arglist  */
#line 305 "synan.y"
                           {
            std::cout << "printv %t" << (yyvsp[-2].int_val) << std::endl;
      }
#line 1839 "bison.tab.cpp"
    break;

  case 43: /* imprime: PRINTF LPAR_EXPR STRING RPAR_EXPR PEV  */
#line 313 "synan.y"
                                            {
            std::cout << "printf \"" << *(yyvsp[-2].str_val) << "\"" << std::endl;
            delete (yyvsp[-2].str_val);
      }
#line 1848 "bison.tab.cpp"
    break;

  case 44: /* imprime: PRINTF LPAR_EXPR STRING VIRGULA arglist RPAR_EXPR PEV  */
#line 321 "synan.y"
                                                            {
            std::string s = *(yyvsp[-4].str_val);
            size_t pos;
            while ((pos = s.find("%d")) != std::string::npos) s.erase(pos, 2);
            while ((pos = s.find('%')) != std::string::npos) s.erase(pos, 1);
            if (s.empty()) {
                /* emit an empty printf so the runtime doesn't print a stray '%' */
                std::cout << "printf \"\"" << std::endl;
            } else {
                if (s.back() != ' ') s.push_back(' ');
                std::cout << "printf \"" << s << "\"" << std::endl;
            }
            delete (yyvsp[-4].str_val);
      }
#line 1867 "bison.tab.cpp"
    break;

  case 45: /* ler: SCANF LPAR_EXPR ID RPAR_EXPR PEV  */
#line 340 "synan.y"
                                       {
            int e = getend(*(yyvsp[-2].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[-2].str_val));
            std::cout << "read %r" << e << std::endl;
            delete (yyvsp[-2].str_val);
      }
#line 1878 "bison.tab.cpp"
    break;

  case 46: /* ler: SCANF LPAR_EXPR ID LCOLCHETES expr RCOLCHETES RPAR_EXPR PEV  */
#line 346 "synan.y"
                                                                  {
            int e = getend(*(yyvsp[-5].str_val));
            if (e == -1) sem_erro("variavel nao declarada: " + *(yyvsp[-5].str_val));
            std::cout << "read %t" << T << std::endl;
            std::cout << "store %t" << T << ", %t" << (yyvsp[-3].int_val) << "(" << e << ")" << std::endl;
            T++;
            delete (yyvsp[-5].str_val);
      }
#line 1891 "bison.tab.cpp"
    break;

  case 50: /* $@1: %empty  */
#line 374 "synan.y"
        {
            int cond_tmp;
            if (val_stack.empty()) {
                std::cout << "mov %t" << T << ", 1" << std::endl;
                cond_tmp = T++;
            } else {
                cond_tmp = val_stack.top(); val_stack.pop();
            }
            int else_label = S++;
            int end_label = S++;
            std::cout << "jf %t" << cond_tmp << ", R" << else_label << std::endl;
            lbl_stack.push(else_label);
            lbl_stack.push(end_label);
        }
#line 1910 "bison.tab.cpp"
    break;

  case 51: /* $@2: %empty  */
#line 389 "synan.y"
        {
            if (lbl_stack.empty()) sem_erro("lbl_stack vazio no IF");
            int end_label = lbl_stack.top(); lbl_stack.pop();
            if (lbl_stack.empty()) sem_erro("lbl_stack vazio no IF");
            int else_label = lbl_stack.top(); lbl_stack.pop();
            std::cout << "jump R" << end_label << std::endl;
            std::cout << "label R" << else_label << std::endl;
            lbl_stack.push(end_label);  /* push it back for else_part */
        }
#line 1924 "bison.tab.cpp"
    break;

  case 52: /* condicional: IF LPAR_EXPR condicoes RPAR_EXPR LCHAVES $@1 codigos RCHAVES $@2 else_part  */
#line 399 "synan.y"
        {
            if (lbl_stack.empty()) sem_erro("lbl_stack vazio no IF");
            int end_label = lbl_stack.top(); lbl_stack.pop();
            std::cout << "label R" << end_label << std::endl;
        }
#line 1934 "bison.tab.cpp"
    break;

  case 55: /* mid_loop_start: %empty  */
#line 414 "synan.y"
                {
        int loop = S++;
        int exit_label = S++;
        loop_stack.push(loop);
        exit_stack.push(exit_label);
        std::cout << "label R" << loop << std::endl;
    }
#line 1946 "bison.tab.cpp"
    break;

  case 56: /* mid_loop_jf: %empty  */
#line 425 "synan.y"
                {
        if (val_stack.empty()) sem_erro("condicao ausente no for/while");
        int cond_tmp = val_stack.top(); val_stack.pop();
        int exit_label = exit_stack.top();
        std::cout << "jf %t" << cond_tmp << ", R" << exit_label << std::endl;
    }
#line 1957 "bison.tab.cpp"
    break;

  case 57: /* laco: FOR LPAR_EXPR atrib mid_loop_start condicoes mid_loop_jf PEV ID cremento_for RPAR_EXPR LCHAVES codigos RCHAVES  */
#line 435 "synan.y"
                                                                                                                     {
            /* recuperar rótulos */
            int loop = loop_stack.top(); loop_stack.pop();
            int exit_label = exit_stack.top(); exit_stack.pop();

            /* valida var do incremento */
            int e = getend(*(yyvsp[-5].str_val));
            if (e == -1) sem_erro("variavel nao declarada no for: " + *(yyvsp[-5].str_val));

            if ((yyvsp[-4].int_val) == 1)
                std::cout << "add %r" << e << ", %r" << e << ", 1" << std::endl;
            else
                std::cout << "sub %r" << e << ", %r" << e << ", 1" << std::endl;

            std::cout << "jump R" << loop << std::endl;
            std::cout << "label R" << exit_label << std::endl;

            delete (yyvsp[-5].str_val);
      }
#line 1981 "bison.tab.cpp"
    break;

  case 58: /* laco: WHILE LPAR_EXPR mid_loop_start condicoes mid_loop_jf RPAR_EXPR LCHAVES codigos RCHAVES  */
#line 456 "synan.y"
                                                                                             {
            int loop = loop_stack.top(); loop_stack.pop();
            int exit_label = exit_stack.top(); exit_stack.pop();

            std::cout << "jump R" << loop << std::endl;
            std::cout << "label R" << exit_label << std::endl;
    }
#line 1993 "bison.tab.cpp"
    break;

  case 59: /* retorno: RETURN expr PEV  */
#line 468 "synan.y"
                      {
            /* Raposeitor não precisa realmente de ret; colocar label/municao opcional */
            std::cout << "mov %r0, %t" << (yyvsp[-1].int_val) << std::endl; /* coloca em r0 por exemplo */
      }
#line 2002 "bison.tab.cpp"
    break;


#line 2006 "bison.tab.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 474 "synan.y"


/* ---------------- ERRO SINTÁTICO ---------------- */
void yyerror(const char *s) {
    std::cerr << "Erro sintatico: " << s << std::endl;
}

/* ---------------- MAIN ---------------- */
int main(int argc, char **argv) {
    if (argc > 1) {
        std::ifstream fin(argv[1]);
        if (!fin) { perror("open"); return 1; }
        lexer.switch_streams(&fin, nullptr);
    } else {
        lexer.switch_streams(&std::cin, nullptr);
    }
    yyparse();
    return 0;
}
