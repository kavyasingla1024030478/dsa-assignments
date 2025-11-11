#include <iostream>
#include <climits>
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

class solution {
public:
    bool isValidBST(node* root, long long minVal, long long maxVal) {
        if (root == nullptr)
            return true;

        // Check current node value
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Recursively validate left and right subtrees
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};

int main() {
    // Create a valid BST
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->right = new node(8);

    solution sol;

    if (sol.isValidBST(root, LLONG_MIN, LLONG_MAX))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    return 0;
}
