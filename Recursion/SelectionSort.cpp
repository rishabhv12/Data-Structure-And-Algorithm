#include<bits/stdc++.h>
using namespace std;

void selection(int *ar, int n){
    if(n==0 or n==1) return;

    // Place smallest element at index 0
    int mi=INT_MAX, idx =0;
    for(int i=0;i<n;i++){
        if(ar[i]<mi){
            idx = i;
            mi = ar[i];
        }
    }
    
    swap(ar[0],ar[idx]);

    // It will place nth smallest element to its actuall position
    selection(ar+1, n-1);
}

int main(){
    int n; cin>>n;

    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    selection(ar, n);

    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    return 0;
}