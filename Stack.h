// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _STACK_H_
#define _STACK_H_

#include <exception>
#include "Array.h"

// Ryan: You should use aggregation rather than inheritance here.
// Fixed: Aggregation used

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Stack
{
public:
  /// Type definition of the type.
  typedef T type;

    // Ryan: How would the Stack become full with our Array?
    // Fixed: array now resizes itself as needed

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    virtual const char* what() const throw()
    {
        return "An attempt to pop from an empty stack was made.";
    }
  };

  /// Default constructor.
  Stack (void);

  /// Copy constructor.
  Stack (const Stack & s);

  /// Destructor.
  ~Stack (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Stack & operator = (const Stack & rhs);

  /**
   * Push a new \a element onto the stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push (T element);

  /**
   * The equivalence operator.
   * @param[in]      rhs          The stack to which this instance is to be compared.
   * @return         boolean      True if the stacks are equivalent. False otherwise.
   */
  bool operator == (const Stack & rhs) const;

  /**
   * The negation of the equivalence operator.
   * @param[in]      rhs          The stack to which this instance is to be compared.
   * @return         boolean      True if the stacks are  not equivalent. False otherwise.
   */
  bool operator != (const Stack & rhs) const;

  /**
   * Remove the top-most element from the stack.
   *
   * @exception      empty_exception    The stack is empty.
   */
  void pop (void);

  /**
   * Get the top-most element on the stack. If there are no element
   * on the stack, then the stack_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The stack is empty
   */
  T top (void) const;

  /**
   * Test if the stack is empty
   *
   * @retval         true          The stack is empty
   * @retval         false         The stack is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the stack.
   *
   * @return         Size of the stack.
   */
  size_t size (void) const;

  /**
   * The maximum size of the stack. (should never be hit as the array
   * class automatically resizes itself when it hits the maximum.)
   *
   */
  size_t max_size () const;

  /// Remove all elements from the stack.
  void clear (void);

protected:
  Array<T> arr;

private:

  size_t top_;

};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif   // !defined _STACK_H_
