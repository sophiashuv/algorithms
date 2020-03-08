//
// Created by Sophia Shuvar on 03.03.20.
//

#ifndef STLSTACK2_0_UNITTESTS_H
#define STLSTACK2_0_UNITTESTS_H

#endif //STLSTACK2_0_UNITTESTS_H
#include <cassert>
#include <assert.h>
#include <string>
#include "polska_n.h"

using namespace std;

class UnitTests{
public:

    void testinfixToPrefix2(){
        vector<string> new_v{ "-356", "2", "4", "/", "*" };
        assert(infixToPrefix2("(-356) * (2 / 4)") == new_v);
    }

    void testCalculateTheExpression(){
        vector<string> new_v{ "-356", "2", "4", "/", "*" };
        assert(CalculateTheExpression(new_v) == -178);
    }

    void testcounter(){
        assert(counter('+', 8, 75) == 83);
    }

    void testisOperator1(){
        assert(isOperator('+'));
    }

    void testisOperator2(){
        assert(isOperator("+"));
    }

    void testgetpriority(){
        assert(getPriority('^') == 3);
    }

};