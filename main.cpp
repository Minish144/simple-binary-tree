#include <iostream>
#include "./include/BinaryTree.h"

using namespace std;

int main() {
    BinaryTree<int> tree = BinaryTree<int>(123);
    tree.rootPrint();
    return 0;
}
