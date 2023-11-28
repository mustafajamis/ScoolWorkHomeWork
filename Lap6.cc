// Mustafa Jamshidi
#include <iostream>
#include <string> // Include for string type

// Definition of Node struct
template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
};

// Definition of BinarySearchTree class
template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;
    int count;

    // Helper function to recursively destroy nodes
    void destroy(Node<T>* ptr);

    // Helper function to recursively insert a value into the BST
    void insert(T value, Node<T>*& ptr);

    // Helper function to create a new node
    Node<T>* makeNode(T value);

    // Helper function for inorder traversal
    void inorder(Node<T>* ptr) const;

    // Helper function for preorder traversal
    void preorder(Node<T>* ptr) const;

    // Helper function for postorder traversal
    void postorder(Node<T>* ptr) const;

public:
    // Constructor:
    BinarySearchTree();

    // Destructor
    ~BinarySearchTree();

    // Public function to insert a value into the BST
    void insert(T value);

    // Public function for inorder traversal
    void inorder() const;

    // Public function for preorder traversal
    void preorder() const;

    // Public function for postorder traversal
    void postorder() const;

    // Public function to get the size of the BST
    int size() const;

    // Public function to check if the BST is empty
    bool empty() const;
};

// Implementation of BinarySearchTree member functions

// Constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr), count(0) {}

// Destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroy(root);
}

// Helper function to recursively destroy nodes
template <typename T>
void BinarySearchTree<T>::destroy(Node<T>* ptr) {
    if (ptr != nullptr) {
        destroy(ptr->left);
        destroy(ptr->right);
        delete ptr;
    }
}

// Helper function to recursively insert a value into the BST
template <typename T>
void BinarySearchTree<T>::insert(T value, Node<T>*& ptr) {
    if (ptr == nullptr) {
        ptr = makeNode(value);
        count++;
    } else if (value < ptr->data) {
        insert(value, ptr->left);
    } else {
        insert(value, ptr->right);
    }
}

// Helper function to create a new node
template <typename T>
Node<T>* BinarySearchTree<T>::makeNode(T value) {
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Helper function for inorder traversal
template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* ptr) const {
    if (ptr != nullptr) {
        inorder(ptr->left);
        std::cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

// Public function for inorder traversal
template <typename T>
void BinarySearchTree<T>::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

// Helper function for preorder traversal
template <typename T>
void BinarySearchTree<T>::preorder(Node<T>* ptr) const {
    if (ptr != nullptr) {
        std::cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

// Public function for preorder traversal
template <typename T>
void BinarySearchTree<T>::preorder() const {
    preorder(root);
    std::cout << std::endl;
}

// Helper function for postorder traversal
template <typename T>
void BinarySearchTree<T>::postorder(Node<T>* ptr) const {
    if (ptr != nullptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        std::cout << ptr->data << " ";
    }
}

// Public function for postorder traversal
template <typename T>
void BinarySearchTree<T>::postorder() const {
    postorder(root);
    std::cout << std::endl;
}

// Public function to get the size of the BST
template <typename T>
int BinarySearchTree<T>::size() const {
    return count;
}

// Public function to check if the BST is empty
template <typename T>
bool BinarySearchTree<T>::empty() const {
    return count == 0;
}

int main() {
    // Test 1:
    BinarySearchTree<int> bstInt;
    bstInt.insert(1);
    bstInt.insert(20);
    bstInt.insert(3);
    bstInt.insert(7);
    bstInt.insert(13);
    bstInt.insert(5);

    std::cout << "inorder: " << std::endl;
    bstInt.inorder();

    std::cout << "preorder: " << std::endl;
    bstInt.preorder();

    std::cout << "postorder: " << std::endl;
    bstInt.postorder();

    std::cout << "size: " << bstInt.size() << std::endl;

    // Test 2:
    BinarySearchTree<std::string> bstStr;
    bstStr.insert("Michael");
    bstStr.insert("Jane");
    bstStr.insert("Sophie");
    bstStr.insert("Thomas");
    bstStr.insert("Rose");
    bstStr.insert("Richard");

    std::cout << "Using preorder traversal" << std::endl;
    bstStr.preorder();
    std::cout << std::endl << std::endl;

    std::cout << "Using inorder traversal" << std::endl;
    bstStr.inorder();
    std::cout << std::endl << std::endl;

    std::cout << "Using postorder traversal" << std::endl;
    bstStr.postorder();
    std::cout << std::endl << std::endl;

    return 0;
}

