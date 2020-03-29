//
// Created by Sophia Shuvar on 30.03.20.
//

#ifndef SPARSEMATRIX_UNITTESTS_H
#define SPARSEMATRIX_UNITTESTS_H

#endif //SPARSEMATRIX_UNITTESTS_H

#include "Matrix.h"
using namespace std;

class UnitTests{
public:
    void TestreadMatrix(){
        Matrix <int>m1;
        m1.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        assert(m1.toString() == "12 0 0 6 \n"
                                "567 0 8 9 \n"
                                "4 5 6 0 \n"
                                "46 7 0 8 \n"
                                "0 8 9 9 \n");
    }

    void Testadd(){
        Matrix <int>m1;
        m1.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        m1.add(1, 1, 0);
        m1.add(1, 0, 0);
        assert(m1.toString() == "1 1 0 6 \n"
                                "567 0 8 9 \n"
                                "4 5 6 0 \n"
                                "46 7 0 8 \n"
                                "0 8 9 9 \n");
    }

    void Testremove(){
        Matrix <int>m1;
        m1.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        m1.remove(0, 0);
        m1.remove(1, 0);
        assert(m1.toString() == "0 0 0 6 \n"
                                "567 0 8 9 \n"
                                "4 5 6 0 \n"
                                "46 7 0 8 \n"
                                "0 8 9 9 \n");
    }

    void Testplus(){
        Matrix <int>m1, m2, m3;
        m1.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        m2.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        m1.add(1, 1, 0);
        m1.add(67, 3, 0);
        m3 = m1 + m2;
        assert(m3.toString() == "24 1 0 73 \n"
                                "1134 0 16 18 \n"
                                "8 10 12 0 \n"
                                "92 14 0 16 \n"
                                "0 16 18 18 \n");
    }

    void Testminus(){
        Matrix <int>m1, m2, m3;
        m1.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        m2.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        m1.add(1, 1, 0);
        m1.add(67, 3, 0);
        m3 = m1 - m2;
        assert(m3.toString() == "0 1 0 61 \n"
                                "0 0 0 0 \n"
                                "0 0 0 0 \n"
                                "0 0 0 0 \n"
                                "0 0 0 0 \n");
    }

    void Testmultiplie1(){
        Matrix <int>m1, m2;
        m1.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
        m2 = m1*5;
        assert(m2.toString() == "60 0 0 30 \n"
                                "2835 0 40 45 \n"
                                "20 25 30 0 \n"
                                "230 35 0 40 \n"
                                "0 40 45 45 \n");
    }

};