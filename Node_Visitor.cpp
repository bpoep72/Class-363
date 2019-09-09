
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Node_Visitor.h"
#include "Node.h"
#include "Numeric_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"

//
//  Constructor
//
Node_Visitor::Node_Visitor() :
    root_(0)
{
    //empty
}

//
// Constructor
//
Node_Visitor::Node_Visitor(Node * root) :
    root_(root)
{
    //empty
}

//
// ~Node_Visitor
//
Node_Visitor::~Node_Visitor()
{
    //empty
}

void Node_Visitor::eval(void)
{
    if(root_ != 0)
    {
        //clear the operands stack
        operands.clear();
        root_->accept(*this);
    }
    else
    {
        throw visitor_result_invalid();
    }
}

//
// visit_add_node
//
void Node_Visitor::visit_add_node(Node & node)
{
    //visit both children nodes
    visit_children(node);

    //once we have fulfilled our civic duty to visit all nodes perform the math operation
    //then push the result back onto the operand stack
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();

    int result = a + b;
    operands.push(result);

}

//
// visit_sub_node
//
void Node_Visitor::visit_sub_node(Node & node)
{
    //visit both children nodes
    visit_children(node);

    //once we have fulfilled our civic duty to visit all nodes perform the math operation
    //then push the result back onto the operand stack
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();

    int result = a - b;
    operands.push(result);
}

//
// visit_mult_node
//
void Node_Visitor::visit_mult_node(Node & node)
{
    //visit both children nodes
    visit_children(node);

    //once we have fulfilled our civic duty to visit all nodes perform the math operation
    //then push the result back onto the operand stack
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();

    int result = a * b;
    operands.push(result);
}

//
// visit_div_node
//
void Node_Visitor::visit_div_node(Node & node)
{
    //visit both children nodes
    visit_children(node);

    //once we have fulfilled our civic duty to visit all nodes perform the math operation
    //then push the result back onto the operand stack
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();

    if(b != 0)
    {
        int result = a / b;
        operands.push(result);
    }
    else
    {
        throw Division_Node::divide_by_zero();
    }

}

//
// visit_mod_node
//
void Node_Visitor::visit_mod_node(Node & node)
{
    //visit both children nodes
    visit_children(node);

    //once we have fulfilled our civic duty to visit all nodes perform the math operation
    //then push the result back onto the operand stack
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();

    if(b != 0)
    {
        int result = a % b;
        operands.push(result);
    }
    else
    {
        throw Modulus_Node::mod_by_zero();
    }

}

//
// visit_num_node
//
void Node_Visitor::visit_num_node(Node & node)
{
    Numeric_Node *cast_node = dynamic_cast<Numeric_Node*>(&node);

    //if the above cast was successful
    if(cast_node != 0)
    {
        operands.push(cast_node->get_value());
    }
    else
    {
        throw visitor_result_invalid();
    }

}

//
// get_result
//
int Node_Visitor::get_result()
{
    //if the operands stack only has one item then the evaluation was completed and is valid
    if(operands.size() == 1)
    {
        return operands.top();
    }
    else
    {
        throw Visitor::visitor_result_invalid();
    }

}

//
// visit_children
//
void Node_Visitor::visit_children(Node & node)
{
    //visit the right child if it exists
    if(node.get_left_child() != 0) {
        Node * left_child;
        left_child = node.get_left_child();
        left_child->accept(*this);
    }
    //the node should have both a right and left child otherwise throw an error
    else
    {
        throw visitor_result_invalid();
    }
    //visit the left child if it exists
    if(node.get_right_child() != 0) {
        Node * right_child;
        right_child = node.get_right_child();
        right_child->accept(*this);
    }
    //the node should have both a right and left child otherwise throw an error
    else
    {
        throw visitor_result_invalid();
    }
}

