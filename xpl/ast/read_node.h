// $Id: read_node.h,v 1.2 2017/03/23 15:48:42 ist181115 Exp $ -*- c++ -*-
#ifndef __XPL_READNODE_H__
#define __XPL_READNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing read nodes.
   */
  class read_node: public cdk::expression_node {

  public:
    inline read_node(int lineno) :
        cdk::expression_node(lineno) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_read_node(this, level);
    }

  };

} // xpl

#endif
