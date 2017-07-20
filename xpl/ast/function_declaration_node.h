#ifndef __CDK_FUNCTIONDECLARATIONNODE_H__
#define __CDK_FUNCTIONDECLARATIONNODE_H__

#include <cdk/ast/expression_node.h>
#include <string>

namespace xpl {

  /**
   * Class for describing function declaration nodes.
   */
  class function_declaration_node: public cdk::basic_node {
    bool _is_public;
    bool _is_used;
    basic_type * _type;
    std::string _name;
    cdk::sequence_node * _arguments;
    cdk::expression_node * _value;

  public:
    inline function_declaration_node(int lineno, bool is_public, bool is_used, basic_type * type, std::string name, cdk::sequence_node * arguments, cdk::expression_node * value) :
        cdk::basic_node(lineno), _type(type), _name(name), _arguments(arguments), _value(value) {
    }

  public:
    inline bool is_public() {
      return _is_public;
    }
    
    inline bool is_used() {
      return _is_used;
    }
    
    inline basic_type *type() {
      return _type;
    }
    
    inline const std::string & name() {
      return _name;
    }
    
    inline void name(const std::string &name) {
      _name = name;
    }
    
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }
    
    inline cdk::expression_node *value() {
      return _value;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // xpll

#endif