#include "hello.h"
#include "suite_hello.h"

void hello_case1() {
    CU_ASSERT(say_hello() == 42);
    CU_ASSERT(1 == 1);
    CU_ASSERT_TRUE(1);
}

CU_ErrorCode add_suite_hello(CU_pSuite pSuite) {
    pSuite = CU_add_suite("suite_hello", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "hello case1", hello_case1)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CUE_SUCCESS;
}

