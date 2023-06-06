/*!
 * \file
 * \brief test additional protection test
 * \attention optional test case
 */

#include "rt-test/assert.h"
#include "user/user.h"

void test(int prot) {
    void *ptr = mmap(0, 4096, prot, MAP_PRIVATE | MAP_ANONYMOUS);
    assert(ptr && ptr != (void*) MAP_FAILED);
    assert(!munmap(ptr, 4096));
}

void main() {
    test(PROT_EXEC);
    test(PROT_READ | PROT_WRITE | PROT_EXEC);
    test(PROT_READ);
    test(PROT_READ | PROT_EXEC);
    test(PROT_NONE);
}
