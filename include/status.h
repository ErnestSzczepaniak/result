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

enum class Status_type : unsigned char 
{
    BINARY,
    WARNING,
    ERROR,
}; /* enum: Status_type */

class Status
{
    static constexpr auto size_details = 64;

public:
    Status(bool value = true, const Location & location = Location::current());
    Status(Status_type type, const char * category, const char * brief = nullptr, const char * details = nullptr, const Location & location = Location::current());
    ~Status();

    const char * type() const;
    const char * category() const;
    const char * brief() const;
    const char * details() const;
    const char * file() const;
    const char * function() const;
    int line() const;

    template<typename ...T>
    Status & details(const char * format, T ... ts);

    bool operator==(bool value);
    bool operator==(const Status & other) const;
    bool operator!=(const Status & other) const;

private:
    Status_type _type;

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

#define STR_(X) #X
#define STR(X) STR_(X)

#define _l0_class(TYPE, CATEGORY) class CATEGORY : public Status                                       \
{                                                                                                      \
public:                                                                                                \
    CATEGORY(const char * details = nullptr, const Location & location = Location::current())          \
    : Status(TYPE, STR(CATEGORY), nullptr, details, location) {}                                    \
    ~CATEGORY() {}                                                                                     \
}


/* ---------------------------------------------| info |--------------------------------------------- */

#define _l1_class(TYPE, CATEGORY, BRIEF) class BRIEF : public Status                                   \
{                                                                                                      \
public:                                                                                                \
    BRIEF(const char * details = nullptr, const Location & location = Location::current())             \
    : Status(TYPE, STR(CATEGORY), STR(BRIEF), details, location) {}                              \
    ~BRIEF() {}                                                                                        \
}

/* ---------------------------------------------| info |--------------------------------------------- */

namespace status::binary
{

_l0_class(Status_type::BINARY, Success);
_l0_class(Status_type::BINARY, Failure);

}; /* namespace: status */

namespace status::warning::possible
{

_l1_class(Status_type::WARNING, Possible, Data_corruption);
_l1_class(Status_type::WARNING, Possible, Data_loss);
_l1_class(Status_type::WARNING, Possible, Value_empty);

}; /* namespace: warning::return */

namespace status::warning::performed
{

_l1_class(Status_type::WARNING, Performed, Truncation);
_l1_class(Status_type::WARNING, Performed, Narrowing);
_l1_class(Status_type::WARNING, Performed, Reorder);
_l1_class(Status_type::WARNING, Performed, Aliasing);

}; /* namespace: warning::return */

namespace status::warning::memory
{

_l1_class(Status_type::WARNING, Memory, Low);

}; /* namespace: status::warning::memory */


namespace status::error::memory
{

_l1_class(Status_type::ERROR, Memory, Access_violation);
_l1_class(Status_type::ERROR, Memory, Alignment_violation);
_l1_class(Status_type::ERROR, Memory, Not_enought);
_l1_class(Status_type::ERROR, Memory, Leak);
_l1_class(Status_type::ERROR, Memory, Corruption);
_l1_class(Status_type::ERROR, Memory, Overflow);

}; /* namespace: status::memory */

namespace status::error::driver
{

_l1_class(Status_type::ERROR, Driver, Open);
_l1_class(Status_type::ERROR, Driver, Close);
_l1_class(Status_type::ERROR, Driver, Write);
_l1_class(Status_type::ERROR, Driver, Read);
_l1_class(Status_type::ERROR, Driver, Timeout);
_l1_class(Status_type::ERROR, Driver, Failure);
_l1_class(Status_type::ERROR, Driver, Busy);
_l1_class(Status_type::ERROR, Driver, Bad_configuration);
_l1_class(Status_type::ERROR, Driver, Restart_needed);
_l1_class(Status_type::ERROR, Driver, Not_present);
_l1_class(Status_type::ERROR, Driver, Not_responding);
_l1_class(Status_type::ERROR, Driver, Hardware_fault);

}; /* namespace: error::driver */

namespace status::error::argument
{

_l1_class(Status_type::ERROR, Argument, Size_mismatch);
_l1_class(Status_type::ERROR, Argument, Type_mismatch);
_l1_class(Status_type::ERROR, Argument, Address_unaligned);
_l1_class(Status_type::ERROR, Argument, Address_empty);
_l1_class(Status_type::ERROR, Argument, Out_of_range);

}; /* namespace: error::argument */

namespace status::error::frame
{

_l1_class(Status_type::ERROR, Frame, Id_mismatch);
_l1_class(Status_type::ERROR, Frame, Id_unknown);
_l1_class(Status_type::ERROR, Frame, Length_mismatch);
_l1_class(Status_type::ERROR, Frame, Crc_mismatch);

}; /* namespace: error::frame */

#endif /* define: status_h */