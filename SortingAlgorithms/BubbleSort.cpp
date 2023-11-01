#include<bits/stdc++.h>
using namespace std;

// At each iteration, the largest element among the unsorted elements is placed at the end.
// It is an in-place sorting algorithm. (No extra space is required)
// It is a stable sorting algorithm. (Order of elements with equal values is maintained)
// TIme Complexity: O(n^2)


void bubbleSort(vector<int>& v){
    int n = v.size();
    for(int i=0;i<n-1;i++){
        bool swp = false;
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]) {
                swap(v[j],v[j+1]);
                swp = true;
            }
        }
        if(swp==false) break;
    }
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto & i:v) cin>>i;
    
    bubbleSort(v);

    for(auto i:v) cout<<i<<" ";

    return 0;
}