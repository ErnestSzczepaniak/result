#include "test.h"
#include "result.h"

Result<int> f()
{
    Result<int> result;

    return Status::Memory::Unaligned_access("Not in word boundary");
}


Status s()
{

    return Status::Driver::Timeout();

    return Status::Driver::Open_error();

    return Status::Memory::Leak();

    return Status::Memory::Unaligned_access("asd %d", 20);
}

TEST_CASE("rw")
{
    auto status = s();

    printf("Category: [%s], Brief: [%s], Details: [%s]\n", status.category(), status.brief(), status.details());


}


