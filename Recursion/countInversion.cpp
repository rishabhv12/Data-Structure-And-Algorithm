#include <bits/stdc++.h> 
using namespace std;


int merge(long long *arr, int s, int e){

    vector<long long> temp;
    int mid = s+ (e-s)/2;

    int left = s;
    int right = mid+1;
    int count =0;

    while(left <= mid && right <= e){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            // take all the element from left to mid bcz they all can be a pair
            temp.push_back(arr[right]);
            count += (mid-left+1);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= e) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i =s; i <=e; i++) {
        arr[i] = temp[i-s];
    }
    return count;
}


int mergeSort(long long *arr, int s, int e){

    int count =0;
    if(s>=e) return count;

    int mid = s+ (e-s)/2;
    
    count += mergeSort(arr, s, mid);
    count += mergeSort(arr, mid+1, e);
    count += merge(arr, s,e);
    return count;
}

int main(){
    // Write your code here.
    int n; cin>>n;
    long long arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    long long ans = mergeSort(arr, 0, n-1);
    cout<<ans;
    return 0;
}
