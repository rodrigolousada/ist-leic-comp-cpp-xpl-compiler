#include <string>
#include "targets/frame_pointer_counter.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

void xpl::frame_pointer_counter::do_sequence_node(cdk::sequence_node * const node, int lvl) {
    for(cdk::basic_node * basic_node : node->nodes()) {
        basic_node->accept(this, lvl+2);
    }
}

void xpl::frame_pointer_counter::do_block_node(xpl::block_node * const node, int lvl) {
    if(node->declarations())
        node->declarations()->accept(this, lvl+2);
    
    if(node->instructions())
        node->instructions()->accept(this, lvl+2);
}

void xpl::frame_pointer_counter::do_variable_declaration_node(xpl::variable_declaration_node * const node, int lvl) {
    _size += node->type()->size();
    if(node->type()->size() > _max_size)
        _max_size = node->type()->size();
}


void xpl::frame_pointer_counter::do_function_definition_node(xpl::function_definition_node * const node, int lvl) {
    node->block()->accept(this, lvl+2);
}

void xpl::frame_pointer_counter::do_function_call_node(xpl::function_call_node * const node, int lvl) {
    if(node->arguments())
        node->arguments()->accept(this, lvl+2);
}

void xpl::frame_pointer_counter::do_sweep_plus_node(xpl::sweep_plus_node * const node, int lvl) {
    if(node->init())
        node->init()->accept(this, lvl+2);
}

void xpl::frame_pointer_counter::do_sweep_minus_node(xpl::sweep_minus_node * const node, int lvl) {
    if(node->init())
        node->init()->accept(this, lvl+2);
}

void xpl::frame_pointer_counter::do_integer_node(cdk::integer_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_string_node(cdk::string_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_unary_expression(cdk::unary_expression_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_neg_node(cdk::neg_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_binary_expression(cdk::binary_expression_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_add_node(cdk::add_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_sub_node(cdk::sub_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_mul_node(cdk::mul_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_div_node(cdk::div_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_mod_node(cdk::mod_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_lt_node(cdk::lt_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_le_node(cdk::le_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_ge_node(cdk::ge_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_gt_node(cdk::gt_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_ne_node(cdk::ne_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_eq_node(cdk::eq_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_identifier_node(cdk::identifier_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_assignment_node(cdk::assignment_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_evaluation_node(xpl::evaluation_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_print_node(xpl::print_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_read_node(xpl::read_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_while_node(xpl::while_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_if_node(xpl::if_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_if_else_node(xpl::if_else_node * const node, int lvl) {}

void xpl::frame_pointer_counter::do_stop_node(xpl::stop_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_next_node(xpl::next_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_return_node(xpl::return_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_null_node(xpl::null_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_index_node(xpl::index_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_memory_allocate_node(xpl::memory_allocate_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_memory_address_node(xpl::memory_address_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_function_declaration_node(xpl::function_declaration_node * const node, int lvl) {}
void xpl::frame_pointer_counter::do_identity_node(xpl::identity_node * const node, int lvl) {}