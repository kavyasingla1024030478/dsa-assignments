#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node{
public:

    int data;
    node*left;
    node*right;

    node(int val)
    {
        data=val;
        left=right=nullptr;
    }

};


void preorder(node* root, vector<int> &arr){
        
        if(root == nullptr){
            return;
        }
        arr.push_back(root->data);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }

    
void inorder(node* root, vector<int> &arr){
        
        if(root == nullptr){
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    
void postorder(node* root, vector<int> &arr){
        
        if(root == nullptr){
            return;
        }
       
        postorder(root->left, arr);
        postorder(root->right, arr);
         arr.push_back(root->data);
    }
    // Function to initiate preorder traversal
    // and return the resulting vector

    vector<int> preOrder(node* root){
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }



    vector<int> inOrder(node* root){
        vector<int> arr;
        inorder(root, arr);
        return arr;
    }

    
    vector<int> postOrder(node* root){
        vector<int> arr;
        postorder(root, arr);
        return arr;
    }



int main()
{

   node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);


    // Getting preorder traversal
    vector<int> pre = preOrder(root);
    vector<int> in = inOrder(root);
    vector<int> post = postOrder(root);


    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for(int val : pre) {
        cout << val << " ";
    }
    cout << endl;

// Displaying the postorder traversal result
    cout << "Postorder Traversal: ";
    for(int val : post) {
        cout << val << " ";
    }
    cout << endl;


// Displaying the inorder traversal result
    cout << "inorder Traversal: ";
    for(int val : in) {
        cout << val << " ";
    }
    cout << endl;




    return 0;
}