#include "test.h"
#include "result.h"

Result<int> f()
{

    return Status::Memory::Unaligned_access("invalid %d", 2);
}


TEST_CASE("rw")
{
    auto [status, value] = f();


    if (status == true)
    {
        int k = 2;
    }
    else 
    {
        int k = 3;
    }

    //else printf("Category: [%s], Brief: [%s], Details: [%s]\n", status.category(), status.brief(), status.details());
}


