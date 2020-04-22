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
    
    const Location & _location;

}; /* class: Status */

template<typename ...T>
Status & Status::details(const char * format, T ... ts)
{
    snprintf(_details, size_details, format, ts ...);

    return *this;
}

/* ---------------------------------------------| info |--------------------------------------------- */

#define STRING(x) #x
#define status_class(CATEGORY, BRIEF) class BRIEF : public Status                                       \
{                                                                                                       \
public:                                                                                                 \
    BRIEF(const char * details = nullptr, const Location & location = Location::current())              \
    : Status(STRING(CATEGORY), STRING(BRIEF), details, location) {}                                     \
    ~BRIEF() {}                                                                                         \
}

/* ---------------------------------------------| info |--------------------------------------------- */

namespace error::memory
{

status_class(Memory, Access_violation);
status_class(Memory, Alignment_violation);
status_class(Memory, Low);
status_class(Memory, Not_enought);
status_class(Memory, Leak);
status_class(Memory, Corruption);
status_class(Memory, Overflow);

}; /* namespace: status::memory */

namespace error::driver
{

status_class(Driver, Open);
status_class(Driver, Close);
status_class(Driver, Write);
status_class(Driver, Read);
status_class(Driver, Timeout);
status_class(Driver, Failure);
status_class(Driver, Busy);
status_class(Driver, Bad_configuration);
status_class(Driver, Restart_needed);
status_class(Driver, Not_present);
status_class(Driver, Not_responding);
status_class(Driver, Hardware_fault);

}; /* namespace: error::driver */

namespace error::argument
{

status_class(Argument, Size_mismatch);
status_class(Argument, Type_mismatch);
status_class(Argument, Address_unaligned);
status_class(Argument, Address_empty);
status_class(Argument, Out_of_range);

}; /* namespace: status::argument */

namespace error::frame
{

status_class(Frame, Id_mismatch);
status_class(Frame, Id_unknown);
status_class(Frame, Length_mismatch);
status_class(Frame, Crc_mismatch);

}; /* namespace: error::frame */


#endif /* define: status_h */