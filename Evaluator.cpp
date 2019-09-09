
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "Evaluator.h"

//
///  Evaluator
//
Evaluator::Evaluator() :
    input_(""), output_(0), converted_(""), tree_()
{
    //empty
}

//
///  destructor
//
Evaluator::~Evaluator()
{
    //empty
}

//
///  evaluate
//
int Evaluator::evaluate(std::string input)
{
    input_ = input;

    //attempt to convert the input
    if(convert_input())
    {
        //attempt to build the tree
        if(build_tree())
        {
            //attempt to evaluate the tree using the visitor
            if(evoke_visitor())
            {
                return output_;
            }
            else
            {
                throw invalid_result(err_);
            }
        }
        else
        {
            throw invalid_result(err_);
        }
    }
    else
    {
        throw invalid_result(err_);
    }
    return 0;
}

//
/// convert_input
//
bool Evaluator::convert_input(void)
{
    try
    {
        converted_ = InToPostFix::convert(input_);
    }
    catch (InToPostFix::invalid_expression)
    {
        err_ = "\nCould not convert to postfix.\n";
        return false;
    }
    return true;
}

//
/// build_tree
//
bool Evaluator::build_tree(void)
{
    Array<std::string> arr;             ///an array of the terms gathered from the string
    Postfix_Exp_Tree_Builder builder;   ///the builder that will build the tree

    //split the string on the ' ' delimiter
    arr = StringHelper::split_string(converted_, " ");

    //the build commands are all capable of throwing the Postfix_Exp_Tree_Builder::invalid_expression
    //exception so wrap this in a try loop and return false if that exception is hit
    try
    {
        //for each term in the input string add a node to the tree in reverse order
        for(Array<std::string>::Iterator iter = arr.end()--; iter != arr.begin()--; iter--)
        {
            std::string term = *iter;

            if(term.compare("*") == 0)
            {
                builder.build_mult_node();
            }
            else if(term.compare("/") == 0)
            {
                builder.build_div_node();
            }
            else if(term.compare("%%") == 0)
            {
                builder.build_mod_node();
            }
            else if(term.compare("+") == 0)
            {
                builder.build_add_node();
            }
            else if(term.compare("-") == 0)
            {
                builder.build_sub_node();
            }
            //if not an operator it must be numeric
            else
            {
                builder.build_num_node(term);
            }
        } ///END FOR ALL TERMS
    }
    catch (Postfix_Exp_Tree_Builder::invalid_expression)
    {
        err_ = "\nCould not build the tree.\n";
        return false;
    }

    //regardless of pass or failure set the root_ so that the tree will be deleted
    tree_.set_root(builder.get_tree());

    return true;
}

//
/// evoke_visitor
//
bool Evaluator::evoke_visitor(void)
{
    //give the root to a node_visitor
    Node_Visitor visitor(tree_.get_root());

    try
    {
        //evaluate the tree from the root
        visitor.eval();
    }
    catch (Division_Node::divide_by_zero)
    {
        err_ = "\nDivision by zero error. Try again.\n";
        return false;
    }
    catch (Modulus_Node::mod_by_zero)
    {
        err_ = "\nModulus by zero error. Try again.\n";
        return false;
    }
    catch (Visitor::visitor_result_invalid)
    {
        err_ = "\nEvaluation failed. Try again.\n";
        return false;
    }

    output_ = visitor.get_result();

    return true;
}

std::string Evaluator::get_converted() const
{
    return converted_;
}

int Evaluator::get_output() const
{
    return output_;
}
