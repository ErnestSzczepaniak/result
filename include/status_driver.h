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

/* ---------------------------------------------| Driver |--------------------------------------------- */

class Status::Driver : public Status
{
    /**
     * @class	Status::Driver
     * @brief	
     * @details	
    **/
public:
    Driver(const char * brief, const char * details, const Location & location) : Status("Driver", brief, details, location) {}
    ~Driver() {}

    class Open_error;
    class Close_error;
    class Read_error;
    class Write_error;
    class Timeout;
    class Failure;
    class Busy;

}; /* class: Status::Driver */

/* ---------------------------------------------| Driver::Open_error |--------------------------------------------- */

class Status::Driver::Open_error : public Status::Driver
{
    /**
     * @class	Status::Driver::Open_error
     * @brief	
     * @details	
    **/
public:
    Open_error(const char * details = nullptr, const Location & location = Location::current())
        : Status::Driver("Open error", details, location) {}
    ~Open_error() {}
};

/* ---------------------------------------------| Driver::Close_error |--------------------------------------------- */

class Status::Driver::Close_error : public Status::Driver
{
    /**
     * @class	Status::Driver::Close_error
     * @brief	
     * @details	
    **/
public:
    Close_error(const char * details = nullptr, const Location & location = Location::current())
        : Status::Driver("Close error", details, location) {}
    ~Close_error() {}
};

/* ---------------------------------------------| Driver::Read_error |--------------------------------------------- */

class Status::Driver::Read_error : public Status::Driver
{
    /**
     * @class	Status::Driver::Read_error
     * @brief	
     * @details	
    **/
public:
    Read_error(const char * details = nullptr, const Location & location = Location::current())
        : Status::Driver("Read error", details, location) {}
    ~Read_error() {}
};

/* ---------------------------------------------| Driver::Write_error |--------------------------------------------- */

class Status::Driver::Write_error : public Status::Driver
{
    /**
     * @class	Status::Driver::Write_error
     * @brief	
     * @details	
    **/
public:
    Write_error(const char * details = nullptr, const Location & location = Location::current())
        : Status::Driver("Write error", details, location) {}
    ~Write_error() {}
};

/* ---------------------------------------------| Driver::Timeout |--------------------------------------------- */

class Status::Driver::Timeout : public Status::Driver
{
    /**
     * @class	Status::Driver::Timeout
     * @brief	
     * @details	
    **/
public:
    Timeout(const char * details = nullptr, const Location & location = Location::current())
        : Status::Driver("Timeout", details, location) {}
    ~Timeout() {}
};

/* ---------------------------------------------| Driver::Failure |--------------------------------------------- */

class Status::Driver::Failure : public Status::Driver
{
    /**
     * @class	Status::Driver::Failure
     * @brief	
     * @details	
    **/
public:
    Failure(const char * details = nullptr, const Location & location = Location::current())
        : Status::Driver("Failure", details, location) {}
    ~Failure() {}
};

/* ---------------------------------------------| Driver::Busy |--------------------------------------------- */

class Status::Driver::Busy : public Status::Driver
{
    /**
     * @class	Status::Driver::Busy
     * @brief	
     * @details	
    **/
public:
    Busy(const char * details = nullptr, const Location & location = Location::current())
        : Status::Driver("Busy", details, location) {}
    ~Busy() {}
};

#endif /* define: status_driver_h */