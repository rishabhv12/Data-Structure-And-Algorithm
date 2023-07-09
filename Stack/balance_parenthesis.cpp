#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    
    stack<char> st;

    for(int i=0;i<s.size();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return 0;
            char c = st.top();
            
            if(c=='{' && s[i]=='}') st.pop();
            else if(c=='(' && s[i]==')') st.pop();
            else if(c=='[' && s[i]==']') st.pop();
            else {
                cout<<"Error";
                return 0;
            }
        }
    }
    if(!st.empty()) cout<<"Error";
    else cout<<"Processed"<<endl;
    return 0;
}