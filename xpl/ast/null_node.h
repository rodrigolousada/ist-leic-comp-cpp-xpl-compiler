#ifndef __CDK_NULLNODE_H__
#define __CDK_NULLNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing null nodes.
   */
  class null_node: public cdk::expression_node {

  public:
    inline null_node(int lineno) :
        expression_node(lineno) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_null_node(this, level);
    }

  };

} // xpl

#endif
