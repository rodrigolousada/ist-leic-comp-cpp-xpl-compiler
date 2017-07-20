#ifndef __CDK_SWEEPPLUSNODE_H__
#define __CDK_SWEEPPLUSNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>

namespace xpl {

  /**l
   * Class for describing sweep+ nodes.
   */
  class sweep_plus_node: public cdk::basic_node {
    cdk::lvalue_node *_lvalue;
    cdk::expression_node *_init, *_limit, *_step;
    cdk::basic_node *_block;

  public:
    inline sweep_plus_node(int lineno, cdk::lvalue_node *lvalue, cdk::expression_node *init, cdk::expression_node *limit, cdk::expression_node *step, cdk::basic_node *block) :
        basic_node(lineno), _lvalue(lvalue), _init(init), _limit(limit), _step(step), _block(block) {
    }

  public:
    inline cdk::lvalue_node *lvalue() {
      return _lvalue;
    }
    inline cdk::expression_node *init() {
      return _init;
    }
    inline cdk::expression_node *limit() {
      return _limit;
    }
    inline cdk::expression_node *step() {
      return _step;
    }
    inline cdk::basic_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_sweep_plus_node(this, level);
    }

  };

} // xpl 

#endif
