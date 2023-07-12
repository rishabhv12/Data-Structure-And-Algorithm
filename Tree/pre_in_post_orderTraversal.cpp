//  Preoder, inorder and postorder traversal came under Depth-first search 
//  Time complexity - O(n)
//  Space complexity - best/average - O(log(n)) - height of the tree , worst case - O(n)


#include<bits/stdc++.h>
using namespace std;


// Structure of Binary Search Tree
struct bstNode{
    int data;
    bstNode *left = NULL;
    bstNode *right = NULL;
};


// Insert value in bst
bstNode* InsertTree(bstNode *root, int val){
    bstNode *temp = new bstNode();
    temp->data = val;

    //  If tree in empty
    if(root == NULL){
        root = temp;
    }

    //  If value is less then or equal to root then insert to left of the tree
    else if(val <= root->data){
        root->left = InsertTree(root->left, val);
    }

    //  If value is greater then root then insert to right of the tree    
    else {
        root->right = InsertTree(root->right, val);
    }
    return root;
}


//  Preorder -->  root -> left tree -> right tree
void preorder(bstNode *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


//  Inorder -->  left tree -> root -> right tree
void inorder(bstNode *root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


//  Postorder -->  left tree -> right tree -> root
void postorder(bstNode *root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    bstNode *root = NULL;
    root = InsertTree(root,8);
    root = InsertTree(root,2);
    root = InsertTree(root,9);
    root = InsertTree(root,6);
    root = InsertTree(root,5);
    root = InsertTree(root,1);
    root = InsertTree(root,7);

    preorder(root);
    cout<<endl;

    inorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;

}