//
// Created by Sophia Shuvar on 07.03.20.
//


#define TABLE_VECTOR_H

#include <iostream>
#pragma once


using namespace std;
template<typename T>
class vectorClass {
    T* arr;
    int capacity;
    int current;

public:
    vectorClass(): arr( new T[1]),  capacity(1), current(0){};
    ~vectorClass() {
        delete[] arr;
    }

    void push_back(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) temp[i] = arr[i];
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    bool isEmpty() const{
        return current==0;
    }

    void insert(T data, int index) {
        if (index == capacity) push_back(data);
        else arr[index] = data;
    }

    T get(int index) const{
        return arr[index];
    }

    void pop_back() {
        current--;
    }

    int GetSize() {
        return current;
    }

    int getcapacity() {
        return capacity;
    }

    friend ostream &operator<<(ostream &os, const vectorClass &a) {
        for (int i = 0; i < a.current; ++i) os << a.arr[i] << " ";
        return os;
    }
    void print() {
        for (int i = 0; i < current; i++) cout << arr[i] << " ";
        cout << endl;
    }

    T &operator[](size_t i) {
        return arr[i];
    }
};