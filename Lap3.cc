#include "Lap3.h"

using namespace std;
template <typename T>
Vector<T>::Vector(int initialSize){
    arr  = new T[initialSize];
    capacity = initialSize;
    currentSize = 0;
}
template <typename T>
Vector<T>::~Vector(){
    delete[] arr;
}
template <typename T>
void Vector<T>::push_back(const T& element){
    if(currentSize < capacity){
        arr[currentSize++] = element;
    }
}
template <typename T>
void Vector<T>::pop_back(){
    if(currentSize > 0){
        currentSize--;
    }
}
template <typename T>
void Vector<T>::insert(int index, const T& element){
    if(index >=0 && index <= currentSize && currentSize < capacity) {
                for(int i = currentSize; i > index; i--){
                arr[i] = arr[i - 1];
                }
                arr[index] = element;
                currentSize++;
    }

}
template <typename T>
void Vector<T>::erase(int index)
{
    if (index >= 0 && index < currentSize) {
        for (int i = index; i < currentSize - 1; i++){
            arr[i] = arr[i + 1];
        }
        currentSize--;
    }
}
template <typename T>
T& Vector<T>::operator[](int index){
    return arr[index];
}
template <typename T>
int Vector<T>::size(){
    return currentSize;
}




