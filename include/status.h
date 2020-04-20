#ifndef _status_h
#define _status_h

/**
 * @file	status.h
 * @author	en2
 * @date	19-04-2020
 * @brief	
 * @details	
**/

class Status
{
    /**
     * @class	Status
     * @brief	
     * @details	
    **/

   static constexpr auto size_custom_details = 64;

public:
    Status();
    Status(bool value);
    Status(const char * category, const char * brief = nullptr, const char * details = nullptr);
    ~Status();

    const char * category() const;
    const char * brief() const;
    const char * details() const;

    operator bool() const;   
    bool operator==(const Status & other) const;

    class Success;
    class Failure;
    class Memory;
    class Driver;
    class Argument;

protected:
    template<typename ...T>
    void _format_custom_details(const char * format, T ... ts);

private:
    const char * _category;
    const char * _brief;
    const char * _details;

    char _custom_details[size_custom_details];

}; /* class: Status */

template<typename ...T>
void Status::_format_custom_details(const char * format, T ... ts)
{
    snprintf(_custom_details, size_custom_details, format, ts...);
}

#include "status_binary.h"
#include "status_memory.h"
#include "status_driver.h"

#endif /* define: status_h */