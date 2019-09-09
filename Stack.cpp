// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifdef _STACK_H_

//
// Stack
//
template <typename T>
Stack<T>::Stack (void) :
    arr(Array<T>{}), top_(0)
{
    //empty
}

//
// Stack
//
template <typename T>
Stack<T>::Stack (const Stack & stack) :
    arr(Array<T>(stack.arr)), top_(stack.size())
{
    //empty
}

//
// ~Stack
//std::cout << stk.top() << std::endl;
template <typename T>
Stack <T>::~Stack (void)
{
    //as the memory management is done by the base class nothing needed here
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    //set the open space to be element
    arr.set(top_, element);
    //increment top_
    top_++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    //check that there is an item in the stack
    if(top_ > 0)
    {
        //default the deleted element
        arr.set(top_, T{});
        //decrement top_
        top_--;
    }
    else
    {
        throw empty_exception();
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //check for self comparison
    if(*this == rhs)
    {
        return *this;
    }
    else
    {
        top_ = rhs.size();

        arr = Array<T>(rhs.arr);

        return *this;
    }
}

//
// operator ==
//
template <typename T>
bool Stack<T>::operator == (const Stack & rhs) const
{
    if(arr == rhs.arr && this->size() == rhs.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//
// operator !=
//
template <typename T>
bool Stack<T>::operator != (const Stack & rhs) const
{
    return !(*this == rhs);
}


//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    //default the whole array
    arr.fill( T{} );
    //set top_ to 0
    top_ = 0;
}

#endif

