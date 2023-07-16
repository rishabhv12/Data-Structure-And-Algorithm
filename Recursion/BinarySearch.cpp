#include<bits/stdc++.h>
using namespace std;

void BinarySearch(int *ar, int l, int r, int target){
    if(l>r){
        cout<<"Not Present"<<endl;
        return;
    }
    int mid = l+ (r-l)/2; 

    if(ar[mid]== target){
        cout<<"Present"<<endl;
        return;
    }

    if(ar[mid] > target){
        return BinarySearch(ar, l, mid-1, target);
    }

    else if(ar[mid] < target){
        return BinarySearch(ar, mid+1, r, target);
    }
}

int main(){
    int n; cin>>n;

    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];

    int target; cin>>target;

    BinarySearch(ar, 0, n-1, target);

    return 0;
}