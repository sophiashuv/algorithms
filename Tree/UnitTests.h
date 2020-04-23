//
// Created by Sophia Shuvar on 23.04.20.
//

#ifndef TREE_UNITTESTS_H
#define TREE_UNITTESTS_H

#endif //TREE_UNITTESTS_H
#pragma once
#include <cassert>
#include <assert.h>
#include "Tree.h"

using namespace std;

class UnitTests{
public:

    void test1(){
        Tree tree(5);
        tree.addElement(3);
        tree.addElement(4);
        tree.addElement(1);
        tree.addElement(0);
        tree.addElement(10);
        tree.addElement(8);
        assert(tree.isElement(4));
    }

    void test2(){
        Tree tree(5);
        tree.addElement(3);
        tree.addElement(4);
        tree.addElement(1);
        tree.addElement(0);
        tree.addElement(10);
        tree.addElement(8);
        assert(!tree.isElement(95));
    }

    void test3(){
        Tree tree(5);
        tree.addElement(3);
        tree.addElement(4);
        tree.addElement(1);
        tree.addElement(0);
        tree.addElement(10);
        tree.addElement(8);
        assert(tree.isElement(8));
    }

    void test4(){
        Tree tree(5);
        tree.addElement(3);
        tree.addElement(4);
        tree.addElement(1);
        tree.addElement(0);
        tree.addElement(10);
        tree.addElement(8);
        vector<Node*> vector;
        tree.RAB(tree.getRoot() ,vector);
        assert(tree.getRoot() == vector[0]);
    }
};