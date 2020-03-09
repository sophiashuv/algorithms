//
// Created by Sophia Shuvar on 09.03.20.
//

#ifndef TABLE_UNITTESTS_H
#define TABLE_UNITTESTS_H

#endif //TABLE_UNITTESTS_H
#include <cassert>
#include <assert.h>
#include <string>
#include "Table.h"
#include "List.h"
#include "Vector.h"

using namespace std;

class UnitTests{
public:

    void TestVector(){
        Table <vectorClass>m;
        m.push_back(11);
        m.push_back(13);
        m.push_back(61);
        m.push_back(12);
        m.push_back(18);
        m.push_back(68);
        m.push_back(21);
        m.insert(91, 0);
        int k = m.get(1, 1);
        assert(k == 61);
    }

    void TestList(){
        Table <List>m;
        m.push_back(11);
        m.push_back(13);
        m.push_back(61);
        m.push_back(12);
        m.push_back(18);
        m.push_back(68);
        m.push_back(21);
        m.insert(91, 0);
        int k = m.get(1, 1);
        assert(k == 11);
    }

};