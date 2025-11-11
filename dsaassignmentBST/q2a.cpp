#include<iostream>
#include<bits/stdc++.h>

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
   
    node* searchBSTrecursive(node* root, int key){
        // Loop until either the tree is
        // exhausted (NULL) or the value is found.
        while(root != NULL && root->val != key){
            root = key < root->val ? root->left : root->right;
        }
        
        return root;
    }


 bool searchnonrecursive(node* root, int key) {
    node* temp = root;

    while (temp != nullptr) {
        if (temp->val == key)
            return true;  // Key found
        else if (key < temp->val)
            temp = temp->left;  // Move left
        else
            temp = temp->right; // Move right
    }

    return false; // Key not found
}



};

void printInOrder(node* root) {

    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}
   

int main() {
    // Creating a BST
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(8);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(10);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 6;
    node* result = solution.searchBSTrecursive(root, target);

    // Displaying the search result
    if (result != nullptr) {
        cout << "Value " << target << " found in the BST!" << endl;
    } else {
        cout << "Value " << target << " not found in the BST." << endl;
    }
    

    if (solution.searchnonrecursive(root, target))
        cout << "Element " << target << " found in BST." << endl;
    else
        cout << "Element " << target << " not found in BST." << endl;

    return 0;
}