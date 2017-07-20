#include <string>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

#define ASSERT_UNSPEC \
    { if (node->type() != nullptr && \
          node->type()->name() != basic_type::TYPE_UNSPEC) return; }

//---------------------------------------------------------------------------

void xpl::type_checker::do_integer_node(cdk::integer_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void xpl::type_checker::do_string_node(cdk::string_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_STRING));
}

//---------------------------------------------------------------------------

inline void xpl::type_checker::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in argument of unary expression");

  // in XPL, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void xpl::type_checker::do_neg_node(cdk::neg_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void xpl::type_checker::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in right argument of binary expression");

  // in XPL, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void xpl::type_checker::do_add_node(cdk::add_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_sub_node(cdk::sub_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_mul_node(cdk::mul_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_div_node(cdk::div_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}


void xpl::type_checker::do_not_node(cdk::not_node * const node, int lvl) {
    processUnaryExpression(node, lvl);
}
void xpl::type_checker::do_or_node(cdk::or_node * const node, int lvl) {
    processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_and_node(cdk::and_node * const node, int lvl) {
    processBinaryExpression(node, lvl);
}
void xpl::type_checker::do_double_node(cdk::double_node * const node, int lvl) {
  //processBinaryExpression(node, lvl);
}



//---------------------------------------------------------------------------

void xpl::type_checker::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<xpl::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  }
  else {
    throw id;
  }
}

void xpl::type_checker::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void xpl::type_checker::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_UNSPEC;

  try {
    node->lvalue()->accept(this, lvl);
    node->rvalue()->accept(this, lvl + 2);

  } catch (const std::string &id) {
//     std::shared_ptr<xpl::symbol> symbol = std::make_shared<xpl::symbol>(new basic_type(4, basic_type::TYPE_INT), id, 0);
//     _symtab.insert(id, symbol);
//     _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
//     node->lvalue()->accept(this, lvl);  //DAVID: bah!
  }

  if (node->lvalue()->type()->name() == basic_type::TYPE_STRING || node->rvalue()->type()->name() == basic_type::TYPE_STRING)
        node->type(new basic_type(4, basic_type::TYPE_STRING));
  else if (node->lvalue()->type()->name() == basic_type::TYPE_INT || node->rvalue()->type()->name() == basic_type::TYPE_INT)
        node->type(new basic_type(4, basic_type::TYPE_INT));
  else
      throw std::string("wrong type in left/right argument of assignment expression");
}

//---------------------------------------------------------------------------

void xpl::type_checker::do_evaluation_node(xpl::evaluation_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void xpl::type_checker::do_print_node(xpl::print_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void xpl::type_checker::do_read_node(xpl::read_node * const node, int lvl) {
  /*try {
    node->argument()->accept(this, lvl);
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }*/
}

//---------------------------------------------------------------------------

void xpl::type_checker::do_while_node(xpl::while_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void xpl::type_checker::do_if_node(xpl::if_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void xpl::type_checker::do_if_else_node(xpl::if_else_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void xpl::type_checker::do_sweep_plus_node(xpl::sweep_plus_node * const node, int lvl) {}
void xpl::type_checker::do_sweep_minus_node(xpl::sweep_minus_node * const node, int lvl) {}
void xpl::type_checker::do_stop_node(xpl::stop_node * const node, int lvl) {}
void xpl::type_checker::do_next_node(xpl::next_node * const node, int lvl) {}
void xpl::type_checker::do_return_node(xpl::return_node * const node, int lvl) {}
void xpl::type_checker::do_block_node(xpl::block_node * const node, int lvl) {}
void xpl::type_checker::do_null_node(xpl::null_node * const node, int lvl) {}
void xpl::type_checker::do_index_node(xpl::index_node * const node, int lvl) {}
void xpl::type_checker::do_memory_allocate_node(xpl::memory_allocate_node * const node, int lvl) {}
void xpl::type_checker::do_memory_address_node(xpl::memory_address_node * const node, int lvl) {}
void xpl::type_checker::do_function_declaration_node(xpl::function_declaration_node * const node, int lvl) {
    if(node->value())
        node->value()->accept(this, lvl+2);
}

void xpl::type_checker::do_function_definition_node(xpl::function_definition_node * const node, int lvl) {
    if(node->value())
        node->value()->accept(this, lvl+2);
}

void xpl::type_checker::do_variable_declaration_node(xpl::variable_declaration_node * const node, int lvl) {}
void xpl::type_checker::do_identity_node(xpl::identity_node * const node, int lvl) {
    processUnaryExpression(node, lvl);
}
void xpl::type_checker::do_function_call_node(xpl::function_call_node * const node, int lvl) {
    
     std::shared_ptr<xpl::symbol> symbol = _symtab.find(*(node->name()));
    
    node->type(new basic_type(symbol->type()->size(), symbol->type()->name()));
    
    if(symbol->arguments()) {
        for(int i = node->arguments()->size(); i <= 0 ; i--) {
            cdk::expression_node *new_node = (cdk::expression_node *) node->arguments()->node(i);
            new_node->accept(this, lvl+2);
        }
    }
}