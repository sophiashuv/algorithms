//
// Created by Sophia Shuvar on 23.02.20.
//

#ifndef STACK_UNITTESTS_H
#define STACK_UNITTESTS_H
#pragma once
#endif //STACK_UNITTESTS_H
#include "Stack.h"
#include <cassert>
#include <assert.h>


class UnitTests{
public:
    void testStackEmpty1(){
        StackOnArray<int> stack;
        assert(stack.isEmpty());
    }

    void TestStackEmpty2(){
        StackOnArray<int> stack;
        stack.push(2);
        stack.pop();
        assert(stack.isEmpty());
    }

    void TestStackEmpty3(){
        StackOnArray<int> stack;
        stack.push(2);
        assert(!stack.isEmpty());
    }

    void TestStackPush1(){
        StackOnArray<int> stack;
        stack.push(6);
        stack.push(3);
        int res1 = stack.pop();
        assert(res1 == 3);
    }

    bool TestStackPush2(){
        StackOnArray<int> stack;
        stack.push(6);
        stack.push(3);
        stack.pop();
        int res2 = stack.pop();
        assert(res2 == 6);
    }

    void TestSize(){
        StackOnArray<int> stack;
        for (int i = 0; i < 18; i++) stack.push(1);
        int res = stack.getSize();
        assert(res == 27);
    }

//    void TestToString(){
//        StackOnArray<int> stack;
//        for (int i = 0; i < 18; i++) stack.push(i);
//        string res = stack.toString();
//        cout << res;
//    }


};