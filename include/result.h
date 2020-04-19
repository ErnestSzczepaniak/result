#ifndef _result_h
#define _result_h

/*
* project:	result
* file:		result.h
* author:	en2
* date:		18-04-2020
*/

#include "status.h"

template<typename T>
class alignas(4) Result
{
    /**
     * @class	Result
     * @brief	
     * @details	
    **/

public:
    Result();
    Result(Status status) : status(status) {}
    Result(const Result & other);
    Result(Result && other);
    Result & operator=(const Result & other);
    Result & operator=(Result && other);
    ~Result();

    [[gnu::aligned(4)]] Status status;
    [[gnu::aligned(4)]] T value;
}; /* class: Result */

template<typename T> 
Result<T>::Result()
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