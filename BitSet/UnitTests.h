//
// Created by Sophia Shuvar on 15.05.20.
//

#ifndef BITSET_UNITTESTS_H
#define BITSET_UNITTESTS_H

#endif //BITSET_UNITTESTS_H


#include "BitSet.h"
#include <bitset>
using namespace std;

class UnitTests{
public:
    void TestConstructors(){
        BitSet<8> b1("01011"); BitSet<8> b2(87893); BitSet<8> b3(b2);
        bitset<8> n1("01011"); BitSet<8> n2(87893); BitSet<8> n3(n2);
        assert(b1.to_string() == n1.to_string());
        assert(b2.to_string() == n2.to_string());
        assert(b3.to_string() == n3.to_string());
    }

    void TestCount(){
        BitSet<8> b1("01011");
        BitSet<8> b2("11111111");
        assert(b1.count() == 3);
        assert(b2.count() == 8);
    }

    void TestSet(){
        BitSet<8> b1("01011");
        BitSet<8> b2("00000000");
        assert(b1.Set().to_string() == "11111111");
        assert(b2.Set(3).to_string() == "00010000");
    }

    void TestReset(){
        BitSet<8> b1("01011");
        BitSet<8> b2("11111111");
        assert(b1.reset().to_string() == "00000000");
        assert(b2.reset(3).to_string() == "11101111");
    }

    void TestFlip(){
        BitSet<8> b1("01011");
        BitSet<8> b2("11111111");
        assert(b1.flip().to_string() == "11110100");
        assert(b2.flip(3).to_string() == "11101111");
    }

    void TestLogical(){
        BitSet<8> b1("01011");
        BitSet<8> b2("11111111");
        assert(b1.all() == 0);
        assert(b2.all() == 1);
        assert(b1.any() == 1);
        assert(b2.any() == 1);
        assert(b1.none() == 0);
        assert(b2.none() == 0);
    }

    void TestTo_ulong(){
        BitSet<8> b1("01011");
        BitSet<8> b2("11111111");
        BitSet<3> b3("101");
        assert(b1.to_ulong() == 11);
        assert(b2.to_ulong() == 255);
        assert(b3.to_ulong() == 5);
    }

    void TestOverloaded(){
        BitSet<8> b1("01011");
        BitSet<8> b2("11111111");
        assert(b1 != b2);
        b1&=b2;
        assert(b1.to_string() == "00001011");
        b1|=b2;
        assert(b1.to_string() == "11111111");
        b1^=b2;
        assert(b1.to_string() == "00000000");
        b1|=b2;
        assert(b1.to_string() == "11111111");
        ~b1;
        assert(b1.to_string() == "11111111");
    }
};