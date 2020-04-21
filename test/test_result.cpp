#include "test.h"
#include "result.h"

struct Test
{
    int pa[5];
}; /* structure: Test */

Result<Test> s()
{

    
    return error::argument::Address_empty();      
}

TEST_CASE("rw")
{
    auto [status, value] = s();

    printf("Category: [%s], Brief: [%s], Details: [%s], Location: [%s (%d) -> %s()]\n", status.category(), status.brief(), status.details(), status.file(), status.line(), status.function());
}