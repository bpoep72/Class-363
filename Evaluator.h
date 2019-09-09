
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include <string>
#include <exception>
#include <iostream>

#include "InToPostFix.h"
#include "Postfix_Exp_Tree_Builder.h"
#include "Expr_Tree.h"
#include "Node_Visitor.h"

class Evaluator
{
    public :
        /**
        *   Default constructor
        */
        Evaluator();

        /**
        *   Destructor
        */
        ~Evaluator();

        /**
        *   Evaluate method takes an input and returns the output to the caller
        *   @return         int             the output of the evaluation of the given string
        *   @throw          invalid_result  will throw invalid result when the expression evaluation failed
        */
        int evaluate(std::string input);

        /**
        * Exception to be thrown whenever the statement is decided to be invalid
        */
        class invalid_result : public std::exception
        {
            public:
                /// Default constructor.
                invalid_result (void)
                    : std::exception (), err_("Something unknown went wrong.")
                {
                    //empty
                }

                /// Constructor with custom message
                invalid_result(std::string err_msg)
                    : std::exception (), err_(err_msg)
                {
                    //empty
                }

                /// Destructor
                ~invalid_result(void) throw()
                {
                    //empty
                }

                virtual const char* what() const throw()
                {
                    return err_.c_str();
                }
            private :
                std::string err_;
        };

        //getters
        std::string get_converted() const;
        int get_output() const;

    private :
        /**
        *   Will convert a given input from infix to postfix
        *   @param[in]      string          the expression to be converted
        *   @return         bool            true if success, false if failed
        */
        bool convert_input(void);

        /**
        *  Will use converted_ to build an expression tree
        *  @return          bool            true if success, false if failed
        */
        bool build_tree(void);

        /**
        *   Will use the Node_Visitor to evaluate the tree
        *   @return         bool            the evaluation of the converted expression
        */
        bool evoke_visitor(void);

        std::string input_;         ///the input string
        int output_;                ///the evaluation of the input
        std::string converted_;     ///the string after it is converted to postfix
        Expr_Tree tree_;            ///the expression tree
        std::string err_;                  ///the encountered error message
};
