#ifndef __XPL_SEMANTICS_SYMBOL_H__
#define __XPL_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace xpl {

    class symbol {
      basic_type *_type;
      std::string _name;
      int _offset;
      bool _is_global;
      
      cdk::sequence_node *_arguments;
      
      bool _is_function;
      
      bool _is_public;
      bool _is_used;

    public:
      inline symbol(basic_type *type, const std::string &name, int offset, bool is_global, cdk::sequence_node *arguments, bool is_function, bool is_public, bool is_used) :
          _type(type), _name(name), _offset(offset), _is_global(is_global), _arguments(arguments), _is_function(is_function), _is_public(is_public), _is_used(is_used) {
      }

      virtual ~symbol() {
        delete _type;
      }

      inline basic_type *type() const {
        return _type;
      }
      inline const std::string &name() const {
        return _name;
      }
      inline int offset() const {
        return _offset;
      }
      inline int offset(int offset) {
        return _offset = offset;
      }
      
      inline bool is_global() const {
        return _is_global;
      }
      inline bool is_global(bool is_global) {
        return _is_global = is_global;
      }
      inline cdk::sequence_node *arguments() {
        return _arguments;
      }
      inline cdk::sequence_node *arguments(cdk::sequence_node *arguments) {
        return _arguments = arguments;
      }
      inline bool is_function() const {
        return _is_function;
      }
      inline bool is_function(bool is_function) {
        return _is_function = is_function;
      }
      inline bool is_public() const {
        return _is_public;
      }
      inline bool is_public(bool is_public) {
        return _is_public = is_public;
      }
      inline bool is_used() const {
        return _is_used;
      }
      inline bool is_used(bool is_used) {
        return _is_used = is_used;
      }
    };

} // xpl

#endif
