#ifndef _result_h
#define _result_h

/*
* project:	result
* file:		result.h
* author:	en2
* date:		18-04-2020
*/

#include "status_memory.h"
#include "status_argument.h"
#include "status_driver.h"

template<typename T>
class Result
{
    /**
     * @class	Result
     * @brief	
     * @details	
    **/
public:
    Result();
    Result(bool value) : status(value) {}
    Result(const char * category) : status(category) {}
    Result(Status status) : status(status) {}
    Result(const Result & other);
    Result(Result && other);
    Result & operator=(const Result & other);
    Result & operator=(Result && other);
    ~Result();

    Status status;
    T value;
}; /* class: Result */

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