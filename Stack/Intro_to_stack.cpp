/*Stack and Queue are linear data structures 
Stack follows LIFO (last in first Out)
Queue follows FIFO (First in First Out)*/

// Stack Using Arrays 

/*#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[10]; 

public:
    Stack() {
        top = -1;
    }

    void push(int n) {
        if (top >= 9) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = n;
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int size() {
        return top + 1;
    }
};
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.Top() << endl; 
    st.pop();
    cout << "Top after pop: " << st.Top() << endl; 
    cout << "Size: " << st.size() << endl; 

    return 0;
}*/

// Queue using arrays

/*#include <iostream>
using namespace std;

class Queue {
    int arr[10];
    int start, end, currSize, size;

public:
    Queue() {
        size = 10;
        arr[size];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int n) {
        if (currSize == size) {
            cout << "Queue is Full\n";
            return;
        }
        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }
        arr[end] = n;
        currSize++;
    }

    int pop() {
        if (currSize == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }
        int el = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % size;
        }
        currSize--;
        return el;
    }

    int Top() {
        if (currSize == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[start];
    }

    int Size() {
        return currSize;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.Top() << endl; // 1
    cout << "Popped: " << q.pop() << endl; // 1
    cout << "Front now: " << q.Top() << endl; // 2
    cout << "Size: " << q.Size() << endl; // 2

    return 0;
}*/

// Implementing stack using queues

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20

    return 0;
}

// Implementing queues using stacks

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

          if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;
    }
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front: " << q.front() << endl;
    cout << "Popped: " << q.pop() << endl; 
    cout << "Front now: " << q.front() << endl; 
    return 0;
}
