#include <iostream>
#include "./include/BinaryTree.h"

using namespace std;

int main() {
    cout << endl << "------ string / char tree ------";
    BinaryTree<string> strTree = BinaryTree<string>("a");
    Node<string> *strRoot = strTree.getRoot();
    strTree.insert("b");
    strTree.insert("d");
    strTree.insert("g");
    strTree.insert("e");
    strTree.insert("g");
    strTree.insert("k");
    cout << endl << "inorder disp: "; strTree.inorderTraversal();
    cout << endl << "preorder disp: "; strTree.preorderTraversal();
    cout << endl << "postorder disp: "; strTree.postorderTraversal();
    cout << endl << "min: " << strTree.getMin(strRoot)->data << ", max: " << strTree.getMax(strRoot)->data;
    cout << endl << "количество элементов: " << strTree.count(strRoot);

    cout << endl << endl << "-------- int tree --------";
    BinaryTree<int> intTree;// = BinaryTree<int>(4);
    Node<int> *intRoot = intTree.getRoot();
    intTree.insert(6);
    intTree.insert(2);
    intTree.insert(8);
    intTree.insert(111);
    intTree.insert(0);
    intTree.insert(-999999);
    intTree.insert(51);
    intTree.insert(55);
    cout << endl << "inorder disp: "; intTree.inorderTraversal();
    cout << endl << "preorder disp: "; intTree.preorderTraversal();
    cout << endl << "postorder disp: "; intTree.postorderTraversal();
    cout << endl << "min: " << intTree.getMin(intRoot)->data << ", max: " << intTree.getMax(intRoot)->data;
    cout << endl << "количество элементов: " << intTree.count(intRoot);
    intTree.deleteNode(intRoot, 111);
    cout << endl << "после удаления элемента со зн. 11: "; intTree.inorderTraversal(intRoot);
    if (intTree.search(intRoot, 51))
        cout << endl << "51 was found successfully";
    else
        cout << endl << "51 was not found";
    return 0;
}
