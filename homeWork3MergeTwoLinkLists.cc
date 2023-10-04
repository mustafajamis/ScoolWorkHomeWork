//Mustafa Jamshidi
//
// CS400MergeTwoLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
    //TODO:
    int data;
    Node* next;
    Node(int value):data(value), next(nullptr){}
};

typedef Node* NodePtr;

// Function to create a new node with the given data
NodePtr createNode(int data) {
    //TODO:
    return new Node(data);
}

// Function to print the linked list
void printList(NodePtr head) {
    //TODO:
    NodePtr temp = head;
    while (temp != nullptr){
        cout<<temp->data<<endl;
        temp = temp->next;
    }


}




NodePtr mergeSortedLists(NodePtr list1, NodePtr list2) {
    //TODO:
    Node dummy(0);
    Node* tail = &dummy;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->data <= list2->data){
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if(list1 != nullptr){
        tail->next = list1;

    }else {
        tail->next = list2;
    }

    return dummy.next;

    
}





// test your solution:
int main() {
    // Create the first linked list: 1->3->5->7
    NodePtr list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    list1->next->next->next = createNode(7);

    // Create the second linked list: 2->4->6->8
    NodePtr list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(8);

    // Merge the two sorted lists
    NodePtr mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    // Clean up the memory
    NodePtr head = mergedList;
    while (head != nullptr) {
        NodePtr temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

