
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _DIVISION_NODE_
#define _DIVISION_NODE_

#include "Node.h"

class Division_Node : public Node
{
    public:
        /**
        *   The Default constructor
        */
        Division_Node();

        /**
        *   Constructor to instantiate a node with left and right child
        *   @param[in]      left        The left child of the operator node
        *   @param[in]      right       The right child of the operator node
        */
        Division_Node(Node & left, Node & right);

        /**
        *   Destructor
        */
        virtual ~Division_Node();

        /**
        *   Accept method for the visitor
        *   @param[in]      visitor     The visitor to the node.
        */
        virtual void accept(Visitor &visitor);

        /**
        *   Exception to be thrown when the a division by zero is attempted
        */
        class divide_by_zero : public std::exception
        {
            public:
                /// Default constructor.
                divide_by_zero (void)
                    : std::exception ()
                {
                    //empty
                }

                virtual const char* what() const throw()
                {
                    return "Division by zero error.";
                }
        };
};

#endif // _DIVISION_
