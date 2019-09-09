
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _NODE_VISITOR_
#define _NODE_VISITOR_

#include "Visitor.h"
#include "Stack.h"

class Node_Visitor : public Visitor
{
    public :
        Node_Visitor(Node * root);

        virtual ~Node_Visitor();

        virtual void eval(void);

        virtual void visit_add_node(Node &node);
        virtual void visit_sub_node(Node &node);
        virtual void visit_mult_node(Node &node);
        virtual void visit_div_node(Node &node);
        virtual void visit_mod_node(Node &node);
        virtual void visit_num_node(Node &node);

        int get_result();

    private :
        void visit_children(Node &node);

        Node_Visitor();
        int result_;
        Node * root_;       ///the root of the tree that will be traversed
        Stack<int> operands;
};

#endif // _NODE_VISITOR_
