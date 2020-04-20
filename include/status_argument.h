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

class Argument : public Status
{
    /**
     * @class	Status::Argument
     * @brief	
     * @details	
    **/
public:
    Argument(const char * brief, const char * details, const Location & location) : Status("Argument", brief, details, location) {}
    ~Argument() {}

    class Invalid;
    class Out_of_range;

}; /* class: Status::Argument */

/* ---------------------------------------------| Argument::Invalid |--------------------------------------------- */

class Argument::Invalid : public Argument
{
    /**
     * @class	Status::Argument::Invalid
     * @brief	
     * @details	
    **/
public:
    Invalid(const char * details = nullptr, const Location & location = Location::current())
        : Argument("Invalid", details, location) {}
    ~Invalid() {}
};

/* ---------------------------------------------| Argument::Out_of_range |--------------------------------------------- */

class Argument::Out_of_range : public Argument
{
    /**
     * @class	Status::Argument::Out_of_range
     * @brief	
     * @details	
    **/
public:
    Out_of_range(const char * details = nullptr, const Location & location = Location::current())
        : Argument("Out of range", details, location) {}
    ~Out_of_range() {}
};

#endif /* define: status_argument_h */