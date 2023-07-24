#include<bits/stdc++.h>
using namespace std;

void bubble(int *ar, int n){
    if(n==0 or n==1) return;

    // Place largest element to last of the array (solved one case)
    for(int i=0;i<n-1;i++){
        if(ar[i]>ar[i+1]) swap(ar[i],ar[i+1]);
    }

    // It will place n-1th largest element to its actuall position
    bubble(ar, n-1);
}

int main(){
    int n; cin>>n;

    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    bubble(ar, n);

    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    return 0;
}