#ifndef LAP3_H
#define LAP3_H

#include <iostream>
#include <vector>

using namespace std;
template <typename T>
class Vector{
        T* arr;
        int capacity;
        int currentSize;
    
    public:
        Vector(int initialSize);
        ~Vector();
        void push_back(const T& element);
        void pop_back();
        void insert(int index, const T& element);
        void erase(int index);
        T& operator[](int index);
        int size();
};


#endif

