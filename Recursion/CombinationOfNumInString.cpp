//  We have given a string of number and you have to create combination with spaces 


#include<bits/stdc++.h>
using namespace std;

void combine(string s, string out, int idx){
    if(idx == s.size()){
        cout<<out<<endl;
        return;
    }
    
    char currNum = s[idx];
    // No space - put charecter without space
    out.push_back(currNum);

    combine(s, out, idx+1);

    out.push_back(' ');

    // add space - put charecter with space only if next char is not null
    if(idx+1 != s.size())             // s[i+1] != '\0' 
    combine(s, out, idx+1);
}

int main(){
    string s; cin>>s;

    string ans ="";
    combine(s, ans, 0);
    return 0;
}