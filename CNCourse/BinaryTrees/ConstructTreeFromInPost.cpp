#include<iostream>
using namespace std;
#include "CommonFunctions.cpp"

int BinarySearch(int* arr, int s, int e, int k) {
    if (s > e) {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == k) {
        return mid;
    }
    else if (arr[mid] > k) {
        return BinarySearch(arr, s, mid - 1, k);
    }
    else {
        return BinarySearch(arr, mid + 1, e, k);
    }
}

BinaryTreeNode<int>* buildTreeHelper(int* post, int* in, int inS, int inE, int postS, int postE) {
    if (inS > inE) {
        return NULL;
    }
    int rootData = post[postE];
    int rootIndex = BinarySearch(in, inS, inE, rootData);//For index of root in Inorder
    // int rootIndex = -1;
    // for (int i = inS; i <= inE;i++) {
    //     if (in[i] == rootData) {
    //         rootIndex = i;
    //         break;
    //     }
    // }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPostS = postS;
    int lPostE = lPostS + lInE - lInS;

    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(post, in, lInS, lInE, lPostS, lPostE);
    root->right = buildTreeHelper(post, in, rInS, rInE, rPostS, rPostE);

    return root;
}

BinaryTreeNode<int>* buildTree(int* postOrder, int* inOrder, int size) {
    return buildTreeHelper(postOrder, inOrder, 0, size - 1, 0, size - 1);
}

int main() {
    int postOrder[] = { 4,5,2 ,6, 7, 3, 1 };
    int inOrder[] = { 4 ,2 ,5 ,1 ,6 ,3 ,7 };
    int size = sizeof(postOrder) / sizeof(postOrder[0]);
    BinaryTreeNode<int>* root = buildTree(postOrder, inOrder, 7);
    printLevelWise(root);
}