
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "InToPostFix.h"
#include <iostream>

std::string InToPostFix::convert(std::string &statement)
{
    //current operators: 7
    const std::string operators[] = {"(", ")", "*", "/", "%", "+", "-"};
    const int num_of_operators = 7;

    //the output string
    std::string out;

    //the stack to order the operators
    Stack<std::string> opstack;

    //the array to store the split string
    Array<std::string> split = StringHelper::split_string(statement, " ");

    int is_operator = -1;

    std::string term;

    //setting up the stack from the split string
    for(Array<std::string>::Iterator iter = split.begin(); iter != split.end(); iter++)
    {
        is_operator = -1;

        term = *iter;

        //for each operator
        for(size_t j = 0; j < num_of_operators; j++)
        {
            //check to see if the token is an operator
            if(term.compare(operators[j]) == 0)
            {
                is_operator = j;
            }
        }

        //if the token is an operator
        if(is_operator != -1)
        {
            //if the operator is a closing parenthesis
            if(is_operator == 1)
            {

                //pop the opstack till the open parenthesis stops being a coward and reveals himself
                while(opstack.top().compare("(") != 0 && !opstack.is_empty())
                {
                    out.append(opstack.top() + " ");
                    opstack.pop();
                }
                //the opening parenthesis was never found throw invalid
                if(opstack.is_empty())
                {
                    throw invalid_expression();
                }
                //remove the opening parenthesis from the opstack
                opstack.pop();

            }

            //the operator is an opening parenthesis
            else if(is_operator == 0)
            {
                opstack.push("(");
            } // END the top of the stack is an opening parenthesis

            //the operator is not a parenthesis
            else
            {
                bool keepGoing = true;
                bool parenthesis = false;
                int top_of_opstack_precedence;

                //check precedence rules
                while(keepGoing)
                {
                    //find the precedence of the top of the opstack
                    for(size_t i = 0; i < num_of_operators; i++)
                    {
                        if(opstack.top().compare(operators[i]) == 0)
                        {
                            if(i > 1)
                            {
                                parenthesis = false;
                                top_of_opstack_precedence = i;
                            }
                            else
                            {
                                parenthesis = true;
                            }
                        }
                    }

                    //if precedence of the top of the stack is higher or equal than the current operator pop the stack and append it to the output
                    if(top_of_opstack_precedence <= is_operator && !opstack.is_empty() && !parenthesis)
                    {
                        out.append(opstack.top() + " ");
                        opstack.pop();
                    }
                    //if of the top of the stack is of lower or equal precedence then exit this loop
                    else
                    {
                        keepGoing = false;
                    }
                }

                // finally push the new operator onto the stack
                opstack.push(term);

            } //END if the token is an operator that is not a parenthesis

        } //END if the split[i] is an operator

        //else the token is an operand add it to the output string if it is numeric
        else
        {
            //check that the stack top is a valid numeric operand
            if(!StringHelper::is_numeric(term))
            {
                throw invalid_expression();
            }
            //if it is append it to the output
            else
            {
                out.append(term + " ");
            }

        } //END if split[i] is an operand

    } // END for each element of split

    //empty the opstack when the stack is empty
    while(!opstack.is_empty())
    {

        //if there is an opening parenthesis at this point there was no matching closing parenthesis throw an error
        if(opstack.top().compare("(") == 0)
        {
            throw invalid_expression();
        }

        //else empty the opstack onto the output
        else
        {
            //the print method will not print % as by default % is used by the print method
            //use it to indicate a substitution. To escape the typical behavior %% must be used
            //instead of just %.
            if(opstack.top().compare("%") == 0)
            {
                out.append(opstack.top() + opstack.top() + " ");
                opstack.pop();
            }
            else
            {
                out.append(opstack.top() + " ");
                opstack.pop();
            }
        }
    }

    //this algorithm will add an extra " " at the end of the string that will affect
    //later algorithms if left alone so remove that.
    out = out.substr(0, out.length() - 1);

    return out;
}
