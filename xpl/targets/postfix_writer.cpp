#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/frame_pointer_counter.h"
#include "ast/all.h"  // all.h is automatically generated

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
    if(_is_var_int){
        _pf.CONST(node->value());
        _is_var_int = false;
    }
    else{
        _pf.INT(node->value()); // push an integer
    }
}

void xpl::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.STR(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    node->argument()->accept(this, lvl); // determine the value
    if(node->type()->name() == basic_type::TYPE_DOUBLE)
        _pf.DNEG();
    else
        _pf.NEG();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void xpl::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void xpl::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void xpl::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void xpl::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void xpl::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void xpl::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void xpl::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void xpl::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void xpl::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void xpl::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}


void xpl::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    node->argument()->accept(this, lvl);
    _pf.NOT();
}

void xpl::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    
    std::string label = mklbl(++_lbl);
    
    node->left()->accept(this, lvl);
    _pf.DUP();
    _pf.JNZ(label);
    _pf.TRASH(node->type()->size());
    node->right()->accept(this, lvl);
    _pf.ALIGN();
    _pf.LABEL(label);
}

void xpl::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    std::string label = mklbl(++_lbl);
    
    node->left()->accept(this, lvl);
    _pf.DUP();
    _pf.JZ(label);
    _pf.TRASH(node->type()->size());
    node->right()->accept(this, lvl);
    _pf.ALIGN();
    _pf.LABEL(label);
}

void xpl::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) { 
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  
  const std::string &id = node->name();
  std::shared_ptr<xpl::symbol> symbol = _symtab.find(id);
  
  if(symbol->is_global() && !symbol->is_function()) {
      _pf.ADDR(node->name());
  }
  else {
      _pf.LOCAL(symbol->offset());
  }
}

void xpl::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  _pf.LOAD(); // depends on type size
}

void xpl::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP();
  //if (new_symbol() == nullptr) {
    node->lvalue()->accept(this, lvl); // where to store the value
  //} else {
    //_pf.DATA(); // variables are all global and live in DATA
    //_pf.ALIGN(); // make sure we are aligned
    //_pf.LABEL(new_symbol()->name()); // name variable location
    //_pf.CONST(0); // initialize it to 0 (zero)
    //_pf.TEXT(); // return to the TEXT segment
    //node->lvalue()->accept(this, lvl);  //DAVID: bah!
  //}
  _pf.STORE(); // store the value at address
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_function_definition_node(xpl::function_definition_node * const node, int lvl) {
  // The ProgramNode (representing the whole function_definition) is the
  // main function node.

  if(node->name() == "xpl") {
       node->name("_main");
   }
   
   _local_offset = -node->type()->size();
   
   std::string id = node->name();
   std::shared_ptr<xpl::symbol> symbol = std::make_shared<xpl::symbol>(new basic_type(node->type()->size(), node->type()->name()), id, _local_offset, _is_global, node->arguments(), true, node->is_public(), false);
   _symtab.insert(id, symbol);
   
   xpl::frame_pointer_counter fpc(_compiler);
   node->accept(&fpc, lvl+2);
    
   
  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL(node->name(), _pf.FUNC());
  _pf.LABEL(node->name());
  _pf.ENTER(fpc.size() - _local_offset);  // XPL doesn't implement local variables
  
  if(node->value() != nullptr) {
      node->value()->accept(this, lvl+2);
      _pf.LOCAL(_local_offset);
      _pf.STORE();
  }
  
  _is_global = false;
  node->block()->accept(this, lvl);
  _is_global = true;
  
  // end the main function
  
  if(node->type()->name() != basic_type::TYPE_VOID) {
      //_pf.INT(0);
      _pf.LOCAL(_local_offset);
      _pf.LOAD();
      _pf.POP();
  }
  
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("reads");
  _pf.EXTERN("readd");
  _pf.EXTERN("readp");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("printd");
  _pf.EXTERN("printp");
  _pf.EXTERN("println");
  _pf.EXTERN("argc");
  _pf.EXTERN("argv");


}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_evaluation_node(xpl::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.TRASH(4); // delete the evaluated value
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.TRASH(4); // delete the evaluated value's address
  } else if (node->argument()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.TRASH(4); // delete the printed value's address
  } else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.TRASH(8); // delete the printed value's address
  }else if (node->argument()->type()->name() == basic_type::TYPE_VOID) {
    ; // delete the printed value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

void xpl::postfix_writer::do_print_node(xpl::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  } else if (node->argument()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.CALL("printp");
    _pf.TRASH(4); // delete the printed value's address
  } else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.CALL("printd");
    _pf.TRASH(8); // delete the printed value's address
  } else if (node->argument()->type()->name() == basic_type::TYPE_VOID) {
    ; // delete the printed value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
  
  if(node->print_new_line()) {
      _pf.CALL("println"); // print a newline
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_read_node(xpl::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (node->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("readi");
    _pf.PUSH();
  } else if (node->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("reads");
    _pf.PUSH();
  } else if (node->type()->name() == basic_type::TYPE_POINTER) {
    _pf.CALL("readp");
    _pf.PUSH();
  } else if (node->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.CALL("readd");
    _pf.DPUSH();
  } else if (node->type()->name() == basic_type::TYPE_VOID) {
    ;
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_while_node(xpl::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1 = ++_lbl;
  int lbl2 = ++_lbl;
  
  _stop_labels.push_back(mklbl(lbl2));
  _next_labels.push_back(mklbl(lbl1));
  
  _pf.LABEL(mklbl(lbl1));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl2));
  node->block()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl1));
  _pf.LABEL(mklbl(lbl2));
  
  
  _stop_labels.pop_back();
  _next_labels.pop_back();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_node(xpl::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_else_node(xpl::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}

void xpl::postfix_writer::do_sweep_plus_node(xpl::sweep_plus_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    int limit_lbl = ++_lbl;
    int end_lbl = ++_lbl;
    int step_lbl = ++_lbl;
    
    _stop_labels.push_back(mklbl(end_lbl)); 
    _next_labels.push_back(mklbl(step_lbl));
    
    _pf.ALIGN();
    node->init()->accept(this, lvl+2);
    //_pf.DUP();
    node->lvalue()->accept(this, lvl+2);
    _pf.STORE();
    //_pf.TRASH(4);
    
    _pf.LABEL(mklbl(limit_lbl));
    
    node->lvalue()->accept(this, lvl+2);
    _pf.LOAD();
    
    node->limit()->accept(this, lvl+2);
    
    _pf.LE();
    
    _pf.JZ(mklbl(end_lbl));
    
    node->lvalue()->accept(this, lvl+2);
    _pf.LOAD();
    
    node->block()->accept(this, lvl+2);
    _pf.LABEL(mklbl(step_lbl));
    
    node->lvalue()->accept(this, lvl+2);
    _pf.LOAD();
    
    if(node->step())
        node->step()->accept(this, lvl+2);
    else
        _pf.INT(1);
    _pf.ADD();
    
    node->lvalue()->accept(this, lvl+2);
    _pf.STORE();
    
    _pf.JMP(mklbl(limit_lbl));
    _pf.LABEL(mklbl(end_lbl));
    
    _stop_labels.pop_back();
    _next_labels.pop_back();
}
void xpl::postfix_writer::do_sweep_minus_node(xpl::sweep_minus_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    int limit_lbl = ++_lbl;
    int end_lbl = ++_lbl;
    int step_lbl = ++_lbl;
    
    _stop_labels.push_back(mklbl(end_lbl)); 
    _next_labels.push_back(mklbl(step_lbl));
    
    _pf.ALIGN();
    node->init()->accept(this, lvl+2);
    //_pf.DUP();
    node->lvalue()->accept(this, lvl+2);
    _pf.STORE();
    //_pf.TRASH(4);
    
    _pf.LABEL(mklbl(limit_lbl));
    
    node->lvalue()->accept(this, lvl+2);
    _pf.LOAD();
    
    node->limit()->accept(this, lvl+2);
    
    _pf.GE();
    
    _pf.JZ(mklbl(end_lbl));
    
    node->lvalue()->accept(this, lvl+2);
    _pf.LOAD();
    
    node->block()->accept(this, lvl+2);
    _pf.LABEL(mklbl(step_lbl));
    
    node->lvalue()->accept(this, lvl+2);
    _pf.LOAD();
    
    if(node->step())
        node->step()->accept(this, lvl+2);
    else
        _pf.INT(1);
    _pf.SUB();
    
    node->lvalue()->accept(this, lvl+2);
    _pf.STORE();
    
    _pf.JMP(mklbl(limit_lbl));
    _pf.LABEL(mklbl(end_lbl));
    
    _stop_labels.pop_back();
    _next_labels.pop_back();
}

void xpl::postfix_writer::do_stop_node(xpl::stop_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    if(_stop_labels.empty()) {
        std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
        exit(1);
    }
    
    _pf.JMP(_stop_labels.back());
}

void xpl::postfix_writer::do_next_node(xpl::next_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    if(_next_labels.empty()) {
        std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
        exit(1);
    }
    
    _pf.JMP(_next_labels.back());
}

void xpl::postfix_writer::do_return_node(xpl::return_node * const node, int lvl) {}

void xpl::postfix_writer::do_block_node(xpl::block_node * const node, int lvl) {
    _pf.PUSH();
    
    if(node->declarations() != nullptr)
        node->declarations()->accept(this, lvl+2);
    if(node->instructions() != nullptr)
        node->instructions()->accept(this, lvl+2);
    
    _pf.POP();
}

void xpl::postfix_writer::do_null_node(xpl::null_node * const node, int lvl) {}

void xpl::postfix_writer::do_index_node(xpl::index_node * const node, int lvl) {
}

void xpl::postfix_writer::do_memory_allocate_node(xpl::memory_allocate_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    node->argument()->accept(this, lvl+2);
    _pf.INT(node->type()->subtype()->size());
    _pf.MUL();
    _pf.ALLOC();
    _pf.SP();
}

void xpl::postfix_writer::do_memory_address_node(xpl::memory_address_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    node->argument()->accept(this, lvl);
}

void xpl::postfix_writer::do_function_declaration_node(xpl::function_declaration_node * const node, int lvl) {
    const std::string &id = node->name();
    std::shared_ptr<xpl::symbol> symbol = _symtab.find(id);
    
    if(node->name() == "xpl") {
         node->name("_main");
     }
    
    if(symbol == nullptr) {
        symbol = std::make_shared<xpl::symbol>(new basic_type(node->type()->size(), node->type()->name()), id, -node->type()->size(), _is_global, node->arguments(), true, node->is_public(), node->is_used());
        
        _symtab.insert(id, symbol);
    }
}

void xpl::postfix_writer::do_function_call_node(xpl::function_call_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    
    std::string &id = *(node->name());
    std::shared_ptr<xpl::symbol> symbol = _symtab.find(id);
    
    node->type(new basic_type(symbol->type()->size(), symbol->type()->name()));
    
    int argsSize = 0;
    if(symbol->arguments()) {
        for(int i = node->arguments()->size(); i <= 0 ; i--) {
            cdk::expression_node *new_node = (cdk::expression_node *) node->arguments()->node(i);
            new_node->accept(this, lvl+2);
            argsSize += new_node->type()->size();
        }
    }
    
    _pf.CALL(symbol->name());
    _pf.TRASH(argsSize);
    _pf.PUSH();
}

void xpl::postfix_writer::do_variable_declaration_node(xpl::variable_declaration_node * const node, int lvl) {

    std::string &id = *(node->name());
    std::shared_ptr<xpl::symbol> symbol = _symtab.find_local(id);
    int string_lbl;
    
    if(_is_global) {
        symbol = std::make_shared<xpl::symbol>(new basic_type(node->type()->size(), node->type()->name()), id, 0, _is_global, nullptr, false, false, false);
    
        _symtab.insert(id, symbol);
        
        if(node->is_public())
            _pf.GLOBAL(*(node->name()), _pf.OBJ());

        
        if(node->value() == nullptr) {
            _pf.BSS();
            _pf.ALIGN();
            _pf.LABEL(*(node->name()));
            _pf.BYTE(node->type()->size());
        }
        else if(node->type()->name() == basic_type::TYPE_STRING) {
            _pf.RODATA();
            _pf.ALIGN();
            _pf.LABEL(mklbl(string_lbl = ++_lbl));        
            node->value()->accept(this, lvl+2);
            _pf.DATA();
            _pf.ALIGN();
            _pf.LABEL(*(node->name()));
            _pf.ID(mklbl(string_lbl));
        }    
        else {
            _pf.DATA(); //_pf.RODATA();
            _pf.ALIGN();
            _pf.LABEL(*(node->name()));
            _is_var_int = true;
            node->value()->accept(this, lvl+2);
        }
    }
    else {
        
        _local_offset -= node->type()->size();
        
        symbol = std::make_shared<xpl::symbol>(new basic_type(node->type()->size(), node->type()->name()), id, _local_offset, _is_global, nullptr, false, false, false);
        _symtab.insert(id, symbol);
        
        if(node->value()) {
            //a=1
            node->value()->accept(this, lvl+2);
            //_pf.DUP();
            _pf.LOCAL(_local_offset);
            _pf.STORE();
        }
    }
}

void xpl::postfix_writer::do_identity_node(xpl::identity_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;
    node->argument()->accept(this,lvl);
}