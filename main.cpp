#include <iostream>
#include "./include/BinaryTree.h"

using namespace std;

int main() {
    BinaryTree<string> tree = BinaryTree<string>();
    tree.insert("test");
    return 0;
}
