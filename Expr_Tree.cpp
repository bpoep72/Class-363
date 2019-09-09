
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Expr_Tree.h"

//
// default constructor
//
Expr_Tree::Expr_Tree() :
    root_(0)
{
    //empty
}

//
//  copy constructor
//
Expr_Tree::Expr_Tree(Expr_Tree& tree) :
    root_(tree.get_root())
{
    //empty
}

//
// destructor
//
Expr_Tree::~Expr_Tree()
{
    //clean up the tree from the root down
    delete_tree(root_);
}


//
// get_root
//
Node* Expr_Tree::get_root() const
{
    return root_;
}

//
// set_root
//
void Expr_Tree::set_root(Node * root)
{
    //if the root is not null and was are resetting the root of the tree delete the old tree
    if(root_ != 0)
    {
        delete_tree(root_);
    }

    root_ = root;
}

//
// delete_node
//
void Expr_Tree::delete_tree(Node * node)
{
    if(node == 0) return;

    delete_tree(node->get_left_child());
    delete_tree(node->get_right_child());

    delete node;
}
