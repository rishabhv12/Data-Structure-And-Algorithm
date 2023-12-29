#include<bits/stdc++.h>
using namespace std;

void subsequece(int idx,int n, vector<int> &ar, vector<int> &ans){
    if(idx >= n){
        // cout<<ans.size()<<endl;
        for(int i:ans) cout<<i<<" ";
        if(ans.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }

    // Condition for taking current element
    ans.push_back(ar[idx]);
    subsequece(idx+1, n, ar, ans);

    // Condition for not taking current element
    ans.pop_back();
    subsequece(idx+1, n, ar, ans);

}
int main(){
    int n; cin>>n;
    vector<int> ar(n);
    for(int &i:ar) cin>>i;

    vector<int> ans;
    subsequece(0,n,ar,ans);
    return 0;
}