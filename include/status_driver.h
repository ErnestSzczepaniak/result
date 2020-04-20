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
    Driver(const char * brief, const char * details = nullptr) : Status("Driver", brief, details) {}
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
    Open_error(const char * details = nullptr) : Status::Driver("Open error", details) {}
    template<typename ... T> Open_error(const char * format, T ... ts) : Status::Driver("Open error") {_format_custom_details(format, ts...);}
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
    Close_error(const char * details = nullptr) : Status::Driver("Close error", details) {}
    template<typename ... T> Close_error(const char * format, T ... ts) : Status::Driver("Close error") {_format_custom_details(format, ts...);}
    ~Close_error() {}
};

/* ---------------------------------------------| Driver::Read_error |--------------------------------------------- */

class Status::Driver::Read_error : public Status::Driver
{
    /**
     * @class	Status::Driver:Read_error
     * @brief	
     * @details	
    **/
public:
    Read_error(const char * details = nullptr) : Status::Driver("Read error", details) {}
    template<typename ... T> Read_error(const char * format, T ... ts) : Status::Driver("Read error") {_format_custom_details(format, ts...);}
    ~Read_error() {}
};

/* ---------------------------------------------| Driver::Write_error |--------------------------------------------- */

class Status::Driver::Write_error : public Status::Driver
{
    /**
     * @class	Status::Driver:Write_error
     * @brief	
     * @details	
    **/
public:
    Write_error(const char * details = nullptr) : Status::Driver("Write error", details) {}
    template<typename ... T> Write_error(const char * format, T ... ts) : Status::Driver("Write error") {_format_custom_details(format, ts...);}
    ~Write_error() {}
};

/* ---------------------------------------------| Driver::Timeout |--------------------------------------------- */

class Status::Driver::Timeout : public Status::Driver
{
    /**
     * @class	Status::Driver:Timeout
     * @brief	
     * @details	
    **/
public:
    Timeout(const char * details = nullptr) : Status::Driver("Timeout", details) {}
    template<typename ... T> Timeout(const char * format, T ... ts) : Status::Driver("Timeout") {_format_custom_details(format, ts...);}
    ~Timeout() {}
};

/* ---------------------------------------------| Driver::Failure |--------------------------------------------- */

class Status::Driver::Failure : public Status::Driver
{
    /**
     * @class	Status::Driver:Failure
     * @brief	
     * @details	
    **/
public:
    Failure(const char * details = nullptr) : Status::Driver("Failure", details) {}
    template<typename ... T> Failure(const char * format, T ... ts) : Status::Driver("Failure") {_format_custom_details(format, ts...);}
    ~Failure() {}
};

/* ---------------------------------------------| Driver::Busy |--------------------------------------------- */

class Status::Driver::Busy : public Status::Driver
{
    /**
     * @class	Status::Driver:Busy
     * @brief	
     * @details	
    **/
public:
    Busy(const char * details = nullptr) : Status::Driver("Busy", details) {}
    template<typename ... T> Busy(const char * format, T ... ts) : Status::Driver("Busy") {_format_custom_details(format, ts...);}
    ~Busy() {}
};

#endif /* define: status_driver_h */