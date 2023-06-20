#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==0) return;
    cout<<n<<endl;
    print(n-1);
}

void rprint(int n){
    if(n==0) return;
    rprint(n-1);
    cout<<n<<endl;
}

int main(){
    int n = 5;
    rprint(n);
    return 0;
}