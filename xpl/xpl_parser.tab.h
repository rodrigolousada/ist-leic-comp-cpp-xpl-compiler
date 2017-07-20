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
extern YYSTYPE yylval;
