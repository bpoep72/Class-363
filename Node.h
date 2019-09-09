
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _NODE_
#define _NODE_

#define PREC_MULTIPLICATION 5
#define PREC_DIVISION 4
#define PREC_MODULUS 3
#define PREC_ADDITION 2
#define PREC_SUBTRACTION 1
#define PREC_NUM 0

#include "Visitor.h"
#include <string>

class Node
{
    public :

        /**
        *   Default constructor
        */
        Node();

        /**
        *   Alternate constructor
        *   @param[in]      prec        The precedence of the node
        *   @param[in]      left        The left child of the node
        *   @param[in]      right       The right child of the node
        */
        Node(int prec, Node & left, Node & right);

        /**
        *   Alternate constructor
        *   @param[in]      prec        The precedence of the node
        */
        Node(int prec);

        /**
        *   Destructor
        */
        virtual ~Node() {};

        /**
        *   Accept method for the visitor
        *   @param[in]      visitor     The visitor to the node.
        */
        virtual void accept(Visitor & visitor) = 0;

        //getters
        int get_precedence() const;     ///get precedence_
        Node* get_left_child() const;   ///get left_
        Node* get_right_child() const;  ///get right_
        //end getters

        //setters
        void set_right_child(Node & right); ///set left_
        void set_left_child(Node & left);   ///set right_
        //end setters

    private :
        int precedence_;
        Node *left_;
        Node *right_;

};

#endif // _NODE_
