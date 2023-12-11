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


//  We create an upper and lower bound and root val must lies in between these bound

bool isBst(bstNode *root, int minVal, int maxVal){
    if(root == NULL) return true;

    if(root->data >=minVal && root->data < maxVal && 
        isBst(root->left, minVal, root->data) && isBst(root->right , root->data, maxVal))
        return true;
    
    else return false;
}


int main(){
    bstNode *root = NULL;
    root = InsertTree(root,8);
    root = InsertTree(root,6);
    root = InsertTree(root,10);
    root = InsertTree(root,5);
    root = InsertTree(root,7);
    root = InsertTree(root,9);
    root = InsertTree(root,12);

    // cout<<isBst(root, INT_MIN, INT_MAX)<<endl;
    cout<<(isBst(root, INT_MIN, INT_MAX) ? "YES" : "NO")<<endl;
}