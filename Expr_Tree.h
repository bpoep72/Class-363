
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _EXPR_TREE_
#define _EXPR_TREE_

#include "Node.h"

class Expr_Tree
{
    public :

        /**
        *   Default constructor
        */
        Expr_Tree();

        /**
        *   Copy constructor
        */
        Expr_Tree(Expr_Tree & tree);

        /**
        *   Will handle the complex deletion of the tree at root_
        */
        ~Expr_Tree();

        //

        //getter : root_
        Node * get_root() const;        ///get the root

        //setter : root_
        void set_root(Node * root);     ///set the root

    private :
        /**
        *   Method to clean up the tree
        */
        void delete_tree(Node * node);

        Node * root_;
};

#endif // _EXPR_TREE_
