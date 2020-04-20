#include "test.h"
#include "result.h"
#include "status_memory.h"

struct Test
{
    int pa[5];
}; /* structure: Test */




Result<Test> s()
{

    return Memory::Low();
}

TEST_CASE("rw")
{
    auto [status, value] = s();



    printf("Category: [%s], Brief: [%s], Details: [%s], Message: [%s], Location: [%s (%d) -> %s()]\n", status.category(), status.brief(), status.details(), status.message(), status.file(), status.line(), status.function());


}


