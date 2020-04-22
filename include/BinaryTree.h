#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
struct Node {
    T data;
    Node *right;
    Node *left;
};

class BinaryTree {
private:
    Node *rootNode;

public:
    BinaryTree();
    ~BinaryTree();
};

#endif
