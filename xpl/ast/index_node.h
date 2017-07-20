#ifndef __CDK_INDEXNODE_H__
#define __CDK_INDEXNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing index nodes.
   */
  class index_node: public cdk::lvalue_node {
    cdk::expression_node *_base_pointer, *_offset;
    
      
  public:
    inline index_node(int lineno, cdk::expression_node * base_pointer, cdk::expression_node * offset) :
        lvalue_node(lineno), _base_pointer(base_pointer), _offset(offset) {
    }

  public:
    inline cdk::expression_node *base_pointer() {
      return _base_pointer;
    }
    
    inline cdk::expression_node *offset() {
      return _offset;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_index_node(this, level);
    }

  };

} // xpl

#endif
 
 
