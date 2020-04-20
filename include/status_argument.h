#ifndef _status_argument_h
#define _status_argument_h

/**
 * @file	status_argument.h
 * @author	en2
 * @date	20-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

/* ---------------------------------------------| Argument |--------------------------------------------- */

class Status::Argument : public Status
{
    /**
     * @class	Status::Argument
     * @brief	
     * @details	
    **/
public:
    Argument(const char * brief, const char * details = nullptr) : Status("Argument", brief, details) {}
    ~Argument() {}

    class Out_of_range;
    class Invalid;

}; /* class: Status::Argument */

/* ---------------------------------------------| Argument::Out_of_range |--------------------------------------------- */

class Status::Argument::Out_of_range : public Status::Argument
{
    /**
     * @class	Status::Argument::Out_of_range
     * @brief	
     * @details	
    **/
public:
    Out_of_range(const char * details = nullptr) : Status::Argument("Out of range", details) {}
    template<typename ... T> Out_of_range(const char * format, T ... ts) : Status::Argument("Out of range") {_format_custom_details(format, ts...);}
    ~Out_of_range() {}
};

/* ---------------------------------------------| Argument::Invalid |--------------------------------------------- */

class Status::Argument::Invalid : public Status::Argument
{
    /**
     * @class	Status::Argument::Invalid
     * @brief	
     * @details	
    **/
public:
    Invalid(const char * details = nullptr) : Status::Argument("Invalid", details) {}
    template<typename ... T> Invalid(const char * format, T ... ts) : Status::Argument("Invalid") {_format_custom_details(format, ts...);}
    ~Invalid() {}
};

#endif /* define: status_argument_h */