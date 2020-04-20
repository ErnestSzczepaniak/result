#ifndef _status_h
#define _status_h

/**
 * @file	status.h
 * @author	en2
 * @date	19-04-2020
 * @brief	
 * @details	
**/

#include <experimental/source_location>
using Location = std::experimental::source_location;

class Status
{
    /**
     * @class	Status
     * @brief	
     * @details	
    **/
   static constexpr auto size_message = 64;

public:
    Status();
    Status(bool value, const Location & location = Location::current());
    Status(const char * category, const char * brief = nullptr, const char * details = nullptr, const Location & location = Location::current());
    ~Status();

    const char * category() const;
    const char * brief() const;
    const char * details() const;
    const char * file() const;
    const char * function() const;
    int line() const;
    const char * message() const;

    template<typename ...T>
    Status message(const char * format, T ... ts);

    operator bool() const;   
    bool operator==(bool value);
    bool operator==(const Status & other) const;

private:
    const char * _category;
    const char * _brief;
    const char * _details;
    const char * _file;
    const char * _function;
    int _line;

    char _message[size_message];

}; /* class: Status */

template<typename ...T>
Status Status::message(const char * format, T ... ts)
{
    snprintf(_message, size_message, format, ts ...);

    return *this;
}

#endif /* define: status_h */