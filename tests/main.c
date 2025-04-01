#include <string.h>
#include "CUnit/Basic.h"

#include "suite_hello.h"

int main(void) {
    CU_pSuite pSuite = NULL;
    if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

    add_suite_hello(pSuite);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
