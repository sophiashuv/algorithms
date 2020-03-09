#include <iostream>
#include "UnitTests.h"

using namespace std;


int main() {
    UnitTests uni;
    uni.TestList();
    uni.TestVector();

    cout << "List:\n";
    Table <List>t;
    t.push_back(11);
    t.push_back(13);
    t.push_back(61);
    t.push_back(12);
    t.push_back(18);
    t.push_back(68);
    t.push_back(21);
    t.insert(91, 0);
    cout << t;

    cout << "\nvectorClass:\n";
    Table <vectorClass>m;
    m.push_back(11);
    m.push_back(13);
    m.push_back(61);
    m.push_back(12);
    m.push_back(18);
    m.push_back(68);
    m.push_back(21);
    m.insert(91, 0);
    cout << m;

    return 0;
}