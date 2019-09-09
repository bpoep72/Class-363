
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Numeric_Node.h"

//
// Default constructor
//
Numeric_Node::Numeric_Node() :
    Node(PREC_NUM), value_(0)
{
    //empty
}

//
//  alternate constructor
//
Numeric_Node::Numeric_Node(int value) :
    Node(PREC_NUM), value_(value)
{

}

//
// alternate constructor
//
Numeric_Node::Numeric_Node(Node & left, Node & right) :
    Node(PREC_NUM, left, right), value_(0)
{
    //empty
}

//
// Destructor
//
Numeric_Node::~Numeric_Node()
{
    //deletion is carried out by expression tree class
}

//
// accept
//
void Numeric_Node::accept(Visitor &visitor)
{
    visitor.visit_num_node(*this);
}

//
// set_value
//
void Numeric_Node::set_value(int value)
{
    value_ = value;
}

//
// get_value
//
int Numeric_Node::get_value() const
{
    return value_;
}
