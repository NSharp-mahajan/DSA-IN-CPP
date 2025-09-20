#include <iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        while (!st.empty()) st.pop();
        mini = INT_MAX;
    }

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            mini = val;
            st.push(value);
        } else {
            if (value < mini) {
                st.push(2LL * value - mini); 
                mini = value;
            } else {
                st.push(value);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long topVal = st.top();
        st.pop();
        if (topVal < mini) {
            mini = 2LL * mini - topVal; 
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long topVal = st.top();
        if (topVal < mini) {
            return (int)mini;
        }
        return (int)topVal;
    }

    int getMin() {
        if (st.empty()) return -1;
        return (int)mini;
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Current Min: " << ms.getMin() << endl;
    ms.pop();
    cout << "Current Min: " << ms.getMin() << endl; 
    ms.pop();
    cout << "Top: " << ms.top() << endl;            
    cout << "Current Min: " << ms.getMin() << endl; 

    return 0;
}
