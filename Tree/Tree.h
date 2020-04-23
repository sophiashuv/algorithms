//
// Created by Sophia Shuvar on 23.04.20.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#endif //TREE_TREE_H

#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    size_t height;
    Node* left;
    Node* right;
    Node(){}
    Node(int value)
    {
        this->value = value;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
public:
    Tree(){}

    Tree(int value) {
        root = new Node(value);
    }

    Node* getRoot() {
        return root;
    }

    size_t max(size_t a, size_t b) {
        return(a > b)?a:b;
    }

    size_t height(Node* n) {
        return (n == nullptr) ? 0: n->height;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        if (y == root) root = x;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* y) {
        Node* x = y->right;
        Node* T2 = x->left;
        x->left = y;
        y->right = T2;
        if (y == root) root = x;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    int getBalance(Node* node) {
        return height(node->left) - height(node->right);
    }

    Node* addElement(int value) {
        return insert(root, value);
    }

    bool isElement(int value) {
        Node *node = root;
        while (node != nullptr) {
            if (value == node->value) return true;
            if (value > node->value) node = node->right;
            else node = node->left;
        }
        return false;
    }

    void RAB(Node* node, vector<Node*>& vector) {
        if (node != nullptr) vector.push_back(node);
        if (node->left != nullptr) RAB(node->left, vector);
        if (node->right != nullptr) RAB(node->right, vector);
    }

private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node(value);
        if (value < node->value) node->left = insert(node->left, value);
        else if (value > node->value) node->right = insert(node->right, value);
        else return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        //LeftLeft
        if (balance > 1 && value < node->left->value) return rightRotate(node);

        //RightRight
        if (balance < -1 && value > node->right->value) return leftRotate(node);

        //LeftRight
        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        //RightLeft
        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};