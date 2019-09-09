
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _MODULUS_NODE_
#define _MODULUS_NODE_

#include "Node.h"

class Modulus_Node : public Node
{
    public:
        /**
        *   The Default constructor
        */
        Modulus_Node();

        /**
        *   Constructor to instantiate a node with left and right child
        *   @param[in]      left        The left child of the operator node
        *   @param[in]      right       The right child of the operator node
        */
        Modulus_Node(Node & left, Node & right);

        /**
        *   Destructor
        */
        virtual ~Modulus_Node();

        /**
        *   Accept method for the visitor
        *   @param[in]      visitor     The visitor to the node.
        */
        virtual void accept(Visitor &visitor);

        /**
        *   Exception to be thrown when the a division by zero is attempted
        */
        class mod_by_zero : public std::exception
        {
            public:
                /// Default constructor.
                mod_by_zero (void)
                    : std::exception ()
                {
                    //empty
                }

                virtual const char* what() const throw()
                {
                    return "Mod by zero error.";
                }
        };
};

#endif // _MODULUS_
