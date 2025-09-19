#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '/' || c == '^');
}
string postfix_to_infix(string postfix){
    stack<string>st;

    for(int i = 0; i < postfix.length(); i++){
        char c = postfix[i];
        if(isalnum(c)){
            string op(1,c);
            st.push(op);
        }
        else if(isOperator(c)){
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string exp = "(" + op1 + string(1,c) + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
}
int main(){
    string postfix = "ab+c";
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << postfix_to_infix(postfix) << endl;
    return 0;
}