#include<bits/stdc++.h>
using namespace std;


// Check for operator presidence 
bool comp(char a, char b){
    vector<char> ar{'-','+','/','*'};
    int f,s;
    for(int i=0;i<4;i++){
        if(ar[i]==a) f=i;
        else if(ar[i]==b) s=i;
    }
    if(f>s) return 1;
    else return 0;

}

// Convert infix expression to postfix
string infixToPostfix(string s){
    stack<char> st;
    string ans = "";        

    set<char> sign{'-','+','/','*'};
    
    for(int i=0;i<s.size();i++){
        // If current char is operand then add this char to answer string
        if(sign.find(s[i])==sign.end()){
            ans += s[i];
        }
        else{

            // Remove operator from stack untill there is operator of higher precedence present in stack
            while(!st.empty() && comp(st.top(),s[i])){
                ans += s[i];
                st.pop();
            }

            // Pushing current operator
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}


int main(){
    string s;
    cin>>s;
    string res = infixToPostfix(s);
    cout<<res<<endl;

    return 0;
}