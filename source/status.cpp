#include "status.h"
#include "string.h"

Status::Status()
:
_category(nullptr),
_brief(nullptr),
_details(nullptr)
{

}

Status::Status(bool value)
:
_category(value ? "Success" : "Failure"),
_brief(nullptr),
_details(nullptr)
{

}

Status::Status(const char * category, const char * brief, const char * details)
:
_category(category),
_brief(brief),
_details(details)
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
    if (_details) return _details;
    else if (strlen(_custom_details)) return _custom_details;
    else return "Not provided";
}

bool Status::operator==(const Status & other) const
{
    return (
        (strcmp(category(), other.category()) == 0) &&
        (strcmp(brief(), other.brief()) == 0)
        );
}

Status::operator bool() const
{
    return ((strcmp(category(), "Success") == 0));
}