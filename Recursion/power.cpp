#include<bits/stdc++.h>
using namespace std;

int power(int b, int p){
    if(p==0){                // Base condition
        return 1;
    }
    int ans = power(b,p-1);  // Calculation
    return b*ans;
}

int main(){
    int b,p; 
    cin>>b>>p;
    int ans = power(b,p);
    cout<<ans;
    return 0;
}