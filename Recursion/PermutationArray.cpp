#include<bits/stdc++.h>
using namespace std;


// Time complexity - O(!n * n), Space complexity - O(n + n)
void permutation_first(vector<int>& v, int n, vector<int>& ans, map<int,bool> mp){
    if(ans.size() == n){
        for(int i:ans) cout<<i<<" ";
        cout<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(mp[v[i]]==0){
            // Mark current element as taken
            mp[v[i]] = true;
            ans.push_back(v[i]);

            permutation_first(v, n, ans, mp);

            // Unmark current element before returning from the recursion
            ans.pop_back();
            mp[v[i]] = false;
        }
    }
}

// Time complexity - O(!n * n), Space complexity - O(1)
void permutation_sec(vector<int>& v, int n, int idx){
    if(idx == n){
        for(int i:v) cout<<i<<" ";
        cout<<endl;
        return;
    }

    for(int i=idx;i<n;i++){
        swap(v[idx], v[i]);
        permutation_sec(v, n, idx+1);

        // Before going to right recursion reswap the number to its origial position
        swap(v[idx], v[i]);
    }
}

int main(){
    int n; cin>>n;
    vector<int> ar(n);
    vector<int> ans;
    for(int &i:ar) cin>>i;
    map<int,bool> mp;

    permutation_first(ar, n, ans, mp);
    permutation_sec(ar, n, 0);
    return 0;
}