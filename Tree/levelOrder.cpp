#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

};


vector<vector<int>> levelOrder(TreeNode* root){

    vector<vector<int>> ans;
    vector<int> level;
    queue<TreeNode*> q;

    if(root == NULL) return ans;

    q.push(root);
    q.push(NULL);

    while(q.size() != 0){
        TreeNode *temp = q.front();
        q.pop();

        if(temp == NULL){
            ans.push_back(level);
            level.clear();

            if(q.size() != 0)
                q.push(NULL);
        }
        else{
            level.push_back(temp->val);

            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
            
        }
    }
    return ans;
}


int main(){

    return 0;
}