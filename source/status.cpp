#include "status.h"
#include "string.h"

Status::Status(bool value, const Location & location)
:
_category(value ? "Success" : "Failure"),
_brief(nullptr),
_file(location.file_name()),
_function(location.function_name()),
_line(location.line())
{
    _details[0] = 0;
}

Status::Status(const char * category, const char * brief, const char * details, const Location & location)
:
_category(category),
_brief(brief),
_file(location.file_name()),
_function(location.function_name()),
_line(location.line())
{
    if (details) memcpy(_details, details, strlen(details));
}

Status::~Status()
{

}

const char * Status::category() const
{
    return _category;
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
    return basename(_file);
}

const char * Status::function() const
{
    return _function;
}

int Status::line() const
{
    return _line;
}

Status::operator bool() const
{
    return (strcmp(_category, "Success") == 0);
}

bool Status::operator==(bool value)
{
    return value ? (strcmp(_category, "Success") == 0) : (strcmp(_category, "Success") != 0);
}

bool Status::operator==(const Status & other) const
{
    return (
        (strcmp(_category, other._category) == 0) &&
        (strcmp(brief(), other.brief()) == 0)
        );
}