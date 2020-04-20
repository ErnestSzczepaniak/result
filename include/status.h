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
    static constexpr auto size_details = 64;

public:
    Status(bool value, const Location & location = Location::current());
    Status(const char * category = nullptr, const char * brief = nullptr, const char * details = nullptr, const Location & location = Location::current());
    ~Status();

    const char * category() const;
    const char * brief() const;
    const char * details() const;
    const char * file() const;
    const char * function() const;
    int line() const;

    template<typename ...T>
    Status & details(const char * format, T ... ts);

    operator bool() const;   
    bool operator==(bool value);
    bool operator==(const Status & other) const;

private:
    const char * _category;
    const char * _brief;
    char _details[size_details];
    const char * _file;
    const char * _function;
    int _line;

}; /* class: Status */

template<typename ...T>
Status & Status::details(const char * format, T ... ts)
{
    snprintf(_details, size_details, format, ts ...);

    return *this;
}

/* ---------------------------------------------| info |--------------------------------------------- */

#define STRING(x) #x
#define status_class(CATEGORY, BRIEF) class BRIEF : public Status                           \
{                                                                                           \
public:                                                                                     \
    BRIEF(const char * details = nullptr, const Location & location = Location::current())  \
    : Status(STRING(CATEGORY), STRING(BRIEF), details, location) {}                         \
    ~BRIEF() {}                                                                             \
}

#endif /* define: status_h */