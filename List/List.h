//
// Created by Sophia Shuvar on 19.03.20.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#endif //LIST_LIST_H
#include <stdlib.h>
#include <iostream>
using namespace std;
template <class T>
struct Node {
    T x;
    Node *Next;
    Node *Prev;

    Node(T v) : x(v), Prev(nullptr), Next(nullptr) {}

    friend void swap(Node<T>* a,  Node<T>*b){
        swap(a->x, b->x);
    }

    friend ostream& operator<<(ostream& out, Node<T>& a) {
        out << a.x << " ";
        return out;
    }

    Node& operator =(const Node&a) {
        this->x = a.x;
        this->Next = a->Next;
        this->Prev = a->Prev;
        return *this;
    }
};


template <class T>
class List {
    Node<T> *Head;
    Node<T> *Tail;
    size_t size;

public:
    List():Head(nullptr),Tail(nullptr), size(0){};

//???????????????
    List (const List & a){
        size = a.size;
        Node<T> *origPtr;
        origPtr = a.Head;
        while (origPtr != nullptr) {
            this->push_back(origPtr->x);
            origPtr = origPtr->Next;
        }
    }

    ~List(){
        while (Head){
            Tail = Head->Next;
            delete Head;
            Head = Tail;
        }
    }

    void Show(){
        Node<T> *temp = Head;
        while (temp != nullptr){
            cout << *temp;
            temp = temp->Next;
        }
        cout << "\n";
    }

    size_t Size(){
        return size;
    }

    friend ostream& operator<<(ostream& out, List<T>& list) {
        Node<T>* temp = list.Head;
        while (temp != nullptr) {
            out << *temp;
            temp = temp->Next;
        }
        out << endl;
        return out;
    }

    void push_back(T val) {
        Node<T>* curr = new Node<T>(val);
        if (Head == nullptr) {
            Head = Tail = curr;
        } else {
            curr->Prev = Tail;
            Tail->Next = curr;
            Tail = curr;
        }
        size++;
    }

    void push_front(T val) {
        Node<T>* curr = new Node<T>(val);
        if (Head == nullptr) {
            Head = Tail = curr;
        } else {
            Head->Prev = curr;
            curr->Next = Head;
            Head = curr;
        }
        size++;
    }

    void insert( T val, int index) {
        Node<T>* t = Head;
        if (index > size || index < 0) throw "index out of range exception";
        if (Head == nullptr) throw "empty list exception";
        if (index == 0) push_front(val);
        else if (index == size) push_back(val);
        else {
            while (index > 1) {
                t = t->Next;
                index--;
            }
            Node<T> *temp = new Node<T>(val);
            temp->Next = t->Next;
            temp->Prev = t;
            t->Next->Prev = temp;
            t->Next = temp;
            size++;
        }
    }

    void pop_front() {
        Node<T>* t = Head->Next;
        delete Head;
        Head = t;
        size--;
    }

    void pop_back() {
        Node<T>* t = Tail->Prev;
        delete Tail;
        Tail = t;
        Tail->Next = nullptr;
        size--;
    }

    void pop(int index) {
        Node<T> *t = Head;
        if (Head == nullptr) throw "empty list exception";
        if (index > size || index < 0) throw "index out of range exception";
        if (index == 0) pop_front();
        else if (index == size - 1) pop_back();
        else {
            while (index > 0) {
                t = t->Next;
                index--;
            }
            t->Next->Prev = t->Prev;
            t->Prev->Next = t->Next;
            delete t;
            size--;
        }
    }

    void reverse(){
        Node<T> *begin = Head;
        Node<T> *end = Tail;
        int ind = size/2;
        while (ind > 0 ) {
           swap(begin, end);
           begin = begin->Next;
           end = end->Prev;
           ind--;
        }
    }
    // coctail sort
    void sort(){
        bool swapped = true;
        Node<T> *begin ;
        Node<T> *ends ;
        Node<T> *begin2 = Head;
        Node<T> *ends2 = Tail;
        while (swapped) {
            swapped = false;
            begin = begin2;
            while (begin->Next != nullptr) {
                if (begin->x > (begin->Next)->x) {
                    swap(begin, begin->Next);
                    swapped = true;
                } begin = begin->Next;
            }
            if (!swapped)
                break;
            swapped = false;
            ends2 = ends2->Prev;
            ends = ends2;
            while (ends->Prev != nullptr) {
                if (ends->x > (ends->Next)->x) {
                    swap(ends, ends->Next);
                    swapped = true;
                } ends = ends->Prev;
            } begin2 =  begin2->Next;
      }
    }

    friend List<T> operator+( List<T>& list1, List<T>& list2) {
        if (list1.Size() != list2.Size()) throw "Size exception";
        List<T> res;
        Node<T> *begin1 = list1.Head;
        Node<T> *begin2 = list2.Head;
        while (begin1 != nullptr) {
            res.push_back(begin1->x + begin2->x);
            begin1 = begin1->Next;
            begin2 = begin2->Next;
        } return res;
    }

    friend List<T> operator+( List<T>& list1, T &a) {
        List<T> res;
        Node<T> *begin1 = list1.Head;
        while (begin1 != nullptr) {
            res.push_back(begin1->x + a);
            begin1 = begin1->Next;
        } return res;
    }

    List& operator =(const List&a) {
        if(this == &a)
            return *this;
        this->size = a.size;
        Node<T> *origPtr;
        origPtr = a.Head;
        while (origPtr != nullptr) {
            this->push_back(origPtr->x);
            origPtr = origPtr->Next;
        }
        return *this;
    }
    };
// 1 2 3 5 12
