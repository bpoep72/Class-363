
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Multiplication_Node.h"

//
// Default constructor
//
Multiplication_Node::Multiplication_Node() :
    Node(PREC_MULTIPLICATION)
{
    //empty
}

//
// Custom constructor
//
Multiplication_Node::Multiplication_Node(Node & left, Node & right) :
    Node(PREC_MULTIPLICATION, left, right)
{
    //empty
}

//
// Destructor
//
Multiplication_Node::~Multiplication_Node()
{
    //deletion is carried out by expression tree class
}

//
// accept
//
void Multiplication_Node::accept(Visitor &visitor)
{
    visitor.visit_mult_node(*this);
}
