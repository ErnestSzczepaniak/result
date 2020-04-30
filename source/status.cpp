#include "status.h"
#include "string.h"
#include "stdio.h"

Status::Status(bool value, const Location & location)
:
_type(Status_type::BINARY),
_category(value ? "Success" : "Failure"),
_brief(nullptr),
_file(location.file_name()),
_function(location.function_name()),
_line(location.line())
{
    _details[0] = 0;
}

Status::Status(const char * category, const Location & location)
:
_type(Status_type::CUSTOM),
_category(category),
_brief(nullptr),
_file(location.file_name()),
_function(location.function_name()),
_line(location.line())
{
    _details[0] = 0;
}

Status::Status(Status_type type, const char * category, const char * brief, const char * details, const Location & location)
:
_type(type),
_category(category),
_brief(brief),
_file(location.file_name()),
_function(location.function_name()),
_line(location.line())
{
    if (details) snprintf(_details, size_details, "%s", details);
}

Status::~Status()
{

}

const char * Status::type() const
{
    if (_type == Status_type::BINARY) return "Binary";
    else if (_type == Status_type::WARNING) return "Warning";
    else if (_type == Status_type::ERROR) return "Error";
    else if (_type == Status_type::CUSTOM) return "Custom";
    return "Unknown";
}

const char * Status::category() const
{
    return _category ? _category : "Not provided";
}

const char * Status::brief() const
{
    return _brief ? _brief : "Not provided";
}

const char * Status::details() const
{
    return strlen(_details) ? _details : "Not provided";
}

const char * Status::file() const
{
    auto * ptr = (char *) _file;
    ptr += strlen(_file);

    for (int i = 0; i < strlen(_file); i++)
    {
        if (*ptr == '/') return (ptr + 1);
        else ptr--;
    }
    
    return _file;
}

const char * Status::function() const
{
    return _function;
}

int Status::line() const
{
    return _line;
}

bool Status::operator==(bool value)
{
    if (_type == Status_type::BINARY)
    {
        return value ? (strcmp(_category, "Success") == 0) : (strcmp(_category, "Success") != 0);
    }
    else if (_type == Status_type::CUSTOM) return !value;
    else if (_type == Status_type::WARNING) return value;
    else return !value;
}

bool Status::operator==(const Status & other) const
{
    if (_type == other._type)
    {
        return (
            (strcmp(category(), other.category()) == 0) &&
            (strcmp(brief(), other.brief()) == 0)
        );
    }
    else return false;
}

bool Status::operator!=(const Status & other) const
{
    return !this->operator==(other);
}