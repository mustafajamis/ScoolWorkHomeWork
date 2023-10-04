#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class LinkedList{
private:
    int count;
    Node<T>* begin;

    Node<T>* makeNode(const T value);
public:
    LinkedList();
    ~LinkedList();
    int size() const;
    bool isEmpty() const;
    T& getValue(int pos) const;
    void insertAtbegin(T& value);
    void insert(int pos, const T& value);
    void erase(int pos);
    void print() const;
};

#endif