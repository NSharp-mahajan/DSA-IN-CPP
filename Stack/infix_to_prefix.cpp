#include<iostream>
#include<stack>
using namespace std;

int precedence(char c){
    if(c == '^') return 3;
    if(c == '/' || c == '*') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

string infix_to_postfix(string s){
    stack<char> st;
    string output = "";
    for(char ch:s){
        if(isalnum(ch)){
            output+=ch;
        }else if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                output += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && precedence(st.top()) >= precedence(ch)){
                output+=st.top();
                st.pop();
                st.push(ch);
            }
        }
        while(!st.empty()){
            output += st.top();
            st.pop();
        }
    }
    return output;
}
string infix_to_prefix(string s){
    reverse(s.begin(), s.end());
    for(int i = 0; i < size(); i++){
        if(s[i] == '(') s[i] = '(';
        else if(s[i] == '(');
    }
    string postfix = infix_to_postfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
int main(){
    string exp = "(A+B)*C - (D + P)";
    cout << "Prefix: " << infix_to_prefix(exp) << endl;
}