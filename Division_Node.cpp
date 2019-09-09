
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Division_Node.h"

//
// Default constructor
//
Division_Node::Division_Node() :
    Node(PREC_DIVISION)
{
    //empty
}

//
// Custom constructor
//
Division_Node::Division_Node(Node & left, Node & right) :
    Node(PREC_DIVISION, left, right)
{
    //empty
}

//
// Destructor
//
Division_Node::~Division_Node()
{
    //deletion is carried out by expression tree class
}

//
// accept
//
void Division_Node::accept(Visitor &visitor)
{
    visitor.visit_div_node(*this);
}
