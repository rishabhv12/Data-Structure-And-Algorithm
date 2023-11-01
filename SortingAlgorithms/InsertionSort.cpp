#include<bits/stdc++.h>
using namespace std;

// It is used for small number of elements.
// It is an in-place sorting algorithm. (No extra space is required)
// It is a stable sorting algorithm. (Order of elements with equal values is maintained)
// TIme Complexity: O(n^2)

void insertionSort(vector<int>& v){
    int n = v.size();
    for(int i=1;i<n;i++){
        int key = v[i];
        int j = i-1;
        while(j>=0 && v[j]>key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto & i:v) cin>>i;
    
    insertionSort(v);

    for(auto i:v) cout<<i<<" ";

    return 0;
}