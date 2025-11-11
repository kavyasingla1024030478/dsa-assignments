//insert an element in bst


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

node*insertintobst(node*root,int key)
{
    if(root==nullptr)
    return new node(key);

    node*curr=root;

    while(true)
    {
        if(curr->val<=key)
        {
            if(curr->right!=nullptr)
            curr=curr->right;
            else
            {
                curr->right=new node(key);
                break;
            }
        }

        else
        {
            if(curr->left!=NULL)
            curr=curr->left;
            else
            {
                curr->left=new node(key);
                break;
            }

        }


    }
return root;
}

// inorder traversal for checking tree structure
void printInOrder(node* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}


int main()
{
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



    root=insertintobst(root,1);

    
      cout << "updated BST: ";
    printInOrder(root);
    cout << endl;



    return 0;
}