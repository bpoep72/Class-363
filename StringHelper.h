
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _STRING_HELPER_
#define _STRING_HELPER_

#include <string>
#include "Array.h"

class StringHelper
{
    public :
        /**
        * Split a string based on the delimiter.
        * @param[in]            statement           The string to be split
        * @param[in]            delim               The delimiter to use
        * @return                                   An Array of template string containing the split strings at each index
        */
        static Array<std::string> split_string(std::string statement, std::string delim);

        /**
        * Check that the input str is numeric.
        * @param[in]            str                 The string to be inspected
        * @return               bool                A boolean true if the str is numeric, false otherwise
        */
        static bool is_numeric(std::string str);

};

#endif // _STRING_HELPER_
