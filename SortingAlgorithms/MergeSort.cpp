#include<bits/stdc++.h>
using namespace std;

// It is not in-place sorting algorithm. (extra space is required)
// It is a stable sorting algorithm. (Order of elements with equal values is maintained)
// TIme Complexity : In all cases -  O(nlogn)  

void merge(int *ar, int s, int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int arr1[len1];
    int arr2[len2];

    // copy all the values
    int k =s;
    for(int i=0;i<len1;i++){
        arr1[i] = ar[k++];
    }

    k =mid+1;
    for(int i=0;i<len2;i++){
        arr2[i] = ar[k++];
    }

    // merge two arrays
    int idx1=0, idx2=0;
    k=s;

    while(idx1<len1 and idx2<len2){
        if(arr1[idx1] < arr2[idx2]){
            ar[k++] = arr1[idx1++];
        }
        else{
            ar[k++] = arr2[idx2++];
        }
    }

    while(idx1 < len1){
        ar[k++] = arr1[idx1++];
    }
    while(idx2 < len2){
        ar[k++] = arr2[idx2++];
    }

}


void mergeSort(int *ar, int s, int e){
    
    if(s>=e) return;

    int mid = s + (e-s)/2;

    // sort left part of array
    mergeSort(ar, s, mid);

    // sort right part of array
    mergeSort(ar, mid+1, e);

    merge(ar, s,e);
}

int main(){
    int n; cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    mergeSort(ar, 0 , n-1);

    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    return 0;
}