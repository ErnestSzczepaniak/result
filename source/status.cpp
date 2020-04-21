#include "status.h"
#include "string.h"
#include "stdio.h"

Status::Status(bool value, const Location & location)
:
_category(value ? "Success" : "Failure"),
_brief(nullptr),
_location(location)
{
    _details[0] = 0;
}

Status::Status(const char * category, const char * brief, const char * details, const Location & location)
:
_category(category),
_brief(brief),
_location(location)
{
    if (details) snprintf(_details, size_details, "%s", details);
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
    return basename(_location.file_name());
}

const char * Status::function() const
{
    return _location.function_name();
}

int Status::line() const
{
    return _location.line();
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