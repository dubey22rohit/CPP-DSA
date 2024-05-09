#include <iostream>

#include "CommonFunctions.h"
using namespace std;

int main() {
    BTNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    return 0;
}