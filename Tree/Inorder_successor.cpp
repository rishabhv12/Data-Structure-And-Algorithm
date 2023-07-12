//  Inorder successor of a node is the next value in the sorted list of given numbers
//  Time complexity - O(h) = O(log(n) )

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


bstNode* Find(bstNode*root, int val) {
	if(root == NULL) return NULL;

	if(root->data == val) return root;
	else if(root->data < val) return Find(root->right,val);
	else return Find(root->left,val);
}

bstNode* FindMin(bstNode* root) {
	if(root == NULL) return NULL;

	while(root->left != NULL){
        root = root->left;
    }

	return root;
}



bstNode *Successor(bstNode *root, int val){
    if(root == NULL){
        cout<<"Tree is empty"<<endl;
        return NULL;
    }

    bstNode* current = Find(root, val);
    
	if(current == NULL) return NULL;

    //Case 1: Node has right subtree
	if(current->right != NULL) {  
		return FindMin(current->right);
	}

    //Case 2: No right subtree
	else {   
		bstNode* successor = NULL;
		bstNode* ancestor = root;

		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
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

    int val = 5;
    bstNode *ans = Successor(root, val);

    cout<<ans->data<<endl;
}