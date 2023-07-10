#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

// Check for operator precedence 
bool comp(char a, char b) {
    vector<char> ar{'-', '+', '/', '*'};
    int f, s;
    for (int i = 0; i < 4; i++) {
        if (ar[i] == a){
            f = i;
        }
            
        else if (ar[i] == b){
            s = i;
        }
           
    }
    if (f > s) return true;
    else return false;
}

// Convert infix expression to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";

    set<char> sign{'-', '+', '/', '*','{','}','[',']','(',')'};

    for (int i = 0; i < s.size(); i++) {
        // If the current char is an operand, add it to the answer string
        if (sign.find(s[i]) == sign.end()) {
            ans += s[i];
        } 
        else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } 
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            while (!st.empty() && (st.top() != '(' && st.top() != '{' && st.top() != '[')) {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } 
        else {
            // Remove operators from the stack until there is an operator of higher precedence present in the stack
            while (!st.empty() && (st.top() != '(' && st.top() != '{' && st.top() != '[') && comp(st.top(), s[i])) {
                ans += st.top();
                st.pop();
            }
            // Pushing current operator
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    string res = infixToPostfix(s);
    cout << res << endl;

    return 0;
}
