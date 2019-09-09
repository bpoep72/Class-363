
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Modulus_Node.h"

//
// Default constructor
//
Modulus_Node::Modulus_Node() :
    Node(PREC_MODULUS)
{
    //empty
}

//
// Custom constructor
//
Modulus_Node::Modulus_Node(Node & left, Node & right) :
    Node(PREC_MODULUS, left, right)
{
    //empty
}

//
// Destructor
//
Modulus_Node::~Modulus_Node()
{
    //deletion is carried out by expression tree class
}

//
// accept
//
void Modulus_Node::accept(Visitor &visitor)
{
    visitor.visit_mod_node(*this);
}
