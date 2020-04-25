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
    T value() { return data; };
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
    Node<T> *deleteNode(Node<T> *root, T value);
    Node<T> *getMin(Node<T> *root);
    Node<T> *getMax(Node<T> *root);
    void inorderTraversal(Node<T> *node);
    void preorderTraversal(Node<T> *node);
    void postorderTraversal(Node<T> *node);
    Node<T> *search(Node<T> *root, T value);

public:
    BinaryTree(); // конструктор
    explicit BinaryTree(T value); // конструктор с явными параметрами
    ~BinaryTree(); // деструктор
    Node<T>* getRoot(); // получения значения из корневого узла
    Node<T>* insert(T value); // вставка по значению
    void inorderTraversal(); // обход узлов в отсортированном порядке по заданному корню
    void preorderTraversal(); // обход узлов в порядке: вершина, левое поддерево, правое поддерево по заданному корню
    void postorderTraversal(); // обход узлов в порядке: левое поддерево, правое поддерево, вершина по заданному корню
    Node<T> *deleteNode(T value); // удаление по значению
    Node<T> *getMin(); // получение указателя на узел с минимальным значением
    Node<T> *getMax(); // получение указателя на узел с максимальным значением
    size_t count(); // получение количества элементов
    Node<T> *search(T value); // получение указателя на первый элемент с указанным знаечнием
    T value(Node<T> *node); // получение значения по указанному узлу
};

// ----------------------------------- описание private методов класса BinaryTree --------------------------------------
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
Node<T>* BinaryTree<T>::deleteNode(Node<T> *root, T value)
{
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else if (root->left != NULL && root->right != NULL)
    {
        root->data = getMin(root->right)->data;
        root->right = deleteNode(root->right, root->data);
    }
    else
    {
        if (root->left != NULL)
            root = root->left;
        else if (root->right != NULL)
            root = root->right;
        else
            root = NULL;
    }
    return root;
}

template <typename T>
Node<T>* BinaryTree<T>::getMin(Node<T> *root)
{
    if (root->left == NULL)
        return root;
    return getMin(root->left);
}

template <typename T>
Node<T>* BinaryTree<T>::getMax(Node<T> *root)
{
    if (root->right == NULL)
        return root;
    return getMax(root->right);
}

template <typename T>
void BinaryTree<T>::inorderTraversal(Node<T> *node)
{
    if (node != NULL)
    {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

template <typename T>
void BinaryTree<T>::preorderTraversal(Node<T> *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

template <typename T>
void BinaryTree<T>::postorderTraversal(Node<T> *node)
{
    if (node != NULL)
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}

template <typename T>
Node<T>* BinaryTree<T>::search(Node<T> *root, T value)
{
    if (root == NULL || value == root->data)
        return root;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// ------------------------------------ описание public методов класса BinaryTree --------------------------------------
template <typename T>
BinaryTree<T>::BinaryTree()
{
    this->root = new Node<T>;
    this->root->data = NULL;
    this->root->left = NULL;
    this->root->right = NULL;
}

template <typename T>
BinaryTree<T>::BinaryTree(T value)
{
    this->nodesCount += 1;
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
Node<T>* BinaryTree<T>::insert(T value)
{
    this->nodesCount += 1;
    Node<T>* tmp = newNode(value);
    Node<T>* x = this->root;
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
void BinaryTree<T>::inorderTraversal ()
{
    inorderTraversal(this->root);
}

template <typename T>
void BinaryTree<T>::preorderTraversal ()
{
    preorderTraversal(this->root);
}

template <typename T>
void BinaryTree<T>::postorderTraversal ()
{
    postorderTraversal(this->root);
}

template <typename T>
Node<T>* BinaryTree<T>::getMin()
{
    return getMin(this->root);
}

template <typename T>
Node<T>* BinaryTree<T>::getMax()
{
    return getMax(root->right);
}

template <typename T>
Node<T>* BinaryTree<T>::deleteNode(T value)
{
    deleteNode(this->root, value);
}

template <typename T>
size_t BinaryTree<T>::count()
{
    return this->nodesCount;
}

template <typename T>
Node<T>* BinaryTree<T>::search(T value)
{
    return search(this->root, value);
}

template <typename T>
T value(Node<T> *node)
{
    return node->data;
}
#endif