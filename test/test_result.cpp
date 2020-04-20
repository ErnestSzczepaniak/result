#include "test.h"
#include "result.h"

struct Test
{
    int pa[5];
}; /* structure: Test */



Result<Test> s()
{

    return status::driver::Busy("asdw");
    return status::memory::Low();
}

#include "t.h"

TEST_CASE("rw")
{
    auto [status, value] = s();

    h();

    printf("Category: [%s], Brief: [%s], Details: [%s], Location: [%s (%d) -> %s()]\n", status.category(), status.brief(), status.details(), status.file(), status.line(), status.function());


}


    class Invalid;
    class Out_of_range;