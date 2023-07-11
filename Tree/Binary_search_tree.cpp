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

//  Search in BST
bool Search(bstNode *root, int key){
    if(root == NULL) return false;
    else if(root->data = key) return true;
    else if(key <= root->data) return Search(root->left, key);
    else return Search(root->right, key);
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


    int num; cin>>num;
	if(Search(root,num) == true) cout<<"Present in tree";
	else cout<<"Not prsent in tree";
}