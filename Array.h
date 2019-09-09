// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>        // for size_t definition
#include "Base_Array.h"   // parent of the array
#include <memory>
#include <math.h> //for ceil method in resize

// Ryan: Here a better approach would be to inherit from a Base Array class
// as our Array is a bit too dynamic for serving as the base for our Fixed
// Array class.
// Fixed: added base class base_array

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Base_Array<T>
{
    public:
        /// Type definition of the element type.
        typedef T type;

        /// Default constructor.
        Array (void);

        /**
        * Initializing constructor.
        *
        * @param[in]      length        Initial size
        */
        Array (size_t length);

        /**
        * Initializing constructor.
        *
        * @param[in]      length        Initial size
        * @param[in]      fill          Initial value for each element
        */
        Array (size_t length, T fill);

        /**
        * Copy constructor
        *
        * @param[in]     arr         The source array.
        */
        Array (const Array & arr);

        /// Destructor.
        ~Array (void);

        /**
        * Set a new size for the array. If \a new_size is less than the current
        * size, then the array is truncated. If \a new_size if greater then the
        * current size, then the array is made larger and the new elements are
        * not initialized to anything. If \a new_size is the same as the current
        * size, then nothing happens.
        *
        * The array's original contents are preserved regardless of whether the
        * array's size is either increased or decreased.
        *
        * @param[in]       new_size              New size of the array
        */
        void resize (size_t new_size);

        /**
        * Retrieve the current size of the array.
        *
        * @return          The current size
        */
        size_t size (void) const;

        /**
        * Overload parent to account for cur_size_
        * Get the character at the specified index. If the \a index is not within
        * the range of the array, then std::out_of_range exception is thrown.
        *
        * @param[in]       index                 Zero-based location
        * @return          Character at \index
        * @exception       std::out_of_range     Invalid index value
        */
        T get (size_t index) const;

        /**
        * Overload parent to account for cur_size_
        * Set the character at the specified \a index. If the \a index is not
        * within range of the array, then std::out_of_range exception is
        * thrown.
        *
        * @param[in]       index                 Zero-based location
        * @param[in]       value                 New value for character
        * @exception       std::out_of_range     Invalid \a index value
        */
        void set (size_t index, T value);

        /**
        * Get the T at the specified index. If the index is not
        * within the range of the array, then std::out_of_range exception
        * is thrown.
        *
        * @param[in]       index               Zero-based location
        * @exception       std::out_of_range   Invalid \a index value
        */
        T & operator [] (size_t index);

        /**
        * @overload
        *
        * The returned T is not modifiable.
        */
        const T & operator [] (size_t index) const;

        const Array<T> & operator = (const Array & rhs);

        /**
        * Fill the contents of the array.
        *
        * @param[in]       ch                   Fill character
        */
        void fill(T fill_item);

        typename Base_Array<T>::Iterator end();

    private:
        //the amount of the max size that is currently in use
        size_t cur_size_;

};  ///END ARRAY CLASS

#include "Array.inl"    //templates are weird
#include "Array.cpp"    //templates are weird

#endif   // if !defined _ARRAY_H_
