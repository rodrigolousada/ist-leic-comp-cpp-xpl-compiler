%{
// $Id: xpl_parser.y,v 1.8 2017/05/22 15:31:54 ist181115 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
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

};

%token <i> tINTEGER
%token <d> tDOUBLE
%token <s> tIDENTIFIER tSTRING
%token tWHILE tIF tPRINT
%token tINT tREAL tSTRING tPROCEDURE tPUBLIC tUSED tELSIF tSWEEP tNEXT tNULL tSTOP tRETURN tSTR tPRINT tPRINTLN tNULL

%nonassoc tIFX
%nonassoc tELSIF
%nonassoc tELSE

%right '='
%left '|'
%left '&' 
%nonassoc '~'
%left tEQ tNE
%left '<' '>' tLE tGE 
%left '+' '-'
%left '*' '/' '%'  
%nonassoc tUNARY
%nonassoc '['

%type <node> file decl vardecl instr cond iter arg else
%type <sequence> decls instrs fargs args exprs vardecls
%type <expression> expr literal funcall
%type <lvalue> lval
%type <b> block
%type <fdecl> funcdecl
%type <fdef> funcdef
%type <t> type;
%type <s> string;

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%


file    : decls         { compiler->ast($1); }
        |               { compiler->ast(new cdk::nil_node(LINE)); }
        ;
        
decls   : decl          { $$ = new cdk::sequence_node(LINE, $1); }
        | decls decl    { $$ = new cdk::sequence_node(LINE, $2, $1); }
        ;
        

decl    : vardecl ';'       { $$ = $1; }
        | funcdecl          { $$ = $1; }
        | funcdef           { $$ = $1; }
        ;
        
vardecls   : vardecl ';'              { $$ = new cdk::sequence_node(LINE, $1); }
           | vardecls vardecl ';'    { $$ = new cdk::sequence_node(LINE, $2, $1); }
           ;

vardecl    : tPUBLIC type tIDENTIFIER                           { $$ = new xpl::variable_declaration_node(LINE, true, false, $2, $3, NULL); }
           | tUSED type tIDENTIFIER                             { $$ = new xpl::variable_declaration_node(LINE, false, true, $2, $3, NULL); }
           | type tIDENTIFIER                                   { $$ = new xpl::variable_declaration_node(LINE, false, false, $1, $2, NULL); }
           | tPUBLIC type tIDENTIFIER '=' expr                  { $$ = new xpl::variable_declaration_node(LINE, true, false, $2, $3, $5); }
           | tUSED type tIDENTIFIER '=' expr                    { $$ = new xpl::variable_declaration_node(LINE, false, true, $2, $3, $5); }
           | type tIDENTIFIER '=' expr                          { $$ = new xpl::variable_declaration_node(LINE, false, false, $1, $2, $4); }
           ;
             

funcdecl   : tPUBLIC type tIDENTIFIER '(' fargs ')'                         { $$ = new xpl::function_declaration_node(LINE, true, false, $2, *$3, $5, NULL); }
           | tUSED type tIDENTIFIER '(' fargs ')'                           { $$ = new xpl::function_declaration_node(LINE, false, true, $2, *$3, $5, NULL); }
           | type tIDENTIFIER '(' fargs ')'                                 { $$ = new xpl::function_declaration_node(LINE, false, false, $1, *$2, $4, NULL); }
           
           | tPUBLIC tPROCEDURE tIDENTIFIER '(' fargs ')'                   { $$ = new xpl::function_declaration_node(LINE, true, false, new basic_type(4, basic_type::TYPE_VOID), *$3, $5, NULL); }
           | tUSED tPROCEDURE tIDENTIFIER '(' fargs ')'                     { $$ = new xpl::function_declaration_node(LINE, false, true, new basic_type(4, basic_type::TYPE_VOID), *$3, $5, NULL); }
           | tPROCEDURE tIDENTIFIER '(' fargs ')'                           { $$ = new xpl::function_declaration_node(LINE, false, false, new basic_type(4, basic_type::TYPE_VOID), *$2, $4, NULL); }
           ;
           
funcdef    : tPUBLIC type tIDENTIFIER '(' fargs ')' block                        { $$ = new xpl::function_definition_node(LINE, true, $2, *$3, $5, NULL, $7); }
           | type tIDENTIFIER '(' fargs ')' block                                { $$ = new xpl::function_definition_node(LINE, false, $1, *$2, $4, NULL, $6); }
           | tPUBLIC type tIDENTIFIER '(' fargs ')' '=' literal block            { $$ = new xpl::function_definition_node(LINE, true, $2, *$3, $5, $8, $9); }
           | type tIDENTIFIER '(' fargs ')' '=' literal block                    { $$ = new xpl::function_definition_node(LINE, false, $1, *$2, $4, $7, $8); }
           
           | tPUBLIC tPROCEDURE tIDENTIFIER '(' fargs ')' block                  { $$ = new xpl::function_definition_node(LINE, true, new basic_type(4, basic_type::TYPE_VOID), *$3, $5, NULL, $7); }
           | tPROCEDURE tIDENTIFIER '(' fargs ')' block                          { $$ = new xpl::function_definition_node(LINE, false, new basic_type(4, basic_type::TYPE_VOID), *$2, $4, NULL, $6); }
           ;

literal     : tINTEGER      { $$ = new cdk::integer_node(LINE, $1); }
            | tDOUBLE       { $$ = new cdk::double_node(LINE, $1); }
            | string        { $$ = new cdk::string_node(LINE, $1); }
            | tNULL         { $$ = new xpl::null_node(LINE); }
            ;
            
string      : tSTRING           { $$ = $1; }
            | string tSTRING    { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
            ;

fargs       : args      { $$ = $1; }
            |           { $$ = NULL; }
            ;
            
args        : arg               { $$ = new cdk::sequence_node(LINE, $1); }
            | args ',' arg      { $$ = new cdk::sequence_node(LINE, $3, $1); }
            ;
            
arg         : type tIDENTIFIER      { $$ = new xpl::variable_declaration_node(LINE, false, false, $1, $2, NULL); }
            ;
            
type        : tINT                  { $$ = new basic_type(4, basic_type::TYPE_INT); }
            | tREAL                 { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
            | tSTR                  { $$ = new basic_type(4, basic_type::TYPE_STRING); }
            | '[' type ']'          { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $2; }
            ;

block       : '{' vardecls instrs '}'   { $$ = new xpl::block_node(LINE, $2, $3); }
            | '{' vardecls '}'          { $$ = new xpl::block_node(LINE, $2, NULL); }
            | '{' instrs '}'         { $$ = new xpl::block_node(LINE, NULL, $2); }
            | '{' '}'                { $$ = new xpl::block_node(LINE, NULL, NULL); }
            ;
            
instrs  : instr         { $$ = new cdk::sequence_node(LINE, $1); }
        | instrs instr   { $$ = new cdk::sequence_node(LINE, $2, $1); }
        ;
        
instr   : expr ';'          { $$ = new xpl::evaluation_node(LINE, $1); }
        | expr tPRINT       { $$ = new xpl::print_node(LINE, $1, false); }
        | expr tPRINTLN     { $$ = new xpl::print_node(LINE, $1, true); }
        | tSTOP             { $$ = new xpl::stop_node(LINE); }
        | tNEXT             { $$ = new xpl::next_node(LINE); }
        | tRETURN           { $$ = new xpl::return_node(LINE); }
        | cond              { $$ = $1; }
        | iter              { $$ = $1; }
        | block             { $$ = $1; }
        ;
            
cond        : tIF '(' expr ')' instr %prec tIFX     { $$ = new xpl::if_node(LINE, $3, $5); }
            | tIF '(' expr ')' instr else           { $$ = new xpl::if_else_node(LINE, $3, $5, $6); }
            ;
        
else        : tELSIF '(' expr ')' instr else        { $$ = new xpl::if_else_node(LINE, $3, $5, $6); }
            | tELSE instr                           { $$ = $2; }
            | tELSIF '(' expr ')' instr %prec tIFX  { $$ = new xpl::if_node(LINE, $3, $5); }
            ;
            
iter        : tWHILE '(' expr ')' instr                                       { $$ = new xpl::while_node(LINE, $3, $5); }
            | tSWEEP '+' '(' lval ':' expr ':' expr ')' instr                { $$ = new xpl::sweep_plus_node(LINE, $4, $6, $8, NULL, $10); }
            | tSWEEP '+' '(' lval ':' expr ':' expr ':' expr ')' instr       { $$ = new xpl::sweep_plus_node(LINE, $4, $6, $8, $10, $12); }
            | tSWEEP '-' '(' lval ':' expr ':' expr ')' instr               { $$ = new xpl::sweep_minus_node(LINE, $4, $6, $8, NULL, $10); }
            | tSWEEP '-' '(' lval ':' expr ':' expr ':' expr ')' instr      { $$ = new xpl::sweep_minus_node(LINE, $4, $6, $8, $10, $12); }
            ;
/*
program	: list      { compiler->ast($1); }
        |           { compiler->ast(new cdk::nil_node(LINE)); }
        ;
        
list    : stmt	            { $$ = new cdk::sequence_node(LINE, $1); }
        | list stmt         { $$ = new cdk::sequence_node(LINE, $2, $1); }
        ;


        
stmt : expr ';'                         { $$ = new xpl::evaluation_node(LINE, $1); }
     | tPRINT expr ';'                  { $$ = new xpl::print_node(LINE, $2); }
     | tREAD lval ';'                   { $$ = new xpl::read_node(LINE, $2); }
     | tWHILE '(' expr ')' stmt         { $$ = new xpl::while_node(LINE, $3, $5); }
     | tIF '(' expr ')' stmt %prec tIFX { $$ = new xpl::if_node(LINE, $3, $5); }
     | tIF '(' expr ')' stmt tELSE stmt { $$ = new xpl::if_else_node(LINE, $3, $5, $7); }
     | '{' list '}'                     { $$ = $2; }
     ;
     
 */
     
exprs   : expr              { $$ = new cdk::sequence_node(LINE, $1); }
        | exprs ',' expr        { $$ = new cdk::sequence_node(LINE, $3, $1); }
        ;

expr : '-' expr %prec tUNARY     { $$ = new cdk::neg_node(LINE, $2); }
     | '+' expr %prec tUNARY     { $$ = new xpl::identity_node(LINE, $2); }
     | expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr             { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
     | '(' expr ')'              { $$ = $2; }
     | lval                      { $$ = new cdk::rvalue_node(LINE, $1); }
     | lval '=' expr             { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | expr '&' expr             { $$ = new cdk::and_node(LINE, $1, $3); }
     | expr '|' expr             { $$ = new cdk::or_node(LINE, $1, $3); }
     | '@'                       { $$ = new xpl::read_node(LINE); }
     | funcall                   { $$ = $1; }
     | '[' expr ']'              { $$ = new xpl::memory_allocate_node(LINE, $2); }
     | lval '?'                  { $$ = new xpl::memory_address_node(LINE, $1); }
     | literal                   { $$ = $1; }
     ;

lval : tIDENTIFIER                  { $$ = new cdk::identifier_node(LINE, $1); }
     | expr '[' expr ']'            { $$ = new xpl::index_node(LINE, $1, $3); }
     ;
     
funcall : tIDENTIFIER '(' exprs ')'	{ $$ = new xpl::function_call_node(LINE, $1, $3); }
        | tIDENTIFIER '(' ')'       	{ $$ = new xpl::function_call_node(LINE, $1, NULL); }
        ;

%%
