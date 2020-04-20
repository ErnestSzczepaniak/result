#include "test.h"
#include "result.h"


Status s()
{

}

TEST_CASE("rw")
{
    auto status = s();


    printf("Category: [%s], Brief: [%s], Details: [%s], Message: [%s], Location: [%s (%d) -> %s()]\n", status.category(), status.brief(), status.details(), status.message(), status.file(), status.line(), status.function());


}


