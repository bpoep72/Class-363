
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _VISITOR_
#define _VISITOR_

#include <exception>

//forward declaration of Node
class Node;

class Visitor
{
    public :
        virtual ~Visitor() {};

        virtual void eval(void) = 0;

        virtual void visit_add_node(Node &node) = 0;
        virtual void visit_sub_node(Node &node) = 0;
        virtual void visit_mult_node(Node &node) = 0;
        virtual void visit_div_node(Node &node) = 0;
        virtual void visit_mod_node(Node &node) = 0;
        virtual void visit_num_node(Node &node) = 0;

        /**
        *   Exception to be thrown whenever the statement is decided to be invalid
        */
        class visitor_result_invalid : public std::exception
        {
            public:
                /// Default constructor.
                visitor_result_invalid (void)
                    : std::exception ()
                {
                    //empty
                }

                virtual const char* what() const throw()
                {
                    return "The visitor has reached an invalid state for result retrieval.";
                }
        };
};

#endif // _VISITOR_
