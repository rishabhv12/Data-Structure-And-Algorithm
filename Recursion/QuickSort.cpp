#include<bits/stdc++.h>
using namespace std;

int partition(int *ar, int s, int e){

    int pivot = ar[s];

    // Check how many element on the right are greater than pivot
    int cnt =0;
    for(int i=s+1;i<=e;i++){
        if(pivot > ar[i]) cnt++;
    }

    // Find right place of pivot element
    int pivotIndex = s+cnt;
    swap(ar[pivotIndex], ar[s]);

    // place element to left if it is less than pivot and greater to right of pivot

    int i =s, j =e;
    while(i<pivotIndex and j> pivotIndex){

        while(ar[i]<= pivot) i++;
        
        while(ar[j]> pivot) j--;

        if(i<pivotIndex and j> pivotIndex){
            swap(ar[i], ar[j]); 
            i++; j--;
             
        }
    }
    return pivotIndex;

}


void quickSort(int *ar, int s, int e){
    
    if(s>=e) return;


    int pIndex = partition(ar, s, e);

    // sort left part of array
    quickSort(ar, s, pIndex);

    // sort right part of array
    quickSort(ar, pIndex+1, e);

}

int main(){
    int n; cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    quickSort(ar, 0 , n-1);

    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    return 0;
}