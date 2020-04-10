//
// Created by Sophia Shuvar on 08.04.20.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
#pragma once
#include <iostream>
#include <string>
using  namespace std;

/*
 * Class for priority queue representation based on linked list.
 */
template<typename T>
class PriorityQueue {
private:

    class Node {
    public:
        T data;
        size_t priority;
        Node * Next;

        Node(T data = T(), size_t priority = 0, Node *Next = nullptr) {
            this->data = data;
            this->priority = priority;
            this->Next = Next;
        }
    };

    size_t size;
    Node *head;

public:
    PriorityQueue() {
        size = 0;
        head = nullptr;
    }

    void insert(T data, size_t priority){
        Node *newNode = new Node(data, priority);
        if(head == nullptr || priority < head->priority){
            newNode->Next = head;
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->Next != nullptr && temp->Next->priority <= priority)
                temp = temp->Next;
            newNode->Next = temp->Next;
            temp->Next = newNode;
        }
        size++;
    }

    void pop(){
        Node *temp;
        if(head == nullptr) throw "Empty queue exception";
        else {
            temp = head;
            head = head->Next;
            cout << "Deleted item: " << temp->data << "\n";
            delete temp;
        }
        size--;
    }

    T top(){
        if(head == nullptr) throw "Empty queue exception";
        else return head->data;
    }

    friend ostream& operator<<(ostream& out, PriorityQueue<T>& pq) {
        Node* temp = pq.head;
        while (temp != nullptr) {
            out << temp->data << " ";
            temp = temp->Next;
        }
        out << endl;
        return out;
    }

    string toString() {
        string res;
        Node* temp = head;
        while (temp != nullptr) {
            res += to_string(temp->data) + " ";
            temp = temp->Next;
        }
        res += "\n";
        return res;
    }

    void clear(){
        while (head != nullptr) this->pop();
    }

    bool isEmpty(){
        return size == 0;
    }

    size_t Size(){
        return size;
    }
};