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


//  Number if edeges in the longest path from that node to a leaf in called height of the node 
//  Height of tree = height of the root

int Height(bstNode *root){
    // If root is not present
    if(root == NULL) return -1;


    // Max height of left leaf
    int left = Height(root->left);

    // Max height of right leaf
    int right = Height(root->right);

    return max(left,right)+1;
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

    cout<<Height(root)<<endl;

}