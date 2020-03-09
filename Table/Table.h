//
// Created by Sophia Shuvar on 07.03.20.
//

#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H

#endif //TABLE_TABLE_H

using namespace std;

template< template <typename> class Container>
class Table {
    const static int n = 10;
    Container<int> arr[n];

public:
    Table(){};
//    ~Table() {
//        delete[] arr;
//    }

    void push_back(int data) {
       arr[data%10].push_back(data);
    }

    void insert(int data, int index) {
        arr[data%10].insert(data, index);
    }

    Container<int> get(int index) const{
        return arr[index];
    }

    int get(int index1, int index2) {
        return (arr[index1])[index2];
    }

    void pop(int index) {
        arr[index].pop_back();
    }

    // Only for List
    void pop(int index1, int index2) {
        arr[index1].removeAt(index2);
    }

    int size() {
        int size = 0;
        for (int i = 0; i < n; i++) size+=arr[i].GetSize();
        return size;
    }

    friend ostream &operator<<(ostream &os,  Table &a) {
        for (int i = 0; i < a.n; ++i) if(a.arr[i].GetSize() != 0) a.arr[i].print();
        return os;
    }

    void print() {
        for (int i = 0; i < n; i++) if(arr[i].GetSize() != 0) arr[i].print();
    }

    Container<int> &operator[](size_t i) {
        return arr[i];
    }

};