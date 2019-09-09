
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Postfix_Exp_Tree_Builder.h"
#include <iostream>

//
// Default constructor
//
Postfix_Exp_Tree_Builder::Postfix_Exp_Tree_Builder() :
    root_(0), current_(0)
{
    //empty
}

//
// Destructor
//
Postfix_Exp_Tree_Builder::~Postfix_Exp_Tree_Builder()
{
    //expects that the recipient knows how to delete the tree
}

//
// get_tree
//
Node* Postfix_Exp_Tree_Builder::get_tree() const
{
    return root_;
}

//
// build_add_node
//
void Postfix_Exp_Tree_Builder::build_add_node()
{
    //if this is the first node to be added to the tree it becomes the root
    if(root_ == 0)
    {
        //set the root to be a new node
        root_ = new Addition_Node();
        //set current to the new root
        current_ = root_;

    }
    //if this is not the first node to be added to the tree
    else
    {
        Addition_Node *new_node = new Addition_Node();
        place_node_in_tree(*new_node);
    }
}

//
// build_sub_node
//
void Postfix_Exp_Tree_Builder::build_sub_node()
{
    //if this is the first node to be added to the tree it becomes the root
    if(root_ == 0)
    {
        //set the root to be a new node
        root_ = new Subtraction_Node();
        //set current to the new root
        current_ = root_;
    }
    //if this is not the first node to be added to the tree
    else
    {
        Subtraction_Node *new_node = new Subtraction_Node();
        place_node_in_tree(*new_node);
    }
}

//
// build_mult_node
//
void Postfix_Exp_Tree_Builder::build_mult_node()
{
    //if this is the first node to be added to the tree it becomes the root
    if(root_ == 0)
    {
        //set the root to be a new node
        root_ = new Multiplication_Node();
        //set current to the new root
        current_ = root_;
    }
    //if this is not the first node to be added to the tree
    else
    {
        Multiplication_Node *new_node = new Multiplication_Node();
        place_node_in_tree(*new_node);
    }
}

//
// build_div_node
//
void Postfix_Exp_Tree_Builder::build_div_node()
{
    //if this is the first node to be added to the tree it becomes the root
    if(root_ == 0)
    {
        //set the root to be a new node
        root_ = new Division_Node();
        //set current to the new root
        current_ = root_;
    }
    //if this is not the first node to be added to the tree
    else
    {
        Division_Node *new_node = new Division_Node();
        place_node_in_tree(*new_node);
    }
}

//
// build_mod_node
//
void Postfix_Exp_Tree_Builder::build_mod_node()
{
    //if this is the first node to be added to the tree it becomes the root
    if(root_ == 0)
    {
        //set the root to be a new node
        root_ = new Modulus_Node();
        //set current to the new root
        current_ = root_;
    }
    //if this is not the first node to be added to the tree
    else
    {
        Modulus_Node *new_node = new Modulus_Node();
        place_node_in_tree(*new_node);
    }
}

//
// build_num_node
//
void Postfix_Exp_Tree_Builder::build_num_node(std::string number)
{
    //need to convert the string to a number before we try to pass it to the constructor
    int num;

    try
    {
        num = std::stoi(number);
    }
    catch (std::invalid_argument err)
    {
        throw std::invalid_argument(err);
    }

    //if this is the first node to be added to the tree it becomes the root.
    //(should only happen if the only thing input was as single number)
    if(root_ == 0)
    {
        //set the root to be a new node
        root_ = new Numeric_Node(num);
        //set current to the new root
        current_ = root_;
    }
    //if this is not the first node to be added to the tree
    else
    {
        /*
            This block will need to act very similarly to put_node_in_tree but
            as this block does not use the incomplete stack it is independent
        */
        Numeric_Node *new_node = new Numeric_Node(num); //this line of code cost me hours of pain (I forgot to pass the parameter)

        if(current_->get_left_child() == 0)
        {
            current_->set_left_child(*new_node);
        }
        else if(current_->get_right_child() == 0)
        {
            current_->set_right_child(*new_node);
        }
        else
        {
            try
            {
                //go back to the last incomplete node
                current_ = incomplete_nodes.top();
                incomplete_nodes.pop();
            }
            catch(Stack<Node*>::empty_exception)
            {
                delete new_node;    ///couldn't place the node so delete it
                throw invalid_expression();
            }

            delete new_node;    ///couldn't place the node so delete it

            build_num_node(number);
        }
    }
}

//
// place_node_in_tree
//
void Postfix_Exp_Tree_Builder::place_node_in_tree(Node & node)
{
    //check if the left child has not yet been assigned
    if(current_->get_left_child() == 0)
    {
        //place the new operator into the left child
        current_->set_left_child(node);

        //if both the right and the left child are empty and we are placing an operator the current_ node is incomplete
        //then it must be placed into the incomplete stack
        if(current_->get_right_child() == 0)
        {
            incomplete_nodes.push(current_);
        }

        //then we advance to current_ node
        current_ = &node;
    }
    //the left child wasn't null check the right child
    else if(current_->get_right_child() == 0)
    {
        current_->set_right_child(node);

        current_ = &node;
    }
    //else move back to the last incomplete node
    else
    {
        try
        {
            //go back to the last incomplete node
            current_ = incomplete_nodes.top();
            incomplete_nodes.pop();
        }
        catch(Stack<Node*>::empty_exception)
        {
            throw invalid_expression();
        }

        //will recursively call this function whenever a node was found to be full
        place_node_in_tree(node);
    }
}
