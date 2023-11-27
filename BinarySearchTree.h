//Jerome Foster
//CSDP 250
/*This header file specifies a Binary Search Tree class, as well as private functions for insertion, 
deletion, and balancing, and public functions for adding, deleting, and displaying nodes,
searching for values, and determining whether the tree is an AVL tree.*/

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

class BinarySearchTree {
private:
    struct TreeNode {
        int value;
        TreeNode* leftptr;
        TreeNode* rightptr;

        TreeNode(int val) : value(val), leftptr(nullptr), rightptr(nullptr) {}
    };

    TreeNode* root;

    void insertNode(TreeNode*&, int);
    void removeNode(TreeNode*&, int);
    void displayPostorder(TreeNode*) const;
    void displayInorder(TreeNode*) const;
    void searchTree(TreeNode*, int) const;
    void destroyTree(TreeNode*);

    TreeNode* findMin(TreeNode*);

    int height(TreeNode*);  
    int balanceFactor(TreeNode*);
    bool isBalanced(TreeNode*);
    TreeNode* rotateRight(TreeNode*);
    TreeNode* rotateLeft(TreeNode*);
   
    

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void addNode(int);
    void deleteNode(int);
    void displayInorder() const;
    void displayPostorder() const;
    void searchTree(int) const;
    bool isAVLTree();
};

#endif



