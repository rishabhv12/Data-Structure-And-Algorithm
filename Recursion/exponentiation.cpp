#include<bits/stdc++.h>
using namespace std;

int expo(int n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(n&1){
        return 2* expo(n/2) * expo(n/2);
    }
    else return expo(n/2) * expo(n/2);
}

int main(){
    int n; 
    cin>>n;
    
    int ans = expo(n);
    cout<<ans<<endl;
    return 0;
}