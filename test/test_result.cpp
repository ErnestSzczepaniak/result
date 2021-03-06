#include "test.h"
#include "result.h"

struct Test
{
    int pa[5];
}; /* structure: Test */

Result<Test> s()
{

    //return status::binary::Failure();
    return status::warning::possible::Data_loss().details("%d", 12);
}

TEST_CASE("rw")
{
    auto [status, value] = s();

    if (status == true)
    {
        printf("true\n");
    }

    printf("Type: [%s], Category: [%s], Brief: [%s], Details: [%s], Location: [%s (%d) -> %s()]\n", status.type(), status.category(), status.brief(), status.details(), status.file(), status.line(), status.function());
}