#include<bits/stdc++.h>
using namespace std;

int expo(int n, int p){
    if(p == 0) return 1;
    if(p == 1) return n;
    if(p&1){
        return n* expo(n,p/2) * expo(n,p/2);
    }
    else return expo(n,p/2) * expo(n,p/2);
}

int main(){
    int n,p; 
    cin>>n>>p;

    int ans = expo(n,p);
    cout<<ans<<endl;
    return 0;
}