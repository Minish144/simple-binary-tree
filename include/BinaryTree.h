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
};

template <typename T>
Node<T>* newNode(T value)
{
    auto* temp = new Node<T>;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// --------------------------------------- объявление класса двоичного дерева ------------------------------------------
template <typename T>
class BinaryTree
{
private:
    size_t nodesCount = 0;
    Node<T> *root;
    void memoryFree(Node<T> *Node);

public:
    BinaryTree();
    explicit BinaryTree(T value);
    ~BinaryTree();
    Node<T>* getRoot();
    Node<T>* insert(Node<T> *root, T value);
    void inorderTraversal (Node<T> *root);
    void preorderTraversal (Node<T> *root);
    void postorderTraversal (Node<T> *root);
};

// ---------------------------------- описание private методов класса BinaryTree ---------------------------------------
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

// ----------------------------------- описание public методов класса BinaryTree ---------------------------------------
template <typename T>
BinaryTree<T>::BinaryTree()
{
    this->root = new Node<T>;
    this->root = NULL;
}

template <typename T>
BinaryTree<T>::BinaryTree(T value)
{
    this->root = new Node<T>;
    this->root->data = value;
    this->root->left = NULL;
    this->root->right = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree<T>()
{
    memoryFree(this->root);
}

template <typename T>
Node<T>* BinaryTree<T>::getRoot()
{
    return root;
}

template <typename T>
Node<T>* BinaryTree<T>::insert(Node<T>* root, T value)
{
    this->nodesCount += 1;
    Node<T>* tmp = newNode(value);
    Node<T>* x = root;
    Node<T>* y = NULL;
    while (x != NULL) {
        y = x;
        if (value < x->data)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
        y = tmp;
    else if (value < y->data)
        y->left = tmp;
    else
        y->right = tmp;
    return y;
}

template <typename T>
void BinaryTree<T>::inorderTraversal(Node<T> *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

template <typename T>
void BinaryTree<T>::preorderTraversal(Node<T> *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

template <typename T>
void BinaryTree<T>::postorderTraversal(Node<T> *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}
#endif
