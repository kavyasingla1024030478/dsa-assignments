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


void printInOrder(node* root) {

    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int findMax(node* root) {
    if (root == nullptr) {
        // Handle empty tree case, return an appropriate value or throw an exception
        return -1;
    }
    if (root->right == nullptr) {
        return root->val;
    }
    return findMax(root->right);
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

    int maximumelement=findMax(root);

    cout<<"the max element of bst is: "<<maximumelement<<endl;

    return 0;
}