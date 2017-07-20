%option c++ yyclass="xpl_scanner" outfile="xpl_scanner.cpp"
%option stack noyywrap yylineno 8bit
%{ 
/* $Id: xpl_scanner.l,v 1.4 2017/05/10 13:48:09 ist181115 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "xpl_scanner.h"
#include "xpl_parser.tab.h"

// don't change this
#define yyerror LexerError
%}

HEXNUM			[0-9a-fA-F]

INTEGER_DEC		0|([1-9][0-9]*)
INTEGER_HEX		0[xX]{HEXNUM}+

NUMBER1                 ([0-9]+\.[0-9]*([eE][+-]?[0-9]+)?)
NUMBER2                 ([0-9]*\.[0-9]+([eE][+-]?[0-9]+)?)
NUMBER3                 ([0-9]+([eE][+-]?[0-9]+))

NUMBER                  {NUMBER1}|{NUMBER2}|{NUMBER3}

%x X_STRING X_COMMENT X_SPECIAL X_BLANK
%%
">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE; 

"while"                return tWHILE; 
"if"                   return tIF; 
"else"                 return tELSE; 
"print"                return tPRINT; 

"int"                  return tINT;
"real"                 return tREAL;
"string"               return tSTR;
"procedure"            return tPROCEDURE;
"public"               return tPUBLIC;
"use"                  return tUSED;
"elsif"                return tELSIF;
"sweep"                return tSWEEP; 
"next"                 return tNEXT;
"stop"                 return tSTOP;
"return"               return tRETURN;
"!"                    return tPRINT;
"!!"                   return tPRINTLN;
"null"                 return tNULL;

[A-Za-z_][A-Za-z0-9_]*        yylval.s = new std::string(yytext); return tIDENTIFIER;

\"                            yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"                  yy_pop_state(); return tSTRING;
<X_STRING>\\                  yy_push_state(X_SPECIAL);
<X_STRING>.                   *yylval.s += yytext;
<X_STRING>\n                  yyerror("newline in string");

<X_BLANK>\"                  yy_pop_state(); return tSTRING;
<X_BLANK>\\\"                ;
<X_BLANK>\\\\                ;
<X_BLANK>.                   ;
<X_BLANK>\n                  yyerror("newline in string");

<X_SPECIAL>0                        yy_pop_state(); yy_pop_state(); yy_push_state(X_BLANK);
<X_SPECIAL>n                        yy_pop_state(); *yylval.s += std::string(1,10);
<X_SPECIAL>r                        yy_pop_state(); *yylval.s += std::string(1,13); 
<X_SPECIAL>t                        yy_pop_state(); *yylval.s += std::string(1,9);
<X_SPECIAL>[\"\\]                   yy_pop_state(); *yylval.s += std::string(1,(int)*yytext);
<X_SPECIAL>[0-9a-fA-F][0-9a-fA-F]?  yy_pop_state(); *yylval.s += std::string(1,strtol(yytext, nullptr, 16));
<X_SPECIAL>.|\n                     yyerror("Invalid special character");

"/*"                          yy_push_state(X_COMMENT);
<X_COMMENT>"/*"               yy_push_state(X_COMMENT);
<X_COMMENT>"*/"               yy_pop_state();
<X_COMMENT>.|\n               ;

"//".*$                       ;

{INTEGER_DEC}		      { yylval.i = strtol(yytext, nullptr, 10); if(errno == ERANGE) yyerror("Invalid number range, overflow occurred"); return tINTEGER; }
{INTEGER_HEX}		      { yylval.i = strtol(yytext, nullptr, 16); if(errno == ERANGE) yyerror("Invalid number range, overflow occurred"); return tINTEGER; }
{NUMBER}	              { yylval.d = strtod(yytext, nullptr); if(errno == ERANGE) yyerror("Invalid number range, overflow occurred"); return tDOUBLE; }

[-\|()\[\]<>=+*/%:;{}&@!.,?]     return *yytext;

[ \t\n]+                      ; /* ignore whitespace */

.                             yyerror("Unknown character");

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int xpl_scanner::yywrap() { return 1; }
