#include <iostream>
#include "UnitTests.h"

int main() {
    UnitTests test;
    test.TestConstructors();
    test.TestCount();
    test.TestSet();
    test.TestReset();
    test.TestFlip();
    test.TestLogical();
    test.TestTo_ulong();
    test.TestOverloaded();
    return 0;
}