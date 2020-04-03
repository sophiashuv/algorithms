//
// Created by Sophia Shuvar on 03.04.20.
//

#ifndef MARKOV_ALGORITHM_LONGLOOPEXCEPTION_H
#define MARKOV_ALGORITHM_LONGLOOPEXCEPTION_H

#endif //MARKOV_ALGORITHM_LONGLOOPEXCEPTION_H
#include <iostream>
#pragma once

using namespace std;
class LongLoopException{
private :
    int type;
    string code;

public:
    LongLoopException(): type(0), code(""){}

    LongLoopException(int _type, string _code): type(_type), code(_code){}

    void show() const{
        cout << "Looping type " << type << " on rule: " + code + "\n";
    }
};
