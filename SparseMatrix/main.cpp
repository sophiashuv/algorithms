#include "Matrix.h"
#include "UnitTests.h"
#include <iostream>
#include <fstream>


int main() {
    UnitTests test;
    test.TestreadMatrix();
    test.Testadd();
    test.Testremove();
    test.Testplus();
    test.Testminus();
    test.Testmultiplie1();
    test.Testmultiplie2();
    system("pause");
    return 0;
}
