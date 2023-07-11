#include<bits/stdc++.h>
using namespace std;

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



vector<vector<int>> levelOrder(bstNode* root){

    vector<vector<int>> ans;
    vector<int> level;
    queue<bstNode*> q;

    if(root == NULL) return ans;

    q.push(root);
    q.push(NULL);

    while(q.size() != 0){
        bstNode *temp = q.front();
        q.pop();

        if(temp == NULL){
            ans.push_back(level);
            level.clear();

            if(q.size() != 0)
                q.push(NULL);
        }
        else{
            level.push_back(temp->data);

            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
            
        }
    }
    return ans;
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

    vector<vector<int>> traverse = levelOrder(root);
    for(auto i:traverse){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}