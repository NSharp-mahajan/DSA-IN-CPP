#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minst.empty() || val <= minst.top()) {
            minst.push(val);
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() == minst.top()) {
            minst.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Min: " << ms.getMin() << endl;  
    ms.pop();
    cout << "Min: " << ms.getMin() << endl;  
}
