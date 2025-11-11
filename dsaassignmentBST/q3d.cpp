//minimum depth of bst


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    // Function to find minimum depth (recursive)
int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    // If leaf node
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    // If left subtree is NULL, recur for right subtree
    if (root->left == nullptr)
        return 1 + minDepth(root->right);

    // If right subtree is NULL, recur for left subtree
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    // If both subtrees exist, take the smaller one
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
};

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    

    Solution solution;
    int depth = solution.minDepth(root);

    cout << "Minimum depth of the binary tree: " << depth << endl;

    return 0;
}