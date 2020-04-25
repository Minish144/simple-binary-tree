#include <iostream>
#include "./include/BinaryTree.h"

using namespace std;

int main() {
    cout << endl << "------ string / char tree ------";
    BinaryTree<string> strTree = BinaryTree<string>("f");
    Node<string> *strRoot = strTree.getRoot();
    strTree.insert("b");
    strTree.insert("d");
    strTree.insert("a");
    strTree.insert("e");
    strTree.insert("g");
    strTree.insert("k");
    cout << endl << "inorder disp: "; strTree.inorderTraversal();
    cout << endl << "preorder disp: "; strTree.preorderTraversal();
    cout << endl << "postorder disp: "; strTree.postorderTraversal();
    cout << endl << "min: " << strTree.getMin()->value() << ", max: " << strTree.getMax()->value();
    BinaryTree<string>::Iterator iter = strTree.begin();
    cout << endl << "Значение из итератора: " << iter.value();
    cout << endl << "количество элементов: " << strTree.count();


    cout << endl << endl << "-------- int tree --------";
    BinaryTree<int> intTree;
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
    cout << endl << "min: " << intTree.getMin()->value() << ", max: " << intTree.getMax()->value();
    cout << endl << "количество элементов: " << intTree.count();
    intTree.deleteNode(111);
    cout << endl << "после удаления элемента со зн. 11: "; intTree.inorderTraversal();

    if (intTree.search(51))
        cout << endl << "51 was found successfully";
    else
        cout << endl << "51 was not found";

    cout << endl;
    return 0;
}