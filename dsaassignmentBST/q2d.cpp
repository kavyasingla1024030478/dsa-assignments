//inorder successor
#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class node{
public:

    int val;
    node*left;
    node*right;

    node(int data)
    {
        val=data;
        left=right=nullptr;
    }

};


class Solution {
public:
    // find inorder successor iteratively
    node* inorderSuccessor(node* root, node* p) {
        // initialize successor
        node* successor = nullptr;
        // traverse until root becomes null
        while (root != nullptr) {
            // when p is greater or equal, move right
            if (p->val >= root->val) {
                root = root->right;
            }
            // otherwise update successor and move left
            else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};

// inorder print helper
void printInOrder(node* root) {

    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}


int main() {
    // construct BST
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->right = new node(7);

    // show inorder
    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    // target node p
    node* p = root->left->right;

    // find successor
    Solution solution;
    node* successor = solution.inorderSuccessor(root, p);

    // print result
    if (successor != nullptr) {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } else {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    // exit
    return 0;
}