#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

// структура узла двоичного дерева
template <typename T>
struct Node
{
    T data;
    Node *right = nullptr;
    Node *left = nullptr;
    Node *parent = nullptr;
};

// объявление класса двоичного дерева ----------------------------------------------------------------------------------
template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
    void memoryFree(Node<T> *Node);
    void setRoot(T value);

public:
    BinaryTree();
    explicit BinaryTree(T value);
    ~BinaryTree();
    void rootPrint();
    void insert(T value);
};

// описание private методов класса BinaryTree --------------------------------------------------------------------------
template <typename T>
void BinaryTree<T>::memoryFree(Node<T> *Node)
{
    if (Node == nullptr) {
        return;
    }
    memoryFree(Node->left);
    memoryFree(Node->right);
    delete Node;
}

template <typename T>
void BinaryTree<T>::setRoot(T value)
{
    this->root->data = value;
}

// описание public методов класса BinaryTree ---------------------------------------------------------------------------
template <typename T>
BinaryTree<T>::BinaryTree()
{
    this->root = new Node<T>;
    this->root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T value)
{
    this->root = new Node<T>;
    this->root->data = value;
    this->root->left = nullptr;
    this->root->right = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree<T>()
{
    memoryFree(this->root);
}

template <typename T>
void BinaryTree<T>::rootPrint()
{
    if (this->root == nullptr)
        cout << "nullptr";
    else
        cout << root->data;
}

template <typename T>
void BinaryTree<T>::insert(T value)
{
    if (this->root == nullptr)
    {
        root = new Node<T>;
        root->data = value;
        cout << root->data;
    }
}

#endif
