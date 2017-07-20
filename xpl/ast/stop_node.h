#ifndef __CDK_STOPNODE_H__
#define __CDK_STOPNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing stop nodes.
   */
  class stop_node: public cdk::basic_node {

  public:
    inline stop_node(int lineno) :
        basic_node(lineno) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };

} // xpl

#endif
 
