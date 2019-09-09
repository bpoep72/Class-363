
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bmpoeppe

#ifdef _ARRAY_H_
#define RESIZE_MULTIPLIER 1.25 //the percent larger that the array needs to be after resize is called

#include "Array.h"

//
// Array
//
template <typename T>
Array<T>::Array (void) :
    Base_Array<T>(DEFAULT_SIZE), cur_size_(0)
{
    //empty
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length) :
    Base_Array<T>(length), cur_size_(0)
{
    //empty
}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill) :
    Base_Array<T>(length), cur_size_(0)
{
    this.fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array) :
    Base_Array<T>(array), cur_size_(array.size())
{
    //empty
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    //data management is done by the parent class
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    //check that new_size is greater than 0
    if(new_size <= 0) {
        throw std::out_of_range("Resize parameter new_size must be greater than 0");
    }

    //if the new_size isn't equal to the max size
    if(new_size != this->max_size_)
    {
        //move the old pointer to temp
        std::unique_ptr<T[]> temp = std::move(this->data_);
        //reset data_ to a new array of new_size
        this->data_.reset(new T[new_size]{});
        //fill it with the default init'ed T's
        this->fill(T{});
        //set max_size_
        this->max_size_ = new_size;

        //migrate all temp to data_
        for(size_t i = 0; i < cur_size_; i++) {
            set(i, temp[i]);
        }
    }
}

//
// get
//
template <typename T>
T Array<T>::get (size_t index) const
{
    //check index right bound, raises out of bound exception
        //Note: size_t checks the left bound by being an unsigned int
    if(index > cur_size_) {
        throw std::out_of_range("An attempt was made to get an index outside the range of the array.");
    }

    //if the index is within the bounds
    else {
        return Base_Array<T>::get(index);
    }
}

//
// [] operator
//
template <typename T>
T& Array<T>::operator [] (size_t index)
{
    T &out = Base_Array<T>::operator[](index);

    if(index > cur_size_)
    {
        cur_size_ = index;
    }

    return out;
}

//
// const [] operator
//
template <typename T>
const T& Array<T>::operator [] (size_t index) const
{
    T &out = Base_Array<T>::operator[](index);

    if(index > cur_size_)
    {
        cur_size_ = index;
    }

    return out;
}

//
// set
//
template <typename T>
void Array<T>::set (size_t index, T value)
{
    //resize if needed
    if(index >= this->max_size())
    {
        size_t new_size = (size_t)ceil(this->max_size() * RESIZE_MULTIPLIER);
        this->resize(new_size);
        Base_Array<T>::set(index, value);
    }
    else
    {
        Base_Array<T>::set(index, value);
    }

    //adjust current size if the last access moved further into the array than previously
    if(index + 1 > cur_size_)
    {
        cur_size_ = index + 1;
    }
}

//
// fill
//
template <typename T>
void Array<T>::fill(T fill_item)
{
    //the cur_size_ needs to be set to the maximum to indicate the array was filled
    cur_size_ = this->max_size();

    Base_Array<T>::fill(fill_item);
}

//
// operator =
//
template <typename T>
const Array<T>& Array<T>::operator = (const Array& rhs)
{
    cur_size_ = rhs.size();

    Base_Array<T>::operator=(rhs);

    return *this;
}


template <typename T>
typename Base_Array<T>::Iterator Array<T>::end()
{
    //the data that is being pointed to at end + 1 of the array class's current range
    T* ptr = Base_Array<T>::data_.get() + Array<T>::cur_size_;
    //return the proper iterator to the end of the array
    return typename Base_Array<T>::Iterator(ptr);
}


#endif
