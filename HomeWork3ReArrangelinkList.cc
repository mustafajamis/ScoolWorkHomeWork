// Mustafa Jamshidi
// CS400Re-arrangeLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

typedef Node* NodePtr;

// Function to create a new node with the given data
NodePtr createNode(int data) {
    return new Node(data);
}

// Function to print the linked list
void printList(NodePtr head) {
    NodePtr current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << std::endl;
}

// Function to rearrange the list with even numbers after odd numbers
void rearrangeList(NodePtr& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    NodePtr oddHead = nullptr;
    NodePtr oddTail = nullptr;
    NodePtr evenHead = nullptr;
    NodePtr evenTail = nullptr;

    NodePtr current = head;

    while (current != nullptr) {
        if (current->data % 2 == 0) {
            if (evenHead == nullptr) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (oddHead == nullptr) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    if (oddHead == nullptr) {
        head = evenHead;
    } else {
        oddTail->next = evenHead;
        if (evenTail != nullptr) {
            evenTail->next = nullptr;
        }
        head = oddHead;
    }
}

int main() {
    NodePtr head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(5);
    head->next->next->next = createNode(8);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(4);

    cout << "Original List: ";
    printList(head);

    rearrangeList(head);

    cout << "Rearranged List: ";
    printList(head);

    // Clean up the memory
    NodePtr current = head;
    while (current != nullptr) {
        NodePtr temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
