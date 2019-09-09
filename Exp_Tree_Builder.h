
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _EXP_TREE_BUILDER_
#define _EXP_TREE_BUILDER_

#include <string>
#include <memory>

#include "Node.h"

class Exp_Tree_Builder
{
    public :
        /**
        *   Destructor
        */
        virtual ~Exp_Tree_Builder() {};

        /**
        *   The method to get the constructed tree
        *   @return             Node*           A pointer to the tree created by the builder
        */
        virtual Node* get_tree() const = 0;

        /**
        *   Places an add node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_add_node() = 0;

        /**
        *   Places a subtraction node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_sub_node() = 0;

        /**
        *   Places a multiplication node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_mult_node() = 0;

        /**
        *   Places a division node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_div_node() = 0;

        /**
        *   Places a modulus node at the root of the tree.
        *   Also connects the left and right children if they exist.
        */
        virtual void build_mod_node() = 0;

        /**
        *   Places a number node at the root of the tree.
        *   Also connects the left and right children if they exist.
        *   @param[in]          Node&           The root of the tree the node will be placed in
        */
        virtual void build_num_node(std::string number) = 0;
};

#endif // _EXP_TREE_BUILDER_
