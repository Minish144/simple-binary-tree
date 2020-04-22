#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

// структура узла двоичного дерева
template <typename T>
struct Node
{
    T data;
    Node *right;
    Node *left;
    Node *parent;
};

// объявление класса двоичного дерева ----------------------------------------------------------------------------------
template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
    void DeallocMemory(Node<T> *Node);

public:
    BinaryTree();
    explicit BinaryTree(T value);
    ~BinaryTree();
    void rootPrint();
};

// описание private методов класса BinaryTree --------------------------------------------------------------------------
template <typename T>
void BinaryTree<T>::DeallocMemory(Node<T> *Node)
{
    if (Node == nullptr) {
        return;
    }
    DeallocMemory(Node->left);
    DeallocMemory(Node->right);
    delete Node;
}

// описание public методов класса BinaryTree ---------------------------------------------------------------------------
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = new Node<T>;
    root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T value)
{
    root = new Node<T>;
    root->data = value;
    root->left = nullptr;
    root->right = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree<T>()
{
    DeallocMemory(root);
}

template <typename T>
void BinaryTree<T>::rootPrint()
{
    if (root == nullptr)
        cout << "nullptr";
    else
        cout << root->data;
}

#endif
