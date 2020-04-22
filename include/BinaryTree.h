#ifndef TREE_H
#define TREE_H

// структура узла двоичного дерева
template <typename T>
struct Node
{
    T data;
    Node *right;
    Node *left;
};

// объявление класса двоичного дерева
template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
    void DeallocMemory(Node<T> *Node);

public:
    BinaryTree();
    ~BinaryTree();
};

// описание методов двоичного дерева
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = new Node<T>;
    root = nullptr;
    root->left = nullptr;
    root->right = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree<T>()
{
    DeallocMemory(root);
}

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

#endif
