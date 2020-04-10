#include <iostream>
#include "UnitTests.h"
using  namespace std;


int main() {
//    PriorityQueue<int> p;
////    p.insert(134, 2);
////    p.insert(135, 2);
////    p.insert(136, 1);
////    p.insert(131, 1);
////    p.insert(134, 2);
////    p.insert(135, 2);
////    p.insert(136, 1);
////    p.insert(137, 3);
////    cout << p.toString();
////    cout << p.Size() << "\n";
////    //p.clear();
////    p.pop();
////    p.pop();
////    p.pop();
////    p.pop();
////    p.pop();
////    cout << p;

    UnitTests test;
    test.testQueueInsert();
    test.testQueuePop();
    test.testQueueTop();
    test.testQueueEmpty1();
    test.testQueueEmpty2();
    test.testQueueClear();
    test.testQueueSize();
    return 0;
}