#include<bits/stdc++.h>
using namespace std;

// Check for operator precedence

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}


// Convert infix expression to prefix

string infixToPrefix(string s) {
    stack<char> st;
    string ans = "";
    set<char> sign{'-', '+', '/', '*'};
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
        // If current char is operand, add it to the answer string
        if (sign.find(s[i]) == sign.end()) {
            ans += s[i];
        } else {
            // Remove operators from stack until there is an operator of higher precedence or the stack is empty
            while (!st.empty() && precedence(st.top())>precedence(s[i])) {
                ans += st.top();
                st.pop();
            }
            // Push the current operator to the stack
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


int main() {
    string s;
    cin >> s;
    string res = infixToPrefix(s);
    cout << res << endl;

    return 0;
}
