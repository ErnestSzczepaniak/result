#ifndef _status_driver_h
#define _status_driver_h

/**
 * @file	status_driver.h
 * @author	en2
 * @date	20-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

namespace status::driver
{

/* ---------------------------------------------| info |--------------------------------------------- */

class Open_error : public Status
{
public:
    Open_error(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Open_error", details, location) {}
    ~Open_error() {}
}; /* Open_error:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Close_error : public Status
{
public:
    Close_error(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Close_error", details, location) {}
    ~Close_error() {}
}; /* Close_error:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Read_error : public Status
{
public:
    Read_error(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Read_error", details, location) {}
    ~Read_error() {}
}; /* Read_error:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Write_error : public Status
{
public:
    Write_error(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Write_error", details, location) {}
    ~Write_error() {}
}; /* Close_error:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Timeout : public Status
{
public:
    Timeout(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Timeout", details, location) {}
    ~Timeout() {}
}; /* Close_error:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Failure : public Status
{
public:
    Failure(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Failure", details, location) {}
    ~Failure() {}
}; /* Close_error:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Busy : public Status
{
public:
    Busy(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Driver", "Busy", details, location) {}
    ~Busy() {}
}; /* Close_error:  */

}; /* namespace: error::driver */

#endif /* define: error_driver_h */