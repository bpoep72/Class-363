
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe


#ifdef _BASE_ARRAY_H_

#include "Base_Array.h"
#include <stdexcept>        // for std::out_of_bounds exception
#include <memory>           // for std::unique_ptr
#define DEFAULT_SIZE 20

//
// Default constructor
//
template <typename T>
Base_Array<T>::Base_Array(void) :
    data_(new T[DEFAULT_SIZE]{}), max_size_(DEFAULT_SIZE)
{
    fill(T{});
}

//
// Sizable Constructor
//
template <typename T>
Base_Array<T>::Base_Array(size_t length) :
    data_ (new T[length]{}), max_size_(length)
{
    fill(T{});
}

//
// Sizable Fill
//
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill_item) :
    data_ (new T[length]{}), max_size_(length)
{
    fill(fill_item);
}

//
// Copy Constructor
//
template <typename T>
Base_Array<T>::Base_Array(const Base_Array &array) :
    data_ (new T[array.max_size()]{}), max_size_(array.max_size())
{
    fill(T{});

    //copy all old contents
    for(size_t i = 0; i < max_size_; i++) {
        set(i, array.get(i));
    }
}

//
// Destructor
//
template <typename T>
Base_Array<T>::~Base_Array(void)
{
    //data_.reset();
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    //self comparison
   if(*this == rhs) {
        return *this;
    }

    //if the arrays are different sizes
    if(rhs.max_size() != max_size_)
    {
        //copy constraints
        max_size_ = rhs.max_size();

        //data_ resize
        data_.reset(new T[max_size_]{});
    }


    //copy the contents of rhs up to max_size_
    for(size_t i = 0; i < max_size_; i++) {
        this->set(i, rhs.get(i));
    }

    //return the new address
    return *this;
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    //check index right bound, raises out of bound exception
    if(index >= max_size_) {
        throw std::out_of_range("An attempt was made to get an index outside the range of the array.");
    }
    //if the index is within the bounds
    else {
        //return the data at the index
        return data_[index];
    }
}

//
// operator []
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    return get(index);
}

//
// find (T)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    return find(value, 0);
}

//
// find (T, size_t)
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    //check that the start is not greater than
    if(start > this->max_size_) {
        throw std::out_of_range("Start parameter in find(value, start) cannot be greater than maximum size.");
    }

    //for each element (i) starting with element "start" in "data_" check if that element matches "val"
    for(size_t i = start; i < this->max_size_; i++) {
        //if the element (i) matches ch return the index i
        if(this->get(i) == val) {
            return i;
        }
    }

    //element not found in data_ return -1
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    //check that rhs is not this
	if(this == &rhs) {
        return true;
    }

    //if both arrays have the same size
    if(this->max_size_ == rhs.max_size_) {
        //compare index by index
        for(size_t i = 0; i < this->max_size_; i++) {
            if(this->get(i) != rhs.get(i)) {
                return false;
            }
        }
    }
    //if they are not the same size they are not equal
    else {
        return false;
    }

    return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    //return the negation of == operator
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    for(size_t i = 0; i < max_size_; i++) {
        data_[i] = value;
    }
}

//
// Get
//
template <typename T>
T Base_Array<T>::get (size_t index) const
{
    //check index right bound, raises out of bound exception
    if(index >= max_size_) {
        throw std::out_of_range("An attempt was made to get an index outside the range of the array.");
    }

    //if the index is within the bounds
    else {
        return data_[index];
    }
}

//
//  Set
//
template <typename T>
void Base_Array<T>::set (size_t index, T value)
{
    //check index right bounds, raises out of bound exception if both are exceeded
    if(index >= max_size_) {
        throw std::out_of_range("An attempt was made to set an index outside of the array.");
    }

    //if the index checks didn't throw an exception then the address is fine
    data_[index] = value;
}

//
//  begin
//
template <typename T>
typename Base_Array<T>::Iterator Base_Array<T>::begin()
{
    return Iterator(Base_Array<T>::data_.get());
}

//
//  end
//
template <typename T>
typename Base_Array<T>::Iterator Base_Array<T>::end()
{
    return Iterator(Base_Array<T>::data_.get() + max_size_);
}

#endif // _BASE_ARRAY_H_
