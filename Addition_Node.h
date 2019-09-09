
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _ADDITION_NODE_
#define _ADDITION_NODE_

#include "Node.h"

class Addition_Node : public Node
{
    public:
        /**
        *   The Default constructor
        */
        Addition_Node();

        /**
        *   Constructor to instantiate a node with left and right child
        *   @param[in]      left        The left child of the operator node
        *   @param[in]      right       The right child of the operator node
        */
        Addition_Node(Node & left, Node & right);

        /**
        *   Destructor
        */
        virtual ~Addition_Node();

        /**
        *   Accept method for the visitor
        *   @param[in]      visitor     The visitor to the node.
        */
        virtual void accept(Visitor &visitor);
};

#endif // _ADDITION_
