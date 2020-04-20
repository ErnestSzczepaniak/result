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

namespace status::argument
{

/* ---------------------------------------------| info |--------------------------------------------- */

class Invalid : public Status
{
public:
    Invalid(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Invalid", details, location) {}
    ~Invalid() {}
}; /* Invalid: */

/* ---------------------------------------------| info |--------------------------------------------- */

class Out_of_range : public Status
{
public:
    Out_of_range(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Out_of_range", details, location) {}
    ~Out_of_range() {}
}; /* Out_of_range: */

}; /* namespace: status::argument */

#endif /* define: status_argument_h */