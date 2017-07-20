#ifndef __CDK_MEMORYALLOCATENODE_H__
#define __CDK_MEMORYALLOCATENODE_H__

#include <cdk/ast/unary_expression_node.h>

namespace xpl {

  /**
   * Class for describing memory allocate nodes.
   */
  class memory_allocate_node: public cdk::unary_expression_node {

  public:
    inline memory_allocate_node(int lineno, cdk::expression_node *argument) :
        cdk::unary_expression_node(lineno, argument) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_memory_allocate_node(this, level);
    }

  };

} // xpl

#endif