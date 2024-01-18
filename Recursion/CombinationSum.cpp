// https://leetcode.com/problems/combination-sum/


#include<bits/stdc++.h>
using namespace std;

// Time complexity - O(2^n) *k       (k -> DS into DS)
void subsequeceSum(vector<int>& v,int n, int idx, vector<vector<int>>&ans, vector<int>& temp, int target){
    if(idx == n){
        if(target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if(v[idx]<=target){
        temp.push_back(v[idx]);
        subsequeceSum(v,n,idx,ans,temp,target-v[idx]);
        temp.pop_back();
    }

    subsequeceSum(v,n,idx+1,ans,temp,target);
}


// https://leetcode.com/problems/combination-sum-ii/
// We connot use above solution bcz the complexity will be O(2^n) *k(logn) ..extra logn bcz of set 

// Time complexity - O(2^n) *k 
void subsequeceSumSec(int idx, vector<int> &ar, int n,vector<int>& curr, int sum,set<vector<int>>& st){
        
    if(sum == 0){
        // for(int i:curr) cout<<i<<" ";
        // cout<<endl;
        st.insert(curr);
        return;
    }

    for (int i = idx; i < n; i++) {
        if (i > idx && ar[i] == ar[i - 1]) continue;
        if (ar[i] > sum) break;
        curr.push_back(ar[i]);
        subsequeceSumSec(i + 1, ar, n, curr, sum-ar[i], st);
        curr.pop_back();
    }
}

int main(){
    int n; cin>>n;
    vector<int> v(n), temp;
    vector<vector<int>> ans;

    for(int &i:v) cin>>i;
    int sum; cin>>sum;

    subsequeceSum(v,n,0,ans,temp,sum);
    for(auto i:ans){
        for(int j:i) cout<<j<<" ";
        cout<<endl;
    }

    cout<<endl;
    sort(v.begin(),v.end());
    set<vector<int>> res;
    subsequeceSumSec(0, v, n, temp, sum, res);
    for(auto i:res){
        for(int j:i) cout<<j<<" ";
        cout<<endl;
    }
    
}