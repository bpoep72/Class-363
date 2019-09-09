
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Addition_Node.h"
#include <iostream>

//
// Default constructor
//
Addition_Node::Addition_Node() :
    Node(PREC_ADDITION)
{
    //empty
}

//
// Custom constructor
//
Addition_Node::Addition_Node(Node & left, Node & right) :
    Node(PREC_ADDITION, left, right)
{
    //empty
}

//
// Destructor
//
Addition_Node::~Addition_Node()
{
    //deletion is carried out by expression tree class
}

//
// accept
//
void Addition_Node::accept(Visitor &visitor)
{
    visitor.visit_add_node(*this);
}


///end setters

