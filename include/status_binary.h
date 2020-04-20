#ifndef _status_binary_h
#define _status_binary_h

/**
 * @file	status_binary.h
 * @author	en2
 * @date	20-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

/* ---------------------------------------------| Success |--------------------------------------------- */

class Status::Success : public Status{
    /**
     * @class	Status::Success
     * @brief	
     * @details	
    **/
public:
    Success(const char * details = nullptr) : Status("Success", nullptr, details) {}
    template<typename ...T> Success(const char * format, T ... ts) : Status("Success") {_format_details(format, ts...);}
    ~Success() {}

}; /* class: Status::Success */

/* ---------------------------------------------| Failure |--------------------------------------------- */

class Status::Failure : public Status{
    /**
     * @class	Status::Failure
     * @brief	
     * @details	
    **/
public:
    Failure(const char * details = nullptr) : Status("Failure", nullptr, details) {}
    template<typename ...T> Failure(const char * format, T ... ts) : Status("Failure") {_format_details(format, ts...);}
    ~Failure() {}

}; /* class: Status::Success */

#endif /* define: status_binary_h */