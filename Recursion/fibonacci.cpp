#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    return fib(n-1)+fib(n-2);    
     
}

//  0 1 1 2 3 5 8 13 21 34 


int main(){
    int n; cin>>n;
    int ans = fib(n);
    cout<<ans;
    return 0;
}