#include<bits/stdc++.h>
using namespace std;

void subsequeceSum(int idx, vector<int> &ar, int n,vector<int> &curr, int sum,int req){
    if(idx == n){
        if(sum == req){
            for(int i:curr) cout<<i<<" ";
            cout<<endl;
        }
        return;
    }

    // pick current element
    curr.push_back(ar[idx]);
    sum += ar[idx];
    subsequeceSum(idx+1, ar, n, curr, sum, req);

    // not pick current element
    curr.pop_back();
    sum -= ar[idx];

    subsequeceSum(idx+1, ar, n, curr, sum, req);
}

bool oneSubSum(int idx, vector<int> &ar, int n, vector<int> &curr, int sum, int req){
    if(idx == n){
        if(sum == req){
            for(int i:curr) cout<<i<<" ";
            cout<<endl;
            return true;
        }
        else return false;
    }

    // pick current element
    curr.push_back(ar[idx]);
    sum += ar[idx];

    if(oneSubSum(idx+1, ar, n, curr, sum, req) == true) return true;

    // not pick current element
    curr.pop_back();
    sum -= ar[idx];
    if(oneSubSum(idx+1, ar, n, curr, sum, req) == true) return true;

    return false;

}

int numSubSum(int idx, vector<int> &ar, int n, int sum, int req){
    if(idx == n){
        if(sum == req){
            return 1;
        }
        else return 0;
    }

    // pick the element
    sum += ar[idx];
    int l = numSubSum(idx+1, ar, n, sum, req);

    // not pick the element
    sum -= ar[idx];
    int r = numSubSum(idx+1, ar, n, sum, req);

    return l+r;

}
int main(){
    int n; cin>>n;
    vector<int> ar(n);

    for(int &i:ar) cin>>i;
    int sum; cin>>sum;
    vector<int> ans;
    // subsequeceSum(0, ar, n, ans, 0, sum);

    // oneSubSum(0, ar, n, ans, 0, sum);

    cout<<numSubSum(0, ar, n, 0, sum)<<endl;
    return 0;
}