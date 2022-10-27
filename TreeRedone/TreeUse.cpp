#include <iostream>

#include "TreeClass.h"
using namespace std;

int main() {
    Tree root;
    BTNode *bt = root.CreateTree();

    cout << "Preorder : ";
    root.Preorder(bt);
    cout << endl;

    cout << "Inorder : ";
    root.Inorder(bt);
    cout << endl;

    cout << "Postorder : ";
    root.Postorder(bt);
    cout << endl;

    cout << "Height : " << root.Height(bt);
    cout << endl;

    cout << "Number of nodes : " << root.CountNodes(bt);
    cout << endl;

    return 0;
}