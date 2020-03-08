#include <iostream>

#include "UnitTests.h"

int main() {
    string s1 = "(-356) * (2 / 4)";
    vector<string> res = infixToPrefix2(s1);
    cout << s1 << " = " <<  CalculateTheExpression(res) << " = ";
    showsvector(res);


    UnitTests k;
    k.testinfixToPrefix2();
    k.testCalculateTheExpression();
    k.testcounter();
    k.testisOperator1();
    k.testisOperator2();
    return 0;
}