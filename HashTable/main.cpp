#include <iostream>
#include "HashTable.h"
#include "UnitTests.h"
using namespace std;

int main(){
    UnitTests test;
    test.test_Insert();
    test.test_Remove();
    test.test_Search();
}
