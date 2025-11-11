//inorder predecessor

#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;

    node(int data) {
        val = data;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Find inorder predecessor iteratively
    node* inorderPredecessor(node* root, node* p) {
        node* predecessor = nullptr;

        while (root != nullptr) {
            // If p's value is less or equal, go left (since predecessor is smaller)
            if (p->val <= root->val) {
                root = root->left;
            }
            // Otherwise, update predecessor and move right
            else {
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};

// inorder traversal for checking tree structure
void printInOrder(node* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Construct BST
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->right = new node(7);

    // Show inorder
    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    // Choose a target node (for example, 4)
    node* p = root->left->right; // node with value 4

    // Find predecessor
    Solution solution;
    node* predecessor = solution.inorderPredecessor(root, p);

    // Print result
    if (predecessor != nullptr) {
        cout << "Inorder Predecessor of " << p->val << " is: " << predecessor->val << endl;
    } else {
        cout << "Inorder Predecessor of " << p->val << " does not exist." << endl;
    }

    return 0;
}
