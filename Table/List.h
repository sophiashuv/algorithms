//
// Created by Sophia Shuvar on 08.03.20.
//

//#ifndef TABLE_LIST_H
#define TABLE_LIST_H
#pragma once
#include <iostream>
using  namespace std;

template<typename T>
class List {
private:
    template<typename K>
    class Node
    {
    public:
        Node * pNext;
        K data;

        Node(K data = K(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *head;

public:
    List() {
        Size = 0;
        head = nullptr;
    }

    ~List(){
        clear();
    }

    void pop_front(){
        Node<T> *temp = head;
        head = head->pNext;
        delete temp;
        Size--;
    }

    void push_back(T data){
        if (head == nullptr) head = new Node<T>(data);
        else {
            Node<T> *current = this->head;
            while (current->pNext != nullptr) current = current->pNext;
            current->pNext = new Node<T>(data);
        }
        Size++;
    }

    void clear(){
        while (Size) pop_front();
    }

    void print(){
        int counter = 0;
        Node<T> *current = this->head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->pNext;
            counter++;
        }
        cout << "\n";
    }

    int GetSize() {
        return Size;
    }

    T& operator[](const int index){
        int counter = 0;
        Node<T> *current = this->head;
        while (current != nullptr) {
            if (counter == index) return current->data;
            current = current->pNext;
            counter++;
        }
    }

    void push_front(T data){
        head = new Node<T>(data, head);
        Size++;
    }

    void insert(T data, int index){
        if (index == 0) push_front(data);
        else {
            Node<T> *previous = this->head;
            for (int i = 0; i < index - 1; i++) previous = previous->pNext;
            Node<T> *newNode = new Node<T>(data, previous->pNext);
            previous->pNext = newNode;
            Size++;
        }
    }

    void removeAt(int index){
        if (index == 0) pop_front();
        else {
            Node<T> *previous = this->head;
            for (int i = 0; i < index - 1; i++) previous = previous->pNext;
            Node<T> *toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            delete toDelete;
            Size--;
        }
    }

    void pop_back(){
        removeAt(Size - 1);
    }
};

