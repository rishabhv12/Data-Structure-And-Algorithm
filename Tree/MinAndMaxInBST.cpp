#include<bits/stdc++.h>
using namespace std;


struct bstNode{
    int data;
    bstNode *left = NULL;
    bstNode *right = NULL;
};

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

//  Maximum value in BST
int Max_value(bstNode *root){
    if(root == NULL){
        cout<<"Error"<<endl;
        return -1;
    } 
    bstNode *temp = root;

    // Go to the end of right side 
    while(temp->right){
        temp = temp->right;
    }
    return temp->data;
}


//  Minimum value in BST
int Min_value(bstNode *root){
    if(root == NULL){
        cout<<"Error"<<endl;
        return -1;
    }
    bstNode *temp = root;

    // Go to the end of left side 
    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
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

    if(Max_value(root) != -1) cout<<"Maximum value in tree is : "<<Max_value(root)<<endl;
    if(Min_value(root) != -1) cout<<"Minimum value in tree is : "<<Min_value(root)<<endl;
    
    return 0;
}
