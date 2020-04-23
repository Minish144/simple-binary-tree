#include <iostream>
#include "./include/BinaryTree.h"

using namespace std;

int main() {
    cout << endl << "------ string / char tree ------";
    BinaryTree<string> strTree = BinaryTree<string>("a");
    Node<string> *strRoot = strTree.getRoot();
    strTree.insert(strRoot, "b");
    strTree.insert(strRoot, "d");
    strTree.insert(strRoot, "g");
    strTree.insert(strRoot, "e");
    strTree.insert(strRoot, "g");
    strTree.insert(strRoot, "k");
    cout << endl << "inorder disp: "; strTree.inorderTraversal(strRoot);
    cout << endl << "preorder disp: "; strTree.preorderTraversal(strRoot);
    cout << endl << "postorder disp: "; strTree.postorderTraversal(strRoot);
    cout << endl << "min: " << strTree.getMin(strRoot)->data << ", max: " << strTree.getMax(strRoot)->data;

    cout << endl << endl << "-------- int tree --------";
    BinaryTree<int> intTree = BinaryTree<int>(4);
    Node<int> *intRoot = intTree.getRoot();
    intTree.insert(intRoot, 6);
    intTree.insert(intRoot, 2);
    intTree.insert(intRoot, 8);
    intTree.insert(intRoot, 111);
    intTree.insert(intRoot, 0);
    intTree.insert(intRoot, 55);
    cout << endl << "inorder disp: "; intTree.inorderTraversal(intRoot);
    cout << endl << "preorder disp: "; intTree.preorderTraversal(intRoot);
    cout << endl << "postorder disp: "; intTree.postorderTraversal(intRoot);
    cout << endl << "min: " << intTree.getMin(intRoot)->data << ", max: " << intTree.getMax(intRoot)->data;
    return 0;
}
