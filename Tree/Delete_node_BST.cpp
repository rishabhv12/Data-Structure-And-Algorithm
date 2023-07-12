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

bstNode *FindMin(bstNode *root){
    // if(root == NULL) return root;

    bstNode *temp = root;

    // Go to the end of left side 
    while(temp->left ){
        temp = temp->left;
    }
    return temp;
    
}

bstNode *Delete(bstNode *root, int val){
    if(root == NULL) return root;

    //  Find the given Node
    else if(val < root->data) root->left = Delete(root->left, val);
    else if(val > root->data) root->right = Delete(root->right, val);

    //  When we found the given node
    else{

        //  If no left and right child are present
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }

        //  If only right child is present
        else if(root->left == NULL){
            bstNode *temp = root;
            root = root->right;
            delete temp;
        }

        // If only left child is present
        else if(root->right == NULL){
            bstNode *temp = root;
            root = root->left;
            delete temp;
        }

        // If both childs are present 
        else{
            bstNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
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

    int val = 2;
    root = Delete(root, val);

    preorder(root);


}