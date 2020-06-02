#ifndef _result_h
#define _result_h

/**
 * @file	result.h
 * @author	en2
 * @date	19-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

template<typename T>
class alignas(4) Result
{
public:
    Result(bool value);
    Result(const Status & status);
    Result(const Status & status, const T & value);

    Result();
    Result(const Result & other);
    Result(Result && other);
    Result & operator=(const Result & other);
    Result & operator=(Result && other);
    ~Result();

    [[gnu::aligned(4)]] Status status;
    [[gnu::aligned(4)]] T value;
    
}; /* class: Result */

template<typename T> 
Result<T>::Result(bool value) : status(value)
{

}

template<typename T> 
Result<T>::Result(const Status & status) : status(status)
{

}

template<typename T> 
Result<T>::Result(const Status & status, const T & value) : status(status), value(value)
{

}

template<typename T> 
Result<T>::Result() : status(true)
{

}

template<typename T> 
Result<T>::Result(const Result<T> & other) : status(other.status), value(other.value)
{

}

template<typename T> 
Result<T>::Result(Result<T> && other) : status(other.status), value(other.value)
{

}

template<typename T> 
Result<T>::~Result()
{
    
}

template<typename T> 
Result<T> & Result<T>::operator=(const Result<T> & other)
{
    status = other.status;
    value = other.value;

    return *this;
}

template<typename T> 
Result<T> & Result<T>::operator=(Result<T> && other)
{
    status = other.status;
    value = other.value;

    return *this;
}

#endif /* define: result_h */