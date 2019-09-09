
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _POSTFIX_EXP_TREE_BUILDER_
#define _POSTFIX_EXP_TREE_BUILDER_

#include "Node.h"
#include "Exp_Tree_Builder.h"
#include "Stack.h"
#include "Expr_Tree.h"

#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Division_Node.h"
#include "Multiplication_Node.h"
#include "Modulus_Node.h"
#include "Numeric_Node.h"

class Postfix_Exp_Tree_Builder : public Exp_Tree_Builder
{
    private :
        Node* root_;                    ///the root of the tree
        Node* current_;                 ///the current operator node
        Stack<Node*> incomplete_nodes;  ///a stack of the nodes that have not yet been filled

        /**
        *   Performs the logical checks for placing the node into the tree then places the node into the tree
        *   @param[in]          Node&           The node to be placed into the tree.
        */
        void place_node_in_tree(Node & node);

    public :
        /**
        *   Default constructor
        */
        Postfix_Exp_Tree_Builder();

        /**
        *   Destructor
        */
        virtual ~Postfix_Exp_Tree_Builder();

        /**
        *   The method to get the constructed tree
        *   @return             Node*        A pointer to the tree created by the builder
        */
        virtual Node* get_tree() const;

        /**
        *   Places an add node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_add_node();

        /**
        *   Places a subtraction node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_sub_node();

        /**
        *   Places a multiplication node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_mult_node();

        /**
        *   Places a division node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_div_node();

        /**
        *   Places a modulus node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_mod_node();

        /**
        *   Places a number node at the root of the tree.
        *   Also connects the left and right children if they exist.
        *   @param[in]          number          The number that will be placed in the tree
        */
        virtual void build_num_node(std::string number);

        /**
        * Exception to be thrown whenever the statement is decided to be invalid
        */
        class invalid_expression : public std::exception
        {
            public:
                /// Default constructor.
                invalid_expression (void)
                    : std::exception () { }

                virtual const char* what() const throw()
                {
                    return "The given expression is invalid.";
                }
        };
};

#endif // _POSTFIX_EXP_TREE_BUILDER_
