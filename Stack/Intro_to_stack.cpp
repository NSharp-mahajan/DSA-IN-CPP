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