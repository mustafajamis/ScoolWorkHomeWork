#include <stdexcept>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(): count(0),begin(nullptr){}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* del= begin;
    while(begin != nullptr){
        begin = begin->next;
        delete del;
        del= begin;
    }
}

template <typename T>
int LinkedList<T>::size() const{
    return count;
}

template <typename T>
bool LinkedList<T>::isEmpty() const{
    return (count == 0);
}

template <typename T>
T& LinkedList<T>::getValue(int pos) const{
    if(pos == 0){
        return begin->data;
    }
    else if(pos<0){
        throw std::out_of_range("Position is out of range");
    }
    else{
        Node<T>* cur = begin;
        for(int i =0; i < pos; i++){
            cur = cur->next;
        }
        return cur->data;
    }
}

template <typename T>
Node<T>* LinkedList<T>::makeNode(const T value){
    Node<T>* newNode = new Node<T>;   //new node under heap dynamically
    newNode->data = value;
    newNode->next = nullptr;
}

template <typename T>
void LinkedList<T>::insertAtbegin(T& value){
    Node<T>* add = makeNode(value);
    add->next= begin;
    begin = add;
    count++;
}

template <typename T>
void LinkedList<T>::insert(int pos, const T& value){
    if(pos<0 || pos>count){
        throw std::out_of_range("Position out of range.");
    }
    Node<T>* add = makeNode(value);
    if (pos == 0){
        add->next = begin;
        begin = add;
    }
    else{
        Node<T>* cur = begin;
        for(int i=1;i<pos;i++){
            cur = cur->next;
        }
        add->next = cur->next;
        cur->next = add; 
    }
    count++;
}

template <typename T>
void LinkedList<T>::erase(int pos){
    if(pos<0 || pos>count){
        throw std::out_of_range("Position out of range.");
    }
    else if(pos == 0){
        Node<T>* del = begin;
        begin =begin->next;
        delete del;
    }
    else{
        Node<T>* cur = begin;
        for(int i=1; i<pos-1; i++){
            cur=cur->next;
        }
        Node<T>* del = cur->next;
        cur->next = cur->next->next;
        delete del;
    }
}

template <typename T>
void LinkedList<T>::print() const{
    if(isEmpty()){
        std::cout << "List is empty." << std::endl;
    }
    Node<T>* cur =begin;
    while(cur){
        std::cout << cur->data <<std::endl;
        cur = cur->next;
    }
}