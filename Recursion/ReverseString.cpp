#include<bits/stdc++.h>
using namespace std;


void reverseString(string &s, int i=0){
    if(i==s.size()/2){
        return;
    }

    swap(s[i], s[s.size()-i-1]);
    reverseString(s, ++i);
}

int main(){
    string s; 
    cin>>s;

    reverseString(s);
    cout<<s<<endl;
    return 0;
}