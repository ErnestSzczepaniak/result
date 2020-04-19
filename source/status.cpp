#include "status.h"
#include "string.h"

Status::Status()
:
_category(nullptr),
_brief(nullptr)
{
    _details[0] = 0;
}

Status::Status(const char * category, const char * brief)
:
_category(category),
_brief(brief)
{
    _details[0] = 0;
}

Status::~Status()
{

}

const char * Status::category() const
{
    return _brief ? _brief : "No category provided";
}

const char * Status::brief() const
{
    return _brief ? _brief : "No brief provided";
}

const char * Status::details() const
{
    return strlen(_details) ? _details : "No details provided";
}

bool Status::operator==(const Status & other)
{
    return (
        (strcmp(category(), other.category()) == 0) &&
        (strcmp(brief(), other.brief()) == 0)
        );
}

Status::operator bool()
{
    return (_category == nullptr);
}