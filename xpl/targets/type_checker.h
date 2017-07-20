// $Id: type_checker.h,v 1.3 2017/05/16 21:29:22 ist181115 Exp $ -*- c++ -*-
#ifndef __XPL_SEMANTICS_TYPE_CHECKER_H__
#define __XPL_SEMANTICS_TYPE_CHECKER_H__

#include <string>
#include <iostream>
#include <cdk/symbol_table.h>
#include <cdk/ast/basic_node.h>
#include "targets/symbol.h"
#include "targets/basic_ast_visitor.h"

namespace xpl {

  /**
   * Print nodes as XML elements to the output stream.
   */
  class type_checker: public basic_ast_visitor {
    cdk::symbol_table<xpl::symbol> &_symtab;

    basic_ast_visitor *_parent;

  public:
    type_checker(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<xpl::symbol> &symtab, basic_ast_visitor *parent) :
        basic_ast_visitor(compiler), _symtab(symtab), _parent(parent) {
    }

  public:
    ~type_checker() {
      os().flush();
    }

  public:
    void do_sequence_node(cdk::sequence_node * const node, int lvl) {
    }

  protected:
    template<typename T>
    void process_literal(cdk::literal_node<T> * const node, int lvl) {
    }

  public:
    void do_integer_node(cdk::integer_node * const node, int lvl);
    void do_string_node(cdk::string_node * const node, int lvl);

  protected:
    void processUnaryExpression(cdk::unary_expression_node * const node, int lvl);

  public:
    void do_neg_node(cdk::neg_node * const node, int lvl);

  protected:
    void processBinaryExpression(cdk::binary_expression_node * const node, int lvl);

  public:
    void do_add_node(cdk::add_node * const node, int lvl);
    void do_sub_node(cdk::sub_node * const node, int lvl);
    void do_mul_node(cdk::mul_node * const node, int lvl);
    void do_div_node(cdk::div_node * const node, int lvl);
    void do_mod_node(cdk::mod_node * const node, int lvl);
    void do_lt_node(cdk::lt_node * const node, int lvl);
    void do_le_node(cdk::le_node * const node, int lvl);
    void do_ge_node(cdk::ge_node * const node, int lvl);
    void do_gt_node(cdk::gt_node * const node, int lvl);
    void do_ne_node(cdk::ne_node * const node, int lvl);
    void do_eq_node(cdk::eq_node * const node, int lvl);
    
    void do_not_node(cdk::not_node * const node, int lvl);
    void do_or_node(cdk::or_node * const node, int lvl);
    void do_and_node(cdk::and_node * const node, int lvl);
    
    void do_double_node(cdk::double_node * const node, int lvl);

  public:
    void do_identifier_node(cdk::identifier_node * const node, int lvl);
    void do_rvalue_node(cdk::rvalue_node * const node, int lvl);
    void do_assignment_node(cdk::assignment_node * const node, int lvl);

  public:
    void do_function_definition_node(xpl::function_definition_node * const node, int lvl);
    void do_evaluation_node(xpl::evaluation_node * const node, int lvl);
    void do_print_node(xpl::print_node * const node, int lvl);
    void do_read_node(xpl::read_node * const node, int lvl);

  public:
    void do_while_node(xpl::while_node * const node, int lvl);
    void do_if_node(xpl::if_node * const node, int lvl);
    void do_if_else_node(xpl::if_else_node * const node, int lvl);

    void do_sweep_plus_node(xpl::sweep_plus_node *const node, int lvl);
    void do_sweep_minus_node(xpl::sweep_minus_node *const node, int lvl);
    void do_stop_node(xpl::stop_node *const node, int lvl);
    void do_next_node(xpl::next_node *const node, int lvl);
    void do_return_node(xpl::return_node *const node, int lvl);
    void do_block_node(xpl::block_node *const node, int lvl);
    void do_null_node(xpl::null_node *const node, int lvl);
    void do_index_node(xpl::index_node *const node, int lvl);
    void do_memory_allocate_node(xpl::memory_allocate_node *const node, int lvl);
    void do_memory_address_node(xpl::memory_address_node *const node, int lvl);
    void do_function_declaration_node(xpl::function_declaration_node *const node, int lvl);
    void do_variable_declaration_node(xpl::variable_declaration_node *const node, int lvl);
    void do_identity_node(xpl::identity_node *const node, int lvl);
    void do_function_call_node(xpl::function_call_node *const node, int lvl);
  };

} // xpl

//---------------------------------------------------------------------------
//     HELPER MACRO FOR TYPE CHECKING
//---------------------------------------------------------------------------

#define CHECK_TYPES(compiler, symtab, node) { \
  try { \
    xpl::type_checker checker(compiler, symtab, this); \
    (node)->accept(&checker, 0); \
  } \
  catch (const std::string &problem) { \
    std::cerr << (node)->lineno() << ": " << problem << std::endl; \
    return; \
  } \
}

#define ASSERT_SAFE_EXPRESSIONS CHECK_TYPES(_compiler, _symtab, node)

#endif
