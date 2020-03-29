//
// Created by Sophia Shuvar on 28.03.20.
//

#ifndef SPARSEMATRIX_MATRIX_H
#define SPARSEMATRIX_MATRIX_H

#endif //SPARSEMATRIX_MATRIX_H

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


template <typename T>
struct Node {
    T data;
    size_t x;
    size_t y;

public:
    Node() {
        data = T();
        x = 0;
        y = 0;
    }

    Node(T data, size_t x, size_t y) {
        this->data = data;
        this->x = x;
        this->y = y;
    }

    friend ostream& operator <<(ostream& os, const Node& node) {
        os << "x = " << node.x << " " << "y = " << node.y << " " << "value = " << node.data << endl;
        return os;
    }

    Node operator + (Node node) {
        Node res = node;
        res.data = data + node.data;
        return res;
    }

    Node operator - (Node node) {
        Node res = node;
        res.data = data - node.data;
        return res;
    }
};

template <typename T>
class Matrix
{
private:
    vector<Node<T>> matrix;
    size_t x_length = 0;
    size_t y_length = 0;

public:
    void readMatrix(string file_name) {
        size_t x = 0, y= 0;
        ifstream myfile(file_name);
        if (myfile.is_open()) {
            string c;
            while (!myfile.eof()) {
                getline(myfile, c);
                string::size_type i = 0;
                string::size_type j = c.find(' ');
                y_length = y;
                y = 0;
                while (j != string::npos) {
                    if (c.substr(i, j-i) != "0") matrix.push_back(Node<T>(convert_to(c.substr(i, j-i)), x, y));
                    i = ++j;
                    j = c.find(' ', j);
                    y++;
                }
                if (c.substr(i, c.length()) != "0") matrix.push_back(Node<T>(convert_to(c.substr(i, c.length())), x, y));
                x++;
            }
            x_length = x;
            y_length++;
        } else cout << "Unable to open file";
    }

    static T convert_to (const string &str) {
        istringstream ss(str);
        T num;
        ss >> num;
        return num;
    }

    void add(T data, size_t y, size_t x){
        bool b = false;
        if (x >= x_length) x_length = x + 1;
        if (y >= y_length) y_length = y + 1;
        size_t s = this->matrix.size();
        if (data != T()) {
            for (size_t i = 0; i < s; i++){
                if (this->matrix[i].x == x && this->matrix[i].y == y) {
                    this->matrix[i].data = data;
                    b = true;
                    break;
                }
                else b = false;
            }
            if (!b) this->matrix.push_back(Node<T>(data, x, y));
        }
    }

    void remove(size_t y, size_t x){
        bool b = false;
        if (x >= x_length) throw "Index out of range";
        if (y >= y_length) throw "Index out of range";
        size_t s = this->matrix.size();
        for (size_t i = 0; i < s; i++){
            if (this->matrix[i].x == x && this->matrix[i].y == y) {
                this->matrix.erase(this->matrix.begin() + i);
                break;
            }
        }
    }

    Matrix operator +(Matrix matrix) {
        if (matrix.x_length == x_length && matrix.y_length == y_length) {
            Matrix result;
            result.x_length = x_length;
            result.y_length = y_length;
            for (size_t i = 0; i < this->matrix.size(); i++) result.matrix.push_back(this->matrix[i]);
            for (size_t i = 0; i < this->matrix.size(); i++)
                for (size_t j = 0; j < matrix.matrix.size(); j++)
                    if (result.matrix[i].x == matrix.matrix[j].x && result.matrix[i].y == matrix.matrix[j].y)
                        result.matrix[i] = result.matrix[i] + matrix.matrix[j];
            for (size_t j = 0; j < matrix.matrix.size(); j++){
                size_t i = 0;
                bool b = false;
                while (i != this->matrix.size()) {
                    if (matrix.matrix[j].x == this->matrix[i].x && matrix.matrix[j].y == this->matrix[i].y) b = true;
                    i++;
                }
                if (!b) result.matrix.push_back(matrix.matrix[j]);
            }
            return result;
        } else throw "Matrix size exception!";
    }

    Matrix operator -(Matrix matrix) {
        if (matrix.x_length == x_length && matrix.y_length == y_length) {
            Matrix result;
            result.x_length = x_length;
            result.y_length = y_length;
            for (size_t i = 0; i < this->matrix.size(); i++) result.matrix.push_back(this->matrix[i]);
            for (size_t i = 0; i < this->matrix.size(); i++) {
                for (size_t j = 0; j < matrix.matrix.size(); j++)
                    if (result.matrix[i].x == matrix.matrix[j].x && result.matrix[i].y == matrix.matrix[j].y)
                            result.matrix[i] = result.matrix[i] - matrix.matrix[j];
            }
            for (size_t j = 0; j < matrix.matrix.size(); j++) {
                size_t i = 0;
                bool b = false;
                while (i != this->matrix.size()) {
                    if (matrix.matrix[j].x == this->matrix[i].x && matrix.matrix[j].y == this->matrix[i].y) b = true;
                    i++;
                }
                if (!b) {
                    matrix.matrix[j].data *= -1;
                    result.matrix.push_back(matrix.matrix[j]);
                }
            }
            return result;
        } else throw "Matrix size exception!";
    }

    Matrix operator *(int a) {
        Matrix result;
        result.x_length = x_length;
        result.y_length = y_length;
        for (size_t i = 0; i < this->matrix.size(); i++) result.matrix.push_back(this->matrix[i]);
        for (size_t i = 0; i < this->matrix.size(); i++) result.matrix[i].data *= a;
        return result;
    }

//    Matrix operator *(Matrix matrix) {
//        if (matrix.y_length == x_length && matrix.x_length == y_length)
//        {
//            Matrix result;
//            result.x_length = matrix.x_length;
//            result.y_length = y_length;
//            vector<Node<T>> temp_vector;
//            int temp_value = 0;
//            for (size_t i = 0; i < this->matrix.size(); i++)
//            {
//                for (size_t j = 0; j < matrix.matrix.size(); j++)
//                {
//                    if (this->matrix[i].y == matrix.matrix[j].x)
//                    {
//                        temp_value = this->matrix[i].data * matrix.matrix[j].data;
//                        if (temp_value != 0)
//                        {
//                            temp_vector.push_back(Node<T>(temp_value, this->matrix[i].x, matrix.matrix[j].y));
//                        }
//                    }
//                }
//            }
//            for (size_t i = 0; i < temp_vector.size(); i++)
//            {
//                for (size_t j = 0; j < temp_vector.size(); j++)
//                {
//                    if (i != j)
//                    {
//                        if (temp_vector[i].x == temp_vector[j].x && temp_vector[i].y == temp_vector[j].y)
//                        {
//                            temp_vector[i].data += temp_vector[j].data;
//                            temp_vector[j].x = x_length + i + 1;
//                        }
//                    }
//                }
//            }
//            for (size_t i = 0; i < temp_vector.size(); i++)
//            {
//                if (temp_vector[i].x < x_length)
//                {
//                    result.matrix.push_back(temp_vector[i]);
//                }
//            }
//            return result;
//        } else throw "Matrix size exception!";
//    }

    T check(int i, int j) {
        for (size_t k = 0; k < matrix.size(); k++) {
            if (matrix[k].x == i && matrix[k].y == j) return matrix[k].data;
        }
        return T();
    }

    string toString(){
        string res = "";
        for (size_t i = 0; i < x_length; i++) {
            for (size_t j = 0; j < y_length; j++) {
                if (is_same<char*, decltype(*this)>::value) res += check(i, j)+ ' ';
                else res += to_string(check(i, j)) + ' ';
            }
            res += "\n";
        } return res;
    }

    void Print() {
        cout << toString();
    }
};