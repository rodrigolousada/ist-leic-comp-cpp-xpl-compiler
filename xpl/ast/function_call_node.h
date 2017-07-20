#ifndef __CDK_FUNCTIONCALLNODE_H__
#define __CDK_FUNCTIONCALLNODE_H__

#include <cdk/ast/expression_node.h>
#include <string>

namespace xpl {

  /**
   * Class for describing function call nodes.
   */
  class function_call_node: public cdk::expression_node {
    std::string *_name;
    cdk::sequence_node * _arguments;

  public:
    inline function_call_node(int lineno, std::string *name, cdk::sequence_node * arguments) :
        cdk::expression_node(lineno), _name(name), _arguments(arguments) {
    }

  public:
    inline std::string *name() {
      return _name;
    }  
     
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // xpl

#endif