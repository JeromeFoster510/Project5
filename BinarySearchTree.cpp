//Jerome Foster
//CSDP 250
/*Description: This program specifies a Binary Search Tree class, which includes 
functions for inserting and deleting nodes, displaying the tree in inorder and postorder, 
searching for a value, and determining whether the tree is an AVL tree, as well as balancing functions.*/

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;


BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::insertNode(TreeNode*& node, int value) {
    if (node == nullptr) {
        node = new TreeNode(value);
    }
    else if (value < node->value) {
        insertNode(node->leftptr, value);
    }
    else {
        insertNode(node->rightptr, value);
    }
}

void BinarySearchTree::removeNode(TreeNode*& node, int value) {
    if (node == nullptr) {
        return;
    }

    if (value < node->value) {
        removeNode(node->leftptr, value);
    }
    else if (value > node->value) {
        removeNode(node->rightptr, value);
    }
    else {
        if (node->leftptr == nullptr) {
            TreeNode* temp = node->rightptr;
            delete node;
            node = temp;
        }
        else if (node->rightptr == nullptr) {
            TreeNode* temp = node->leftptr;
            delete node;
            node = temp;
        }
        else {
            TreeNode* minNode = findMin(node->rightptr);
            node->value = minNode->value;
            removeNode(node->rightptr, minNode->value);
        }
    }
}

void BinarySearchTree::displayPostorder(TreeNode* node) const {
    if (node != nullptr) {
        displayPostorder(node->leftptr);
        displayPostorder(node->rightptr);
        cout << node->value << " ";
    }
}

void BinarySearchTree::displayInorder(TreeNode* node) const {
    if (node != nullptr) {
        displayInorder(node->leftptr);
        cout << node->value << " ";
        displayInorder(node->rightptr);
    }
}

void BinarySearchTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->leftptr);
        destroyTree(node->rightptr);
        delete node;
    }
}

void BinarySearchTree::addNode(int value) {
    insertNode(root, value);
}

void BinarySearchTree::deleteNode(int value) {
    removeNode(root, value);
}

void BinarySearchTree::searchTree(TreeNode* node, int value) const {
    if (node == nullptr) {
        cout << "Value " << value << " not found in the tree." << std::endl;
        return;
    }

    if (value == node->value) {
        cout << "Value " << value << " found in the tree." << std::endl;
    }
    else if (value < node->value) {
        searchTree(node->leftptr, value);
    }
    else {
        searchTree(node->rightptr, value);
    }
}


void BinarySearchTree::searchTree(int value) const {
    searchTree(root, value);
}



void BinarySearchTree::displayInorder() const {
    displayInorder(root);
    cout << endl;
}

void BinarySearchTree::displayPostorder() const {
    displayPostorder(root);
    cout << endl;
}

bool BinarySearchTree::isAVLTree() {
    return isBalanced(root);
}

int BinarySearchTree::height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = height(node->leftptr);
    int rightHeight = height(node->rightptr);
    return 1 + max(leftHeight, rightHeight);
}

int BinarySearchTree::balanceFactor(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->leftptr) - height(node->rightptr);
}

bool BinarySearchTree::isBalanced(TreeNode* node) {
    if (node == nullptr) {
        return true;
    }

    int balance = balanceFactor(node);

    if (abs(balance) > 1) {
        return false;
    }

    return isBalanced(node->leftptr) && isBalanced(node->rightptr);
}

BinarySearchTree::TreeNode* BinarySearchTree::rotateRight(TreeNode* y) {
    TreeNode* x = y->leftptr;
    TreeNode* T2 = x->rightptr;

    x->rightptr = y;
    y->leftptr = T2;

    return x;
}

BinarySearchTree::TreeNode* BinarySearchTree::rotateLeft(TreeNode* x) {
    TreeNode* y = x->rightptr;
    TreeNode* T2 = y->leftptr;

    y->leftptr = x;
    x->rightptr = T2;

    return y;
}

BinarySearchTree::TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    while (node->leftptr != nullptr) {
        node = node->leftptr;
    }
    return node;
}

