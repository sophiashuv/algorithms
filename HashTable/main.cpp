#include <iostream>
#include "HashTable.h"
using namespace std;

int main(){
    HashTable h;
    try {
        h.Insert(123);
        h.Insert(111);
        h.Insert(33);
        h.Insert(34);
        h.Insert(7);
        h.Insert(3);
        h.Insert(897);
        h.Insert(99);
        h.Remove(3);
        h.Insert(3);
        h.Insert(12);
        h.Insert(576);
        h.Insert(1);
        cout << "sum 1: ";
        h.printNode(h.Search(1));
        cout << "\n";
    } catch (const  char* &e){
        cout << e;
    }
    h.PrintTable();
}