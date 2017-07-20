#ifndef __XPL_FUNCTIONDEFINIITONNODE_H__
#define __XPL_FUNCTIONDEFINIITONNODE_H__

#include <cdk/ast/basic_node.h>
#include "function_declaration_node.h"

namespace xpl {

  /**
   * Class for describing function definition nodes.
   */
  class function_definition_node: public cdk::basic_node {
    bool _is_public;
    basic_type * _type;
    std::string _name;
    cdk::sequence_node * _arguments;
    cdk::expression_node * _value;
    cdk::basic_node *_block;


   public:
     inline function_definition_node(int lineno,  bool is_public, basic_type * type, std::string name, cdk::sequence_node * arguments, cdk::expression_node * value, cdk::basic_node * block) :
         cdk::basic_node(lineno), _is_public(is_public), _type(type), _name(name), _arguments(arguments), _value(value), _block(block) {
     }
     
     inline function_definition_node(int lineno, xpl::function_declaration_node *fdecl, cdk::basic_node *block) :
         cdk::basic_node(lineno), _is_public(fdecl->is_public()), _type(fdecl->type()), _name(fdecl->name()), _arguments(fdecl->arguments()), _value(fdecl->value()), _block(block) {
     }

   public:
    inline bool is_public() {
      return _is_public;
    }
    
    inline basic_type *type() {
      return _type;
    }
    
    inline const std::string &name() {
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
    
    inline cdk::basic_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // xpl

#endif

