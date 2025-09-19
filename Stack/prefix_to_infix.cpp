#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToInfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            string op(1, c);
            st.push(op);
        }
        else if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = "(" + op1 + string(1, c) + op2 + ")";
            st.push(exp);
        }
    }

    return st.top(); 
}

int main() {
    string prefix = "*+AB-CD";
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << prefixToInfix(prefix) << endl;
    return 0;
}
