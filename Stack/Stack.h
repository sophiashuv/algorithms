//
// Created by Sophia Shuvar on 18.02.20.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#endif //STACK_STACK_H
#include<iostream>

using namespace std;

#pragma once


template <typename T>

class StackOnArray
{
private:
    T *arr;
    int size;
    int count;
public:
    StackOnArray() : size(17), count(0), arr(new T[size]) {};

    void push(T value) {
        if (size == count) {
            T *tempArr = new T[size];
            for (size_t i = 0; i < size; i++) tempArr[i] = arr[i];
            size += 10;
            arr = new T[size];
            for (size_t i = 0; i < count; i++) arr[i] = tempArr[i];
        }
        arr[count] = value;
        count += 1;
    }

    int pop() {
        if (count == 0) {
            cout << "Count = 0";
            return NULL;
        }

        else if (size - count == 20)
        {
            T *tempArr = new T[count];
            for (size_t i = 0; i < count; i++) tempArr[i] = arr[i];
            size -= 10;
            arr = new T[size];
            for (size_t i = 0; i < count; i++) arr[i] = tempArr[i];
        }
        count--;
        return arr[count];
    }

    bool isEmpty() {
        return count == 0;
    }

    int getCount() {
        return count;
    }

    int getSize() {
        return size;
    }

//    string toString(){
//        string res = "";
//        for (size_t i = 0; i < size; i++) res += arr[i] + " ";
//        return res;
//    }

};