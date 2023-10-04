/*
Mustafa Jamshidi (T686B548)
*/
#include <iostream>

template <typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int currentSize;

public:
    Vector(int initialSize) {
        arr = new T[initialSize];
        capacity = initialSize;
        currentSize = 0;
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(const T& element) {
        if (currentSize < capacity) {
            arr[currentSize++] = element;
        }
    }

    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
    }

    void insert(int index, const T& element) {
        if (index >= 0 && index <= currentSize && currentSize < capacity) {
            for (int i = currentSize; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            currentSize++;
        }
    }

    void erase(int index) {
        if (index >= 0 && index < currentSize) {
            for (int i = index; i < currentSize - 1; i++) {
                arr[i] = arr[i + 1];
            }
            currentSize--;
        }
    }

    T& operator[](int index) {
        return arr[index];
    }

    int size() {
        return currentSize;
    }
};

int main() {
    // Create a Vector of integers
    Vector<int> intVector(10);

    // Add elements to the vector
    intVector.push_back(10);
    intVector.push_back(20);
   

    // Print the elements
    std::cout << "Vector elements:";
    for (int i = 0; i < intVector.size(); i++) {
        std::cout << " " << intVector[i];
    }
    std::cout << std::endl;

    // Remove an element
    intVector.pop_back();

    // Print the elements again
    std::cout << "Vector elements after pop_back:";
    for (int i = 0; i < intVector.size(); i++) {
        std::cout << " " << intVector[i];
    }
    std::cout << std::endl;

    return 0;
}
