#include <iostream>
#include "List.h"

int main() {
    try {
        List<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(5);
        list.push_back(3);
        list.push_front(12);
        cout << list;
        List<int> list2;
        list2 = list;
        cout << list2;
        list2.push_back(1);
        list2.push_back(2);
        list2.push_back(5);
        list2.push_back(3);
        list2.push_front(12);
        List<int> list3 = list + list2;
        cout << list3;
        cout << "\n\n" << list.Size() << "\n\n";

        cout << list;
        list.pop_back();
        cout << "\n\n" << list.Size() << "\n\n";

        list.insert(244, 0);
        cout << list;
        list.pop_back();
        cout << list;
        list.push_front(123);
        cout << list;
        list.pop_front();
        cout << list;
    } catch (const char *e){
        cout << e;
    }
    return 0;
}