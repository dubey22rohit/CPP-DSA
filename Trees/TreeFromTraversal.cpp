#include <iostream>
using namespace std;

// If we're only give one single traversal(ie one of pre,post or inorder), we
// cannot generate a unique tree.
//  We'll generate Catalan's number(2nCn/n+1) of trees with only a single
//  traversal given

/*
 * Even pre-order + post-order will not give us unique trees
 * TO generate unique tree from traversal, we need INORDER to be given with
 * either pre or post-order SO Either,
 *  Pre-Order + In-Order OR Post-Order +  In-Order
 * TC : O(n2)
 */

int main() { return 0; }