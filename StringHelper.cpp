
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include "StringHelper.h"
#include <iostream>

// Ryan: You could actually use the std I/O library functions to complete this for you,
// specifically the use of stringstream and stoi.
// Fixed: stoi does not capture trailing characters where the method that I implemented does.
// And the first method helps to validate input a tiny bit.

Array<std::string> StringHelper::split_string(std::string statement, std::string delim)
{
    //the index at which the delimiter is found
    size_t index;
    //the output string array
    Array<std::string> split;
    //the remaining portion after the string is split
    std::string remainder = statement;
    //the index in the array to place the string
    size_t i = 0;

    //split on the delimiter
    while(remainder.find(delim) != std::string::npos)
    {
        index = remainder.find(delim);

        //append the part before the delimiter to output if it is not empty
        if(index != 0)
        {
            split.set(i, remainder.substr(0, index));
            remainder = remainder.substr(index + 1);
            i++;
        }
        //progress past the empty space
        else
        {
            remainder = remainder.substr(index + 1);
        }
    }
    //get the last token
    split.set(i, remainder);

    return split;
}

bool StringHelper::is_numeric(std::string str)
{
    int test;

    try
    {
        //try using stoi to convert it to a number
        test = std::stoi(str);
    }
    catch (std::invalid_argument)
    {
        return false;
    }

    //stoi does not catch trailing characters this does
    std::string str_test = std::to_string(static_cast<long long>(test));
    if(str.compare(str_test) != 0)
    {
        return false;
    }

    return true;
}
