#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<n<<endl;
}

void rprint(int n){
    if(n==0) return;
    rprint(n-1);
    cout<<n<<endl;
}

int main(){
    int n = 5;
    print(n);
    return 0;
}