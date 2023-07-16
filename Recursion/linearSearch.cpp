#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int *ar, int n, int key){
    if(n == 0){
        return false;
    }
    if(ar[0] == key) {
        return true;
    }
    
    else return linearSearch(ar+1, n-1 , key);
}

int main(){
    int n; cin>>n;

    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    int target; cin>> target;

    bool ans = linearSearch(ar, n, target);
    if(ans) cout<<"Found"<<endl;
    else cout<<"Not Found";
    return 0;
}