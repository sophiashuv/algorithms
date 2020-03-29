#include "Matrix.h"
#include "UnitTests.h"
#include <chrono>
#include <iostream>
#include <fstream>


int main() {
    UnitTests test;
    test.TestreadMatrix();
    test.Testadd();
    test.Testremove();
    test.Testplus();
    test.Testminus();
    test.Testmultiplie1();
//    Matrix<string> matrix, matrix2, matrix3, matrix4;
//    matrix.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m1");
//    matrix2.readMatrix("/Users/sophiyca/ClionProjects/SparseMatrix/m2");
//    matrix.Print();
//    cout << "____________________" << endl;
//    matrix2.Print();
//    cout << "__________________" << endl;
//
//    matrix3 = matrix + matrix2;
//    matrix3.Print();
//    matrix4.add("9", 3, 4);
//    matrix4.add("7", 4, 4);
//    matrix4.add("6", 0, 0);
//    matrix4.remove(1, 4);
//    cout << "__________________" << endl;
//    matrix4.Print();
//    system("pause");
    return 0;
}