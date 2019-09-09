
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#include <iostream>
#include <string>

#include "Evaluator.h"

int main()
{
    bool keepGoing = true;  ///while loop sentry
    std::string input;

    Evaluator eval;

    while(keepGoing)
    {
        //the basic text body and input wait
        printf("\nEnter Input or type 'QUIT': \n");
        std::getline(std::cin, input);

        //check if the input was quit
        if(input == "QUIT")
        {
            keepGoing = false;
        }

        //if the input wasn't quit and is not empty try to evaluate it
        else if(input.length() > 0)
        {
            try
            {
                eval.evaluate(input); //line that can throw exception
                std::cout << "\nConverted Input : " << std::endl;
                std::cout << eval.get_converted() << std::endl;
                std::cout << "Evaluated Output :" << std::endl;
                std::cout << eval.get_output() << std::endl;
            }
            catch (Evaluator::invalid_result &error)
            {
                std::cout << error.what() << std::endl;
            }
        }

        //if the input wasn't quit and is empty give an error
        else
        {
            printf("I can't do anything if you enter nothing. Try again. \n\n");
        }
    }

    return 0;
}
