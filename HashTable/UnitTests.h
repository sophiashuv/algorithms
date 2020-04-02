//
// Created by Sophia Shuvar on 02.04.20.
//

#ifndef HASHTABLE_UNITTESTS_H
#define HASHTABLE_UNITTESTS_H

#endif //HASHTABLE_UNITTESTS_H
#include <cassert>
#include <assert.h>
#include <string>
#include "HashTable.h"

using namespace std;

class UnitTests{
public:

    void test_Insert(){
        HashTable h;
        h.Insert(123);
        h.Insert(111);
        h.Insert(33);
        h.Insert(34);
        h.Insert(7);
        h.Insert(3);
        h.Insert(897);
        h.Insert(99);
        assert(h.toStringTable() == "3: 111->3->\n"
                                    "6: 123->33->\n"
                                    "7: 34->7->\n"
                                    "18: 99->\n"
                                    "24: 897->\n");
    }

    void test_Remove(){
        HashTable h;
        h.Insert(123);
        h.Insert(111);
        h.Insert(33);
        h.Insert(34);
        h.Insert(7);
        h.Insert(3);
        h.Insert(897);
        h.Insert(99);
        try {
            h.Remove(7);
        } catch (const  char* &e) {
            cout << e;
        }
        assert(h.toStringTable() == "3: 111->3->\n"
                                    "6: 123->33->\n"
                                    "18: 99->\n"
                                    "24: 897->\n");
    }

    void test_Search() {
        HashTable h;
        h.Insert(123);
        h.Insert(111);
        h.Insert(33);
        h.Insert(34);
        h.Insert(7);
        h.Insert(3);
        h.Insert(897);
        h.Insert(99);
        try {
            assert(h.toStringNode(h.Search(7)) == "34->7->");
        } catch (const char *&e) {
            cout << e;
        }
    }

};