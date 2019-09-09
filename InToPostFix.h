
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _IN_TO_POSTFIX_
#define _IN_TO_POSTFIX_

#include "Stack.h"
#include <string>
#include "Array.h"
#include "StringHelper.h"

class InToPostFix
{
    public :

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

        /**
        * Convert the given string to a postfix string.
        * @param[in]            statement           The string to be converted
        * @return                                   The converted string
        */
        static std::string convert(std::string &statement);
};

#endif // _IN_TO_POSTFIX_

