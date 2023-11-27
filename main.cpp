//Jerome Foster
//CSDP 250
/*Description: This C++ software creates a Binary Search Tree, fills it with 35 random numbers, 
displays the tree, searches for and deletes a user-specified value, 
and determines whether the resulting tree is an AVL tree, displaying the results at each step.*/

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main() {
    BinarySearchTree bst;

   
    for (int i = 0; i < 35; ++i) {
        int randomNumber = rand() % 100;
        bst.addNode(randomNumber);
    }

    cout << "Binary Search Tree (Inorder Traversal): ";
    bst.displayInorder();

    
    int valueToSearch;
    cout << "Enter a value to search in the tree: ";
    cin >> valueToSearch;

    bst.searchTree(valueToSearch);

   
    cout << "Deleting value " << valueToSearch << " if found..." << endl;
    bst.deleteNode(valueToSearch);

    cout << "Updated Tree (Postorder Traversal): ";
    bst.displayPostorder();

   
    if (bst.isAVLTree()) {
        cout << "The tree is an AVL tree." << std::endl;
    }
    else {
        cout << "The tree is not an AVL tree." << std::endl;
    }

    return 0;
}

