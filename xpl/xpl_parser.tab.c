/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "xpl_parser.y"
/* $Id: xpl_parser.y,v 1.8 2017/05/22 15:31:54 ist181115 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "xpl_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;	/* integer value */
  double                d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  xpl::block_node      *b;
  xpl::function_declaration_node    *fdecl;
  xpl::function_definition_node     *fdef;
  xpl::function_call_node           *fcall;
  basic_type           *t;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "xpl_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 57 "xpl_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tDOUBLE 258
#define tIDENTIFIER 259
#define tSTRING 260
#define tWHILE 261
#define tIF 262
#define tPRINT 263
#define tINT 264
#define tREAL 265
#define tPROCEDURE 266
#define tPUBLIC 267
#define tUSED 268
#define tELSIF 269
#define tSWEEP 270
#define tNEXT 271
#define tNULL 272
#define tSTOP 273
#define tRETURN 274
#define tSTR 275
#define tPRINTLN 276
#define tIFX 277
#define tELSE 278
#define tEQ 279
#define tNE 280
#define tLE 281
#define tGE 282
#define tUNARY 283
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    8,    8,    1,    1,    1,   13,   13,    2,
    2,    2,    2,    2,    2,   19,   19,   19,   19,   19,
   19,   20,   20,   20,   20,   20,   20,   15,   15,   15,
   15,   22,   22,   10,   10,   11,   11,    6,   21,   21,
   21,   21,   18,   18,   18,   18,    9,    9,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    4,    4,    7,
    7,    7,    5,    5,    5,    5,    5,   12,   12,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   17,   17,   16,   16,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    2,    1,    1,    2,    3,    3,
    3,    2,    5,    5,    4,    6,    6,    5,    6,    6,
    5,    7,    6,    9,    8,    7,    6,    1,    1,    1,
    1,    1,    2,    1,    0,    1,    3,    2,    1,    1,
    1,    3,    4,    3,    3,    2,    1,    2,    2,    2,
    2,    1,    1,    1,    1,    1,    1,    5,    6,    6,
    2,    5,    5,   10,   12,   10,   12,    1,    3,    2,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    3,    3,    3,    1,    1,    3,
    2,    1,    1,    4,    4,    3,
};
static const YYINT yydefred[] = {                         0,
   39,   40,    0,    0,    0,   41,    0,    0,    3,    0,
    0,    6,    7,    0,    0,    0,    0,    0,    0,    0,
    5,    4,    0,    0,    0,    0,    0,    0,   42,    0,
    0,   36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   28,   29,    0,   32,   31,    0,    0,    0,    0,
   88,    0,   92,   89,    0,    0,    0,    0,    0,   38,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   91,   33,    0,    0,
   27,   37,    0,    0,   20,   17,   96,    0,    0,   90,
   83,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,    0,    0,
    0,    0,    0,   53,   52,   54,    0,   46,    0,   47,
   55,   56,    0,    0,    0,   57,    0,   26,    0,   22,
   95,    0,   94,    0,    0,    0,    0,    0,    0,    0,
    8,   45,   48,   44,    0,    0,   50,   51,   49,    0,
    0,    0,   25,    0,    0,    0,    0,    0,    0,    9,
   43,   24,    0,    0,    0,    0,    0,   63,    0,    0,
    0,    0,    0,   59,    0,    0,    0,   61,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   64,
    0,   66,    0,   60,    0,    0,   65,   67,
};
static const YYINT yydgoto[] = {                          8,
    9,   10,  130,  131,  132,   32,  184,   11,  133,   33,
   34,   98,  134,  135,   53,   54,   55,  136,   12,   13,
   35,   56,
};
static const YYINT yysindex[] = {                       -14,
    0,    0, -244,  -58,  -31,    0,  -52,    0,    0,  -37,
  -14,    0,    0, -214,   28, -201, -190, -184, -178,    3,
    0,    0,   -9,  -52,   53,   -6,   66,    4,    0, 1341,
  -52,    0,   71,   82, -132,  -52, 1341,  -52,  -52, 1341,
  -52,    0,    0,   97,    0,    0, 1341, 1341, 1341, 1341,
    0,  728,    0,    0,   44, -122,   99,   20,  -52,    0,
  100,  728,  103,  110,  728,  122,  504,   74,   74,  419,
  435, 1341, 1341, 1341, 1341, 1341, 1341, 1341, 1341, 1341,
 1341, 1341, 1341, 1341, 1341, 1341,    0,    0,  -61,  986,
    0,    0,   20,  -45,    0,    0,    0,  -27,  728,    0,
    0,  779,  793,  358,  358,   -7,   -7,   -7,   -7,   -5,
   -5,   74,   74,   74,  461,  728, -211,    0,  128,  129,
  -52,  -52,   90,    0,    0,    0, 1026,    0,  107,    0,
    0,    0, 1056, 1006,  317,    0,  -88,    0, -211,    0,
    0, 1341,    0,   20, 1341, 1341,  -87,  -86,  134,  138,
    0,    0,    0,    0,  123, 1103,    0,    0,    0,  125,
   20,  728,    0,  532,  564,  127,  131, 1341, 1341,    0,
    0,    0, 1302, 1302,  728,  -10,   60,    0, -228, 1341,
 1341,  143, 1302,    0,  599,  631, 1341,    0, 1341, 1341,
  665,  369,  405, 1302, 1302, 1341, 1302, 1341, -228,    0,
  691,    0,  707,    0, 1302, 1302,    0,    0,
};
static const YYINT yyrindex[] = {                       187,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  189,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  136,  149,    0,  137,    0,  145,    0,    0,
  149,    0,    0,  161,    0,  149,    0,  149,  149,    0,
  149,    0,    0,  -34,    0,    0,    0,    0,    0,    0,
    0,  146,    0,    0,   57,   29,    0,    1,    0,    0,
    0,  150,    0,    0,  162,    0,    0,   87,  117,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,    0,   18,   23,    0,    0,    0,    0,   38,    0,
    0,  -39,   98,  955,  960,  856,  881,  892,  919,  813,
  845,  156,  259,  285,    0,  126,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  136,
    0,   39,    0,    0,    0,  137,  145,    0,    0,    0,
    0,    0,    0,    0,    0,  758,  758,    0, 1257,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1279,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  209,  -78,  850,    0,    0,  166,   27,    0,   93,   72,
    0,    0,    0, 1547,  -96,    0, -105,  170,    0,    0,
  774,    0,
};
#define YYTABLESIZE 1745
static const YYINT yytable[] = {                        117,
   21,   87,   93,   93,   87,   18,   93,   93,   93,   93,
   93,  129,   93,  141,   15,  139,  142,   19,   87,   87,
  144,   21,   16,   93,   93,   93,   93,   93,   93,   84,
   31,   84,    7,   38,   82,   80,   82,   81,    7,   83,
  182,   83,  161,   41,   23,   42,   43,  180,   45,  183,
   86,   30,   87,   87,   37,  155,   93,   25,   93,    7,
   46,   90,  176,  177,   40,   30,   30,   24,   26,   30,
   30,   30,   30,   30,   27,   30,    7,   90,   68,   69,
   28,   68,   69,   85,   87,   85,   30,   30,   30,   93,
   30,   21,   36,   84,   84,   29,   18,   84,   84,   84,
   84,   84,   57,   84,   86,   39,   87,   61,   19,   63,
   64,   58,   66,   16,   84,   84,   84,  181,   84,   30,
   86,   30,   87,   71,   71,   59,   60,   71,   71,   71,
   71,   71,  149,   71,  150,   86,   67,   88,   86,   89,
   93,   86,   90,   94,   71,   71,   71,   84,   71,   84,
   95,   30,   30,   70,   70,   86,   86,   70,   70,   70,
   70,   70,   96,   70,   85,  151,   85,  145,  146,   85,
  160,  166,  167,  168,   70,   70,   70,  169,   70,   71,
   84,  170,  187,   85,   85,   30,    2,   37,    1,   35,
   86,   40,   74,   74,   12,   10,   74,   74,   74,   74,
   74,   34,   74,   11,   15,    1,    2,   16,   13,   70,
   71,    1,    2,   74,   74,   74,    6,   74,   85,   22,
   14,   86,    6,   87,   92,  204,  156,   91,   93,    0,
    0,    0,    1,    2,   18,    0,   87,    0,    0,    0,
   70,   93,    0,    6,   93,   93,   93,   93,   74,    1,
    2,    3,    4,    5,    0,    0,    0,    0,  118,    0,
    6,    0,  138,  140,   21,   21,   21,   21,   21,   18,
   18,   18,   18,   18,    0,   21,    0,    0,    0,   74,
   18,   19,   19,   19,   19,   19,   16,   16,   16,   16,
   16,   30,   19,    0,    0,   75,   75,   16,    0,   75,
   75,   75,   75,   75,   30,   75,    0,   30,   30,   30,
   30,    0,    0,  163,    0,    0,   75,   75,   75,   84,
   75,   76,   76,    0,    0,   76,   76,   76,   76,   76,
  172,   76,   84,    0,    0,   84,   84,   84,   84,    0,
    0,    0,   76,   76,   76,    0,   76,    0,    0,   71,
    0,   75,    0,   84,   73,    0,    0,    0,   82,   80,
   86,   81,   71,   83,    0,   71,   71,   71,   71,    0,
    0,    0,    0,   86,    0,  159,   76,   76,   77,   70,
    0,    0,   75,    0,    0,    0,    0,    0,   85,    0,
    0,    0,   70,    0,   84,   70,   70,   70,   70,   82,
   80,   85,   81,    0,   83,   84,   73,   85,   76,  195,
   82,   80,    0,   81,    0,   83,    0,   76,   74,   77,
    0,    0,    0,    0,    0,    0,  196,    0,   76,    0,
   77,   74,    0,    0,   74,   74,   74,   74,    0,    0,
   72,   84,   73,    0,    0,  197,   82,   80,   85,   81,
    0,   83,    0,    0,    0,   84,   73,    0,    0,   85,
   82,   80,  198,   81,   76,   83,   77,    0,    0,    0,
    0,   84,   73,    0,    0,  101,   82,   80,   76,   81,
   77,   83,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   72,    0,   76,   85,   77,   84,   73,    0,
    0,    0,   82,   80,    0,   81,    0,   83,    0,   85,
    0,  100,    0,    0,    0,    0,    0,    0,    0,    0,
   76,   75,   77,    0,    0,   85,    0,    0,   72,    0,
    0,    0,    0,    0,   75,    0,    0,   75,   75,   75,
   75,    0,   72,   50,   97,    0,   47,   76,   48,    0,
    0,   85,    0,  143,    0,    0,    0,    0,   72,    0,
   76,    0,    0,   76,   76,   76,   76,   51,   84,   73,
    0,    0,  173,   82,   80,    0,   81,    0,   83,  157,
    0,    0,    0,    0,   72,    0,    0,    0,    0,    0,
    0,   76,  158,   77,   49,   74,   75,   78,   79,    0,
   84,   73,    0,    0,  174,   82,   80,    0,   81,    0,
   83,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   85,   76,    0,   77,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   84,   73,    0,   78,   79,
   82,   80,    0,   81,    0,   83,    0,   74,   75,   78,
   79,    0,    0,    0,   85,   72,  189,    0,   76,    0,
   77,    0,    0,    0,    0,    0,    0,   84,   73,    0,
    0,    0,   82,   80,    0,   81,    0,   83,    0,    0,
    0,    0,    0,   74,   75,   78,   79,   72,  190,   85,
   76,    0,   77,    0,    0,    0,    0,   74,   75,   78,
   79,   84,   73,    0,    0,  194,   82,   80,    0,   81,
    0,   83,    0,   74,   75,   78,   79,    0,    0,    0,
    0,   85,   72,    0,   76,    0,   77,   84,   73,    0,
    0,  205,   82,   80,    0,   81,    0,   83,    0,   74,
   75,   78,   79,   84,   73,    0,    0,  206,   82,   80,
   76,   81,   77,   83,   72,   85,    0,    0,    0,    0,
   42,   43,   44,   45,   84,   73,   76,    0,   77,   82,
   80,    0,   81,   14,   83,   46,    0,   17,   19,    0,
   20,   85,    0,    0,   14,    0,    0,   76,   72,   77,
    0,    0,    0,    0,   84,   84,    0,   85,    0,   84,
   84,    0,   84,    0,   84,    0,    0,    0,    0,    0,
   74,   75,   78,   79,   72,   84,   73,   84,   85,   84,
   82,   80,    0,   81,    0,   83,    0,    0,    0,   84,
   72,    0,    0,    0,   82,   80,    0,   81,   76,   83,
   77,    0,   74,   75,   78,   79,    0,    0,   84,    0,
   72,   72,   76,   72,   77,   72,   72,   72,    0,    0,
    0,    0,    0,  137,    0,    0,    0,    0,    0,   85,
   72,   72,   72,    0,   72,    0,    0,   74,   75,   78,
   79,   84,   73,   85,    0,   73,    0,   73,   73,   73,
    0,    0,    0,   77,  147,  148,   77,    0,    0,   77,
   20,    0,   73,   73,   73,   72,   73,  137,    0,   74,
   75,   78,   79,   77,   77,   77,    0,   77,   78,    0,
    0,   78,    0,    0,   78,    0,    0,    0,    0,   80,
    0,    0,   80,    0,    0,   80,   72,   73,   78,   78,
   78,    0,   78,   74,   75,   78,   79,    0,   77,   80,
   80,   80,    0,   80,    0,    0,   79,    0,    0,   79,
    0,    0,   79,    0,    0,    0,    0,    0,   73,   74,
   75,   78,   79,   78,    0,    0,   79,   79,   79,   77,
   79,    0,  153,    0,   80,   74,   75,   78,   79,    0,
    0,    0,   82,    0,    0,   82,    0,   81,   82,    0,
   81,    0,    0,   81,   78,  153,   74,   75,   78,   79,
    0,   79,   82,   82,    0,   80,    0,   81,   81,    0,
    0,    0,  178,  179,    0,   50,    0,    0,   47,    0,
   48,    0,  188,    0,    0,    0,   84,   84,   84,   84,
    0,    0,   79,  199,  200,   50,  202,   82,   47,   51,
   48,    0,   81,    0,  207,  208,    0,   74,   75,   78,
   79,    0,    0,    0,    0,   50,    0,    0,   47,   51,
   48,   74,   75,   78,   79,   72,  127,    0,   82,    0,
    0,    0,    0,   81,    0,    0,    0,    0,   72,   51,
    0,   72,   72,   72,   72,   50,  127,    0,   47,    0,
   48,    0,    0,    0,    0,    0,    0,   73,   90,    0,
  128,    0,    0,    0,    0,    0,  127,    0,   77,   51,
   73,    0,    0,   73,   73,   73,   73,    0,   90,    0,
  154,   77,    0,    0,   77,   77,   77,   77,    0,    0,
    0,    0,   50,   78,    0,   47,   49,   48,    0,    0,
    0,    0,    0,    0,   80,    0,   78,    0,    0,   78,
   78,   78,   78,    0,    0,    0,   51,   80,    0,    0,
   80,   80,   80,   80,    0,    0,    0,    0,   90,    0,
  152,   79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   49,   79,    0,    0,   79,   79,   79,
   79,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   82,    0,    0,
    0,    0,   81,    0,    0,   90,    0,  171,    0,    0,
   82,    0,    0,   82,   82,   81,    0,    0,   81,   81,
    0,    0,   42,   43,   44,   45,  119,  120,    0,    1,
    2,    0,  121,  122,    0,  123,  124,   46,  125,  126,
    6,    0,   42,   43,   44,   45,  119,  120,    0,    1,
    2,    0,  121,  122,    0,  123,  124,   46,  125,  126,
    6,    0,   42,   43,   44,   45,    0,    0,    0,    1,
    2,    0,    0,    0,    0,    0,   58,   46,    0,   58,
    6,   58,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   42,   43,   44,   45,  119,  120,   62,    0,
   58,   62,    0,   62,    0,  123,  124,   46,  125,  126,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   50,   62,    0,   47,    0,   48,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   42,
   43,   44,   45,  119,  120,   51,    0,    0,    0,   62,
    0,    0,  123,  124,   46,  125,  126,    0,    0,   58,
   50,   58,    0,   47,    0,   48,    0,    0,    0,    0,
    0,    0,   49,    0,    0,    0,    0,    0,    0,    0,
    0,   62,    0,   62,   51,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   90,    0,    0,    0,    0,    0,
    0,   49,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   58,   58,   58,   58,   58,   58,    0,
    0,    0,    0,    0,    0,    0,   58,   58,   58,   58,
   58,    0,    0,    0,    0,   62,   62,   62,   62,   62,
   62,    0,    0,    0,    0,    0,    0,    0,   62,   62,
   62,   62,   62,    0,    0,    0,    0,    0,   42,   43,
   44,   45,  119,  120,    0,    0,    0,    0,    0,    0,
    0,  123,  124,   46,  125,  126,   52,    0,    0,    0,
    0,    0,    0,   62,    0,    0,   65,    0,    0,    0,
    0,    0,    0,   68,   69,   70,   71,   42,   43,   44,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   46,   99,    0,    0,    0,    0,  102,  103,
  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,
  114,  115,  116,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   70,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  162,    0,
    0,  164,  165,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  175,  175,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  185,  186,    0,    0,
    0,    0,    0,  191,    0,  192,  193,    0,    0,    0,
    0,    0,  201,    0,  203,
};
static const YYINT yycheck[] = {                         61,
    0,   41,   37,   38,   44,    0,   41,   42,   43,   44,
   45,   90,   47,   41,  259,   61,   44,    0,   58,   59,
  117,   59,    0,   58,   59,   60,   61,   62,   63,   37,
   40,   37,   91,   40,   42,   43,   42,   45,   91,   47,
  269,   47,  139,   40,  259,  257,  258,   58,  260,  278,
   61,   61,   63,   93,   61,  134,   91,  259,   93,   91,
  272,  123,  168,  169,   61,   37,   38,   40,  259,   41,
   42,   43,   44,   45,  259,   47,   91,  123,   41,   41,
  259,   44,   44,   91,  124,   91,   58,   59,   60,  124,
   62,   91,   40,   37,   38,   93,   91,   41,   42,   43,
   44,   45,   31,   47,   61,   40,   63,   36,   91,   38,
   39,   41,   41,   91,   58,   59,   60,   58,   62,   91,
   61,   93,   63,   37,   38,   44,  259,   41,   42,   43,
   44,   45,   43,   47,   45,   38,   40,  260,   41,   41,
   41,   44,  123,   41,   58,   59,   60,   91,   62,   93,
   41,  123,  124,   37,   38,   58,   59,   41,   42,   43,
   44,   45,   41,   47,   91,   59,   41,   40,   40,   44,
  259,  259,  259,   40,   58,   59,   60,   40,   62,   93,
  124,   59,   40,   58,   59,   61,    0,   61,    0,   41,
   93,   61,   37,   38,   59,   59,   41,   42,   43,   44,
   45,   41,   47,   59,   59,  264,  265,  266,   59,   93,
  124,  264,  265,   58,   59,   60,  275,   62,   93,   11,
   59,  124,  275,  263,   59,  199,  134,   58,  263,   -1,
   -1,   -1,  264,  265,  266,   -1,  276,   -1,   -1,   -1,
  124,  276,   -1,  275,  279,  280,  281,  282,   93,  264,
  265,  266,  267,  268,   -1,   -1,   -1,   -1,   89,   -1,
  275,   -1,   93,   94,  264,  265,  266,  267,  268,  264,
  265,  266,  267,  268,   -1,  275,   -1,   -1,   -1,  124,
  275,  264,  265,  266,  267,  268,  264,  265,  266,  267,
  268,  263,  275,   -1,   -1,   37,   38,  275,   -1,   41,
   42,   43,   44,   45,  276,   47,   -1,  279,  280,  281,
  282,   -1,   -1,  144,   -1,   -1,   58,   59,   60,  263,
   62,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
  161,   47,  276,   -1,   -1,  279,  280,  281,  282,   -1,
   -1,   -1,   58,   59,   60,   -1,   62,   -1,   -1,  263,
   -1,   93,   -1,   37,   38,   -1,   -1,   -1,   42,   43,
  263,   45,  276,   47,   -1,  279,  280,  281,  282,   -1,
   -1,   -1,   -1,  276,   -1,   59,   60,   93,   62,  263,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,  263,   -1,
   -1,   -1,  276,   -1,   37,  279,  280,  281,  282,   42,
   43,  276,   45,   -1,   47,   37,   38,   91,  124,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   60,  263,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,   -1,
   62,  276,   -1,   -1,  279,  280,  281,  282,   -1,   -1,
  124,   37,   38,   -1,   -1,   41,   42,   43,   91,   45,
   -1,   47,   -1,   -1,   -1,   37,   38,   -1,   -1,   91,
   42,   43,   58,   45,   60,   47,   62,   -1,   -1,   -1,
   -1,   37,   38,   -1,   -1,   41,   42,   43,   60,   45,
   62,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   60,   91,   62,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   91,
   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   60,  263,   62,   -1,   -1,   91,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,  276,   -1,   -1,  279,  280,  281,
  282,   -1,  124,   40,   41,   -1,   43,  263,   45,   -1,
   -1,   91,   -1,   93,   -1,   -1,   -1,   -1,  124,   -1,
  276,   -1,   -1,  279,  280,  281,  282,   64,   37,   38,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,  263,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   60,  276,   62,   91,  279,  280,  281,  282,   -1,
   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   91,   60,   -1,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,  281,  282,
   42,   43,   -1,   45,   -1,   47,   -1,  279,  280,  281,
  282,   -1,   -1,   -1,   91,  124,   58,   -1,   60,   -1,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,  279,  280,  281,  282,  124,   58,   91,
   60,   -1,   62,   -1,   -1,   -1,   -1,  279,  280,  281,
  282,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,  279,  280,  281,  282,   -1,   -1,   -1,
   -1,   91,  124,   -1,   60,   -1,   62,   37,   38,   -1,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,  279,
  280,  281,  282,   37,   38,   -1,   -1,   41,   42,   43,
   60,   45,   62,   47,  124,   91,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,   37,   38,   60,   -1,   62,   42,
   43,   -1,   45,    0,   47,  272,   -1,    4,    5,   -1,
    7,   91,   -1,   -1,   11,   -1,   -1,   60,  124,   62,
   -1,   -1,   -1,   -1,   37,   38,   -1,   91,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
  279,  280,  281,  282,  124,   37,   38,   60,   91,   62,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   37,
  124,   -1,   -1,   -1,   42,   43,   -1,   45,   60,   47,
   62,   -1,  279,  280,  281,  282,   -1,   -1,   91,   -1,
   38,  124,   60,   41,   62,   43,   44,   45,   -1,   -1,
   -1,   -1,   -1,   90,   -1,   -1,   -1,   -1,   -1,   91,
   58,   59,   60,   -1,   62,   -1,   -1,  279,  280,  281,
  282,  124,   38,   91,   -1,   41,   -1,   43,   44,   45,
   -1,   -1,   -1,   38,  121,  122,   41,   -1,   -1,   44,
  127,   -1,   58,   59,   60,   93,   62,  134,   -1,  279,
  280,  281,  282,   58,   59,   60,   -1,   62,   38,   -1,
   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,  124,   93,   58,   59,
   60,   -1,   62,  279,  280,  281,  282,   -1,   93,   58,
   59,   60,   -1,   62,   -1,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,  124,  279,
  280,  281,  282,   93,   -1,   -1,   58,   59,   60,  124,
   62,   -1,  133,   -1,   93,  279,  280,  281,  282,   -1,
   -1,   -1,   38,   -1,   -1,   41,   -1,   38,   44,   -1,
   41,   -1,   -1,   44,  124,  156,  279,  280,  281,  282,
   -1,   93,   58,   59,   -1,  124,   -1,   58,   59,   -1,
   -1,   -1,  173,  174,   -1,   40,   -1,   -1,   43,   -1,
   45,   -1,  183,   -1,   -1,   -1,  279,  280,  281,  282,
   -1,   -1,  124,  194,  195,   40,  197,   93,   43,   64,
   45,   -1,   93,   -1,  205,  206,   -1,  279,  280,  281,
  282,   -1,   -1,   -1,   -1,   40,   -1,   -1,   43,   64,
   45,  279,  280,  281,  282,  263,   91,   -1,  124,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,  276,   64,
   -1,  279,  280,  281,  282,   40,   91,   -1,   43,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,  263,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   91,   -1,  263,   64,
  276,   -1,   -1,  279,  280,  281,  282,   -1,  123,   -1,
  125,  276,   -1,   -1,  279,  280,  281,  282,   -1,   -1,
   -1,   -1,   40,  263,   -1,   43,   91,   45,   -1,   -1,
   -1,   -1,   -1,   -1,  263,   -1,  276,   -1,   -1,  279,
  280,  281,  282,   -1,   -1,   -1,   64,  276,   -1,   -1,
  279,  280,  281,  282,   -1,   -1,   -1,   -1,  123,   -1,
  125,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   91,  276,   -1,   -1,  279,  280,  281,
  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,
   -1,   -1,  263,   -1,   -1,  123,   -1,  125,   -1,   -1,
  276,   -1,   -1,  279,  280,  276,   -1,   -1,  279,  280,
   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,  264,
  265,   -1,  267,  268,   -1,  270,  271,  272,  273,  274,
  275,   -1,  257,  258,  259,  260,  261,  262,   -1,  264,
  265,   -1,  267,  268,   -1,  270,  271,  272,  273,  274,
  275,   -1,  257,  258,  259,  260,   -1,   -1,   -1,  264,
  265,   -1,   -1,   -1,   -1,   -1,   40,  272,   -1,   43,
  275,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,   40,   -1,
   64,   43,   -1,   45,   -1,  270,  271,  272,  273,  274,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   64,   -1,   43,   -1,   45,   91,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,   64,   -1,   -1,   -1,   91,
   -1,   -1,  270,  271,  272,  273,  274,   -1,   -1,  123,
   40,  125,   -1,   43,   -1,   45,   -1,   -1,   -1,   -1,
   -1,   -1,   91,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   64,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,   -1,
   -1,   91,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,  273,
  274,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,
  272,  273,  274,   -1,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,   30,   -1,   -1,   -1,
   -1,   -1,   -1,   37,   -1,   -1,   40,   -1,   -1,   -1,
   -1,   -1,   -1,   47,   48,   49,   50,  257,  258,  259,
  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,   67,   -1,   -1,   -1,   -1,   72,   73,
   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   86,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  127,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  142,   -1,
   -1,  145,  146,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  168,  169,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  180,  181,   -1,   -1,
   -1,   -1,   -1,  187,   -1,  189,  190,   -1,   -1,   -1,
   -1,   -1,  196,   -1,  198,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 308
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,"':'","';'","'<'","'='","'>'","'?'","'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER","tDOUBLE",
"tIDENTIFIER","tSTRING","tWHILE","tIF","tPRINT","tINT","tREAL","tPROCEDURE",
"tPUBLIC","tUSED","tELSIF","tSWEEP","tNEXT","tNULL","tSTOP","tRETURN","tSTR",
"tPRINTLN","tIFX","tELSE","tEQ","tNE","tLE","tGE","tUNARY",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : decls",
"file :",
"decls : decl",
"decls : decls decl",
"decl : vardecl ';'",
"decl : funcdecl",
"decl : funcdef",
"vardecls : vardecl ';'",
"vardecls : vardecls vardecl ';'",
"vardecl : tPUBLIC type tIDENTIFIER",
"vardecl : tUSED type tIDENTIFIER",
"vardecl : type tIDENTIFIER",
"vardecl : tPUBLIC type tIDENTIFIER '=' expr",
"vardecl : tUSED type tIDENTIFIER '=' expr",
"vardecl : type tIDENTIFIER '=' expr",
"funcdecl : tPUBLIC type tIDENTIFIER '(' fargs ')'",
"funcdecl : tUSED type tIDENTIFIER '(' fargs ')'",
"funcdecl : type tIDENTIFIER '(' fargs ')'",
"funcdecl : tPUBLIC tPROCEDURE tIDENTIFIER '(' fargs ')'",
"funcdecl : tUSED tPROCEDURE tIDENTIFIER '(' fargs ')'",
"funcdecl : tPROCEDURE tIDENTIFIER '(' fargs ')'",
"funcdef : tPUBLIC type tIDENTIFIER '(' fargs ')' block",
"funcdef : type tIDENTIFIER '(' fargs ')' block",
"funcdef : tPUBLIC type tIDENTIFIER '(' fargs ')' '=' literal block",
"funcdef : type tIDENTIFIER '(' fargs ')' '=' literal block",
"funcdef : tPUBLIC tPROCEDURE tIDENTIFIER '(' fargs ')' block",
"funcdef : tPROCEDURE tIDENTIFIER '(' fargs ')' block",
"literal : tINTEGER",
"literal : tDOUBLE",
"literal : string",
"literal : tNULL",
"string : tSTRING",
"string : string tSTRING",
"fargs : args",
"fargs :",
"args : arg",
"args : args ',' arg",
"arg : type tIDENTIFIER",
"type : tINT",
"type : tREAL",
"type : tSTR",
"type : '[' type ']'",
"block : '{' vardecls instrs '}'",
"block : '{' vardecls '}'",
"block : '{' instrs '}'",
"block : '{' '}'",
"instrs : instr",
"instrs : instrs instr",
"instr : expr ';'",
"instr : expr tPRINT",
"instr : expr tPRINTLN",
"instr : tSTOP",
"instr : tNEXT",
"instr : tRETURN",
"instr : cond",
"instr : iter",
"instr : block",
"cond : tIF '(' expr ')' instr",
"cond : tIF '(' expr ')' instr else",
"else : tELSIF '(' expr ')' instr else",
"else : tELSE instr",
"else : tELSIF '(' expr ')' instr",
"iter : tWHILE '(' expr ')' instr",
"iter : tSWEEP '+' '(' lval ':' expr ':' expr ')' instr",
"iter : tSWEEP '+' '(' lval ':' expr ':' expr ':' expr ')' instr",
"iter : tSWEEP '-' '(' lval ':' expr ':' expr ')' instr",
"iter : tSWEEP '-' '(' lval ':' expr ':' expr ':' expr ')' instr",
"exprs : expr",
"exprs : exprs ',' expr",
"expr : '-' expr",
"expr : '+' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : '(' expr ')'",
"expr : lval",
"expr : lval '=' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '@'",
"expr : funcall",
"expr : '[' expr ']'",
"expr : lval '?'",
"expr : literal",
"lval : tIDENTIFIER",
"lval : expr '[' expr ']'",
"funcall : tIDENTIFIER '(' exprs ')'",
"funcall : tIDENTIFIER '(' ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 67 "xpl_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 68 "xpl_parser.y"
	{ compiler->ast(new cdk::nil_node(LINE)); }
break;
case 3:
#line 71 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 4:
#line 72 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 5:
#line 76 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 77 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].fdecl; }
break;
case 7:
#line 78 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].fdef; }
break;
case 8:
#line 81 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-1].node); }
break;
case 9:
#line 82 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-1].node, yystack.l_mark[-2].sequence); }
break;
case 10:
#line 85 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, true, false, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL); }
break;
case 11:
#line 86 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, false, true, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL); }
break;
case 12:
#line 87 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, false, false, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL); }
break;
case 13:
#line 88 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, true, false, yystack.l_mark[-3].t, yystack.l_mark[-2].s, yystack.l_mark[0].expression); }
break;
case 14:
#line 89 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, false, true, yystack.l_mark[-3].t, yystack.l_mark[-2].s, yystack.l_mark[0].expression); }
break;
case 15:
#line 90 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, false, false, yystack.l_mark[-3].t, yystack.l_mark[-2].s, yystack.l_mark[0].expression); }
break;
case 16:
#line 94 "xpl_parser.y"
	{ yyval.fdecl = new xpl::function_declaration_node(LINE, true, false, yystack.l_mark[-4].t, *yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, NULL); }
break;
case 17:
#line 95 "xpl_parser.y"
	{ yyval.fdecl = new xpl::function_declaration_node(LINE, false, true, yystack.l_mark[-4].t, *yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, NULL); }
break;
case 18:
#line 96 "xpl_parser.y"
	{ yyval.fdecl = new xpl::function_declaration_node(LINE, false, false, yystack.l_mark[-4].t, *yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, NULL); }
break;
case 19:
#line 98 "xpl_parser.y"
	{ yyval.fdecl = new xpl::function_declaration_node(LINE, true, false, new basic_type(4, basic_type::TYPE_VOID), *yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, NULL); }
break;
case 20:
#line 99 "xpl_parser.y"
	{ yyval.fdecl = new xpl::function_declaration_node(LINE, false, true, new basic_type(4, basic_type::TYPE_VOID), *yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, NULL); }
break;
case 21:
#line 100 "xpl_parser.y"
	{ yyval.fdecl = new xpl::function_declaration_node(LINE, false, false, new basic_type(4, basic_type::TYPE_VOID), *yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, NULL); }
break;
case 22:
#line 103 "xpl_parser.y"
	{ yyval.fdef = new xpl::function_definition_node(LINE, true, yystack.l_mark[-5].t, *yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].b); }
break;
case 23:
#line 104 "xpl_parser.y"
	{ yyval.fdef = new xpl::function_definition_node(LINE, false, yystack.l_mark[-5].t, *yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].b); }
break;
case 24:
#line 105 "xpl_parser.y"
	{ yyval.fdef = new xpl::function_definition_node(LINE, true, yystack.l_mark[-7].t, *yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].b); }
break;
case 25:
#line 106 "xpl_parser.y"
	{ yyval.fdef = new xpl::function_definition_node(LINE, false, yystack.l_mark[-7].t, *yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].b); }
break;
case 26:
#line 108 "xpl_parser.y"
	{ yyval.fdef = new xpl::function_definition_node(LINE, true, new basic_type(4, basic_type::TYPE_VOID), *yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].b); }
break;
case 27:
#line 109 "xpl_parser.y"
	{ yyval.fdef = new xpl::function_definition_node(LINE, false, new basic_type(4, basic_type::TYPE_VOID), *yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].b); }
break;
case 28:
#line 112 "xpl_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 29:
#line 113 "xpl_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 30:
#line 114 "xpl_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 31:
#line 115 "xpl_parser.y"
	{ yyval.expression = new xpl::null_node(LINE); }
break;
case 32:
#line 118 "xpl_parser.y"
	{ yyval.s = yystack.l_mark[0].s; }
break;
case 33:
#line 119 "xpl_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[-1].s + *yystack.l_mark[0].s); delete yystack.l_mark[-1].s; delete yystack.l_mark[0].s; }
break;
case 34:
#line 122 "xpl_parser.y"
	{ yyval.sequence = yystack.l_mark[0].sequence; }
break;
case 35:
#line 123 "xpl_parser.y"
	{ yyval.sequence = NULL; }
break;
case 36:
#line 126 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 37:
#line 127 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-2].sequence); }
break;
case 38:
#line 130 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE, false, false, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL); }
break;
case 39:
#line 133 "xpl_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_INT); }
break;
case 40:
#line 134 "xpl_parser.y"
	{ yyval.t = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 41:
#line 135 "xpl_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 42:
#line 136 "xpl_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_POINTER); yyval.t->_subtype = yystack.l_mark[-1].t; }
break;
case 43:
#line 139 "xpl_parser.y"
	{ yyval.b = new xpl::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 44:
#line 140 "xpl_parser.y"
	{ yyval.b = new xpl::block_node(LINE, yystack.l_mark[-1].sequence, NULL); }
break;
case 45:
#line 141 "xpl_parser.y"
	{ yyval.b = new xpl::block_node(LINE, NULL, yystack.l_mark[-1].sequence); }
break;
case 46:
#line 142 "xpl_parser.y"
	{ yyval.b = new xpl::block_node(LINE, NULL, NULL); }
break;
case 47:
#line 145 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 48:
#line 146 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 49:
#line 149 "xpl_parser.y"
	{ yyval.node = new xpl::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 50:
#line 150 "xpl_parser.y"
	{ yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression, false); }
break;
case 51:
#line 151 "xpl_parser.y"
	{ yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression, true); }
break;
case 52:
#line 152 "xpl_parser.y"
	{ yyval.node = new xpl::stop_node(LINE); }
break;
case 53:
#line 153 "xpl_parser.y"
	{ yyval.node = new xpl::next_node(LINE); }
break;
case 54:
#line 154 "xpl_parser.y"
	{ yyval.node = new xpl::return_node(LINE); }
break;
case 55:
#line 155 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 56:
#line 156 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 57:
#line 157 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].b; }
break;
case 58:
#line 160 "xpl_parser.y"
	{ yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 59:
#line 161 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 60:
#line 164 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 61:
#line 165 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 62:
#line 166 "xpl_parser.y"
	{ yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 63:
#line 169 "xpl_parser.y"
	{ yyval.node = new xpl::while_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 64:
#line 170 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_plus_node(LINE, yystack.l_mark[-6].lvalue, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, NULL, yystack.l_mark[0].node); }
break;
case 65:
#line 171 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_plus_node(LINE, yystack.l_mark[-8].lvalue, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 66:
#line 172 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_minus_node(LINE, yystack.l_mark[-6].lvalue, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, NULL, yystack.l_mark[0].node); }
break;
case 67:
#line 173 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_minus_node(LINE, yystack.l_mark[-8].lvalue, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 68:
#line 197 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 69:
#line 198 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 70:
#line 201 "xpl_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 71:
#line 202 "xpl_parser.y"
	{ yyval.expression = new xpl::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 72:
#line 203 "xpl_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 73:
#line 204 "xpl_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 74:
#line 205 "xpl_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 75:
#line 206 "xpl_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 76:
#line 207 "xpl_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 77:
#line 208 "xpl_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 78:
#line 209 "xpl_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 79:
#line 210 "xpl_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 80:
#line 211 "xpl_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 81:
#line 212 "xpl_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 82:
#line 213 "xpl_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 83:
#line 214 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 84:
#line 215 "xpl_parser.y"
	{ yyval.expression = new cdk::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 85:
#line 216 "xpl_parser.y"
	{ yyval.expression = new cdk::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 86:
#line 217 "xpl_parser.y"
	{ yyval.expression = new cdk::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 87:
#line 218 "xpl_parser.y"
	{ yyval.expression = new cdk::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 88:
#line 219 "xpl_parser.y"
	{ yyval.expression = new xpl::read_node(LINE); }
break;
case 89:
#line 220 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 90:
#line 221 "xpl_parser.y"
	{ yyval.expression = new xpl::memory_allocate_node(LINE, yystack.l_mark[-1].expression); }
break;
case 91:
#line 222 "xpl_parser.y"
	{ yyval.expression = new xpl::memory_address_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 92:
#line 223 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 93:
#line 226 "xpl_parser.y"
	{ yyval.lvalue = new cdk::identifier_node(LINE, yystack.l_mark[0].s); }
break;
case 94:
#line 227 "xpl_parser.y"
	{ yyval.lvalue = new xpl::index_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].expression); }
break;
case 95:
#line 230 "xpl_parser.y"
	{ yyval.expression = new xpl::function_call_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 96:
#line 231 "xpl_parser.y"
	{ yyval.expression = new xpl::function_call_node(LINE, yystack.l_mark[-2].s, NULL); }
break;
#line 1320 "xpl_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
