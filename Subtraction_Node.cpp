
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Subtraction_Node.h"

//
// Default constructor
//
Subtraction_Node::Subtraction_Node() :
    Node(PREC_SUBTRACTION)
{
    //empty
}

//
// Custom constructor
//
Subtraction_Node::Subtraction_Node(Node & left, Node & right) :
    Node(PREC_SUBTRACTION, left, right)
{
    //empty
}

//
// Destructor
//
Subtraction_Node::~Subtraction_Node()
{
    //deletion is carried out by expression tree class
}

//
// accept
//
void Subtraction_Node::accept(Visitor &visitor)
{
    visitor.visit_sub_node(*this);
}
