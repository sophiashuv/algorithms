//
// Created by Sophia Shuvar on 14.03.20.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#endif //HASHTABLE_HASHTABLE_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int Hash(int key) {
    int sum = 0;
    while(key > 0) {
        sum += key%10;
        key /= 10;
    }
    return  sum;
}

class HashTable
{
    class HashNode
    {
    public:
        int value;
        HashNode* next;
        HashNode(int value) {
            this->value = value;
            this->next = nullptr;
        }
    };

private:
    HashNode** table;
    int tableSize;

public:
    HashTable() {
        tableSize = 10;
        table = new HashNode*[tableSize];
        for (int i = 0; i < tableSize; i++) table[i] = nullptr;
    }

    void Insert(int value) {
        int hashKey = Hash(value);
        HashNode* prev = nullptr;
        if (hashKey >= tableSize){
            HashNode** temp = new HashNode*[hashKey+1];
            for (int i = 0; i < tableSize; i++) temp[i] = table[i];
            for (int i = tableSize; i < hashKey+1 - tableSize; i++) temp[i] = nullptr;
            delete[] table;
            tableSize = hashKey+1;
            table = temp;
        }
        HashNode* entry = table[hashKey];
        while (entry != nullptr) {
            prev = entry;
            entry = entry->next;
        }
        if (entry == nullptr) {
            entry = new HashNode(value);
            if (prev == nullptr) table[hashKey] = entry;
            else prev->next = entry;
        }
    }

    void Remove(int hashKey) {
        HashNode* entry = table[hashKey];
        if (entry == nullptr) throw "There is no element with this key\n";
        table[hashKey] = nullptr;
        cout << "Element Deleted" << endl;
    }

//    void Remove_value(int value) {
//        HashNode *entry = table[Hash(value)];
//        if (entry == nullptr) throw "There is no such value\n";
//        while (entry != nullptr) {
//            if (entry->value == value) {
//
//            }
//
//        }
//    }

    void printNode(HashNode* entry){
        while (entry != nullptr) {
            cout << entry->value << "->";
            entry = entry->next;
        }
    }

    HashNode* Search(int hashKey) {
        HashNode* entry = table[hashKey];
        if (entry == nullptr) throw "There is no element with this key\n";
        return entry;
    }

    void PrintTable() {
        for (int i = 0; i < tableSize; i++) {
            HashNode* entry = table[i];
            if(entry != nullptr) {
                cout << i << ": ";
                printNode(entry);
                cout << "\n";
            }
        }
    }
};
