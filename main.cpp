#include <iostream>
#include "./include/BinaryTree.h"

using namespace std;

int main() {
    BinaryTree<int> bin = BinaryTree<int>(2);
    Node<int> *root = bin.getRoot();
    bin.insert(root, 7);
    bin.insert(root, 5);
    bin.insert(root, 2);
    bin.insert(root, 6);
    bin.insert(root, 9);
    bin.insert(root, 5);
    bin.insert(root, 4);
    bin.insert(root, 11);
    bin.display(root);
    return 0;
}
