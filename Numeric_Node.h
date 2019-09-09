
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _NUMERIC_NODE_
#define _NUMERIC_NODE_

#include "Node.h"

class Numeric_Node : public Node
{
    public:
        /**
        *   The Default constructor
        */
        Numeric_Node();

        /**
        *   An initializer constructor
        *   @param[in]      int         The value that the node will store
        */
        Numeric_Node(int value);

        /**
        *   Destructor
        */
        virtual ~Numeric_Node();

        /**
        *   Accept method for the visitor
        *   @param[in]      visitor     The visitor to the node.
        */
        virtual void accept(Visitor &visitor);

        //getter
        int get_value() const;         ///get the value of the node

        //setter
        void set_value(int value);     ///set the node's value

    private:

        /**
        *   Constructor to instantiate a node with left and right child
        *   @param[in]      left        The left child of the operator node
        *   @param[in]      right       The right child of the operator node
        */
        Numeric_Node(Node & left, Node & right);

        int value_;
};

#endif // _NUMERIC_

