#include<bits/stdc++.h>
using namespace std;

void sayDigit(int n){
    string ar[] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if(n==0){
        return;
    }

    //  The current digit
    int digit = n%10;
    sayDigit(n/10);

    cout<<ar[digit]<<" ";
}


int main(){
    int n; cin>>n;

    sayDigit(n);
    return 0;
}