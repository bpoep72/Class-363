
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Node.h"

//
//  Default constructor
//
Node::Node() :
    precedence_(-1), left_(0), right_(0)
{

}

//
// constructor
//
Node::Node(int prec) :
    precedence_(prec), left_(0), right_(0)
{

}

//
// custom child constructor
//
Node::Node(int prec, Node & left, Node & right) :
    precedence_(prec), left_(&left), right_(&right)
{

}

//
// get_precedence
//
int Node::get_precedence() const
{
    return precedence_;
}

//
// get_left_child
//
Node* Node::get_left_child() const
{
    return left_;
}

//
// get_right_child
//
Node* Node::get_right_child() const
{
    return right_;
}

///end getters

///setters

//
// set_left_child
//
void Node::set_left_child(Node & left)
{
    left_ = &left;
}

//
// set_right_child
//
void Node::set_right_child(Node & right)
{
    right_ = &right;
}
