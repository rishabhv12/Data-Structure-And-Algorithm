#include<bits/stdc++.h>
using namespace std;

bool binary(vector<int>& v, int key){
    int n = v.size();
    int l=0,r =n-1;

    while(l<=r){
        int mid = l + (r-l)/2;

        if(v[mid]==key) return true;
        else if(v[mid]>key){
            r = mid-1;
        }
        else l = mid+1;
    }
    return false;
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto & i:v) cin>>i;
    int target;
    cin>>target;

    cout<<binary(v,target);
    return 0;
}