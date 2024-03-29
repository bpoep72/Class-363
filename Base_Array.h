
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring>        // for size_t definition
#include <stdexcept>        // for std::out_of_bounds exception
#include <memory>           // for std::unique_ptr

/**
 * @class Base_Array
 *
 * Basic array implementation for Array and Fixed Array
 */

template <typename T>
class Base_Array {

    public:
        typedef T type;

        /**
        * Default constructor
        */
        Base_Array(void);

        /**
        * Sizable constructor
        * @param[in]        length              the desired length of the array
        */
        Base_Array(size_t length);

        /**
        * Sizable fill constructor
        * @param[in]        length              the desired length of the array
        * @param[in]        fill_item           the value to fill the array with
        */
        Base_Array(size_t length, T fill_item);

        /**
        * Copy constructor
        * @param[in]        array               the array to be copied
        */
        Base_Array(const Base_Array &array);

        /**
        * Destructor
        */
        ~Base_Array(void);

        /**
        * Assignment operation
        *
        * @param[in]       rhs              Right-hand side of equal sign
        * @return          Reference to self
        */
        const Base_Array & operator = (const Base_Array & rhs);

        /**
        * Retrieve the maximum size of the array.
        *
        * @return          The maximum size
        */
        size_t max_size (void) const;

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

        /**
        * Locate the specified T in the array. The index of the first
        * occurrence of the T is returned. If the T is not
        * found in the array, then -1 is returned.
        *
        * @param[in]        ch        Character to search for
        * @return           Index value of the T
        * @retval           -1        Character not found
        */
        int find (T element) const;

        /**
        * @overload
        *
        * This version allows you to specify the start index of the search. If
        * the start index is not within the range of the array, then the
        * std::out_of_range exception is thrown.
        *
        * @param[in]       ch                   Character to search for
        * @param[in]       start                Index to begin search
        * @return          Index value of first occurrence
        * @retval          -1                   Character not found
        * @exception       std::out_of_range    Invalid index
        */
        int find (T element, size_t start) const;

        /**
        * Test the array for equality.
        *
        * @param[in]       rhs                  Right hand side of equal to sign
        * @retval          true                 Left side is equal to right side
        * @retval          false                Left side is not equal to right side
        */
        bool operator == (const Base_Array & rhs) const;

        /**
        * Test the array for inequality.
        *
        * @param[in]       rhs                  Right-hand size of not equal to sign
        * @retval          true                 Left side is not equal to right side
        * @retval          false                Left size is equal to right side
        */
        bool operator != (const Base_Array & rhs) const;

        /**
        * Fill the contents of the array.
        *
        * @param[in]       ch                   Fill T
        */
        void fill (T element);

        /**
        * Get the T at the specified index. If the \a index is not within
        * the range of the array, then std::out_of_range exception is thrown.
        *
        * @param[in]       index                 Zero-based location
        * @return          Character at \index
        * @exception       std::out_of_range     Invalid index value
        */
        T get (size_t index) const;

        /**
        * Set the T at the specified \a index. If the \a index is not
        * within range of the array, then std::out_of_range exception is
        * thrown.
        *
        * @param[in]       index                 Zero-based location
        * @param[in]       value                 New value for T
        * @exception       std::out_of_range     Invalid \a index value
        */
        void set (size_t index, T value);

        /**
        *   @class Iterator
        *   The inner class iterator allows for the construction and use of
        *   iterator style transversal upon the array class.
        */
        class Iterator
        {
            public :
                Iterator(T *ptr) :
                    ptr_(ptr)
                { }

                Iterator operator++(void)
                {
                    ptr_++;
                    return *this;
                }

                Iterator operator++(int junk)
                {
                    ptr_++;
                    return *this;
                }

                Iterator operator--(void)
                {
                    ptr_--;
                    return *this;
                }

                Iterator operator--(int junk)
                {
                    ptr_--;
                    return *this;
                }

                const T& operator*(void)
                {
                    return *ptr_;
                }

                const T* operator->(void)
                {
                    return ptr_;
                }

                bool operator==(const Iterator& rhs)
                {
                    return ptr_ == rhs.ptr_;
                }

                bool operator!=(const Iterator& rhs)
                {
                    return ptr_ != rhs.ptr_;
                }

            private :
                T* ptr_;

        }; ///END ITERATOR CLASS

        /**
        *   Returns an iterator pointing to the first element of the array
        */
        Iterator begin(void);

        /**
        *   Returns an iterator pointing to the element past the end of the array
        */
        Iterator end(void);

    protected:
        /// Pointer to the actual data.
        std::unique_ptr<T[]> data_;

        /// Maximum size of the array.
        size_t max_size_;

};

#include "Base_Array.inl"
#include "Base_Array.cpp"


#endif // _BASE_ARRAY_H_
