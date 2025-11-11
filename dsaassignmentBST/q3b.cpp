//delete a node of bst


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

class solution{
public:

node*deletenode(node*root,int key)
{
    if(root==NULL)
    return NULL ;

    if(root->val==key)
    return helper(root);


    node*dummy=root;
    while(root!=NULL)
    {
        if(root->val>key)
        {
            if(root->left!=NULL&&root->left->val==key)
            {
                root->left=helper(root->left);
                break;
            }

            else
            {root=root->left;}
        }



        else{

            if(root->right!=NULL&&root->right->val==key)
            {
              root->right=helper(root->right);
                break;

            }
            else{
                root=root->right;
            }

        }
    }
return dummy;
}


node*helper(node*root)
{
    if(root->left==NULL)
    {
        return root->right;
    }
    else if (root->right==NULL)
    {
       return root->left;
    }
    
node*rightChild=root->right;
node*lastright=findlastright(root->left);
lastright->right=rightChild;
return root->left;

}

node*findlastright(node*root)
{

    if(root->right==NULL)
    return root;

    return findlastright(root->right);
}

};


//inorder traversal for checking tree structure
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

    solution sol;

    // Show inorder
    cout << "BST: ";
    printInOrder(root);
    cout << endl;



    root=sol.deletenode(root,4);

    
      cout << "updated BST: ";
    printInOrder(root);
    cout << endl;



    return 0;
}