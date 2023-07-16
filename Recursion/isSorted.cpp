#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *ar, int n){
    if(n == 0 or n == 1){
        return true;
    }

    if(ar[0] <= ar[1]) {
        return isSorted(ar+1, n-1);
    }
    
    else return false;

}

int main(){
    int n; cin>>n;

    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];

    bool ans = isSorted(ar, n);
    if(ans) cout<<"Sorted"<<endl;
    else cout<<"Not Sorted";
    return 0;
}