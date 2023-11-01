#include<bits/stdc++.h>
using namespace std;

// At each iteration, the smallest element among the unsorted elements is placed at its position.
// It is an in-place sorting algorithm. (No extra space is required)
// It is not stable sorting algorithm. (Order of elements with equal values is not maintained)
// It can be stablised - https://www.geeksforgeeks.org/stable-selection-sort/
// TIme Complexity: O(n^2)

void selectionSort(vector<int>& v){
    int n = v.size();

    for(int i=0;i<n-1;i++){

        int mi = INT_MAX, idx = i;
        for(int j=i;j<n;j++){
            if(v[j]<mi){
                mi = v[j];
                idx = j;
            }
        }
        swap(v[i],v[idx]);
    }
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto & i:v) cin>>i;
    
    selectionSort(v);

    for(auto i:v) cout<<i<<" ";

    return 0;
}