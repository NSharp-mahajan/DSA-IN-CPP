#include<iostream>
using namespace std;
#include<stack>
#include<queue>

bool isPal(queue<int>q){
    stack<int>st;
    int n = q.size();
    
    for(int i = 0; i < n; i++){
        int temp = q.front();
        q.pop();
        st.push(temp);
        q.push(temp);
    }
    for(int i = 0; i < n; i++){
        int frontElement = q.front();
        int stackElement = st.top();
        if(frontElement != stackElement){
            return false;
        }
        st.pop();
        q.pop();
        q.push(frontElement);
    }
    return true;
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(3);
    q.push(2);
    q.push(1);

    if(isPal(q))
        cout << "It is a palindrome" << endl;
    else
        cout << "not a palindrome " << endl;
}