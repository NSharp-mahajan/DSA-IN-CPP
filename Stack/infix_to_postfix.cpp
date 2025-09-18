#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/') 
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

string infix_to_postfix(string s){
    stack<char>st;
    string ans = "";
    for(int i = 0; i < s.length(); i++){
        char c = s[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            ans += c;
        }
        else if(c == '('){
            st.push(c);
        }else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && precedence(c) <= precedence(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string infix = "A*(B+C)/D";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infix_to_postfix(infix) << endl; 
    return 0; 
}