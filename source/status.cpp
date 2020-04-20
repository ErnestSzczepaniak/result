#include "status.h"
#include "string.h"

Status::Status()
:
_category("Success"),
_brief(nullptr),
_details(nullptr),
_file(nullptr),
_function(nullptr),
_line(0)
{

}

Status::Status(bool value, const Location & location)
:
_category(value ? "Success" : "Failure"),
_brief(nullptr),
_details(nullptr),
_file(location.file_name()),
_function(location.function_name()),
_line(location.line())
{

}

Status::Status(const char * category, const char * brief, const char * details, const Location & location)
:
_category(category),
_brief(brief),
_details(details),
_file(location.file_name()),
_function(location.function_name()),
_line(location.line())
{
    
}

Status::~Status()
{

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
    return _details ? _details : "Not provided";
}

const char * Status::file() const
{
    return _file ? basename(_file) : "Not provided";
}

const char * Status::function() const
{
    return _function ? _function : "Not provided";
}

int Status::line() const
{
    return _line;
}

const char * Status::message() const
{
    return strlen(_message) ? _message : "Not provided";
}

Status::operator bool() const
{
    return ((strcmp(category(), "Success") == 0));
}

bool Status::operator==(bool value)
{
    return value ? ((strcmp(category(), "Success") == 0)) : false;
}

bool Status::operator==(const Status & other) const
{
    return (
        (strcmp(category(), other.category()) == 0) &&
        (strcmp(brief(), other.brief()) == 0)
        );
}