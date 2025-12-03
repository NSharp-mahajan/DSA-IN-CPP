// #include<iostream>
// #define MAX 10
// using namespace std;

/*class my_stack{
    private:
        int items[MAX];
        int count;
    public:
        my_stack(){
            count = 0;
        }
        void push(int item){
            if(count == MAX){
                cout << "Stack Overflow\n";
                return;
            }
            items[count++] = item;
        }
        int pop(){
            if(count == 0){
                cout << "Stack Underflow\n";
                return -1;
            }
            return items[--count];
        }
        int peek(){
            if(count == 0){
                cout << "Stack is empty\n";
                return -1;
            }
            return items[count - 1];
        }
        bool isempty(){
            return count == 0;
        }
        void display(){
            if(count == 0){
                cout << "Stack is empty";
                return;
            }
            cout << "Stack Elements (Top to bottom): ";
            for(int i = count-1; i>=0;i--){
                cout << items[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    my_stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.display();

    cout << "Peek top: " << st.peek() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    st.display();

    cout << "Is stack empty? " << (st.isempty() ? "Yes" : "No") << endl;


    return 0;
}*/

// Using Linked List
/*#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class MyStack {
private:
    Node* top;
    int size;

public:
    MyStack() {
        top = NULL;
        size = 0;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;    // new node points to previous top
        top = newNode;          // update top
        cout << value << " pushed into stack" << endl;
        size++;
    }

    // Pop operation
    int pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int poppedVal = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;            // free memory
        size--;

        cout << poppedVal << " popped from stack" << endl;
        return poppedVal;
    }

    // Peek operation
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if empty
    bool isEmpty() {
        return top == NULL;
    }

    // Get size of stack
    int getSize() {
        return size;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        Node* current = top;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Peek: " << s.peek() << endl;

    s.pop();
    s.pop();

    s.display();

    cout << "Size: " << s.getSize() << endl;

    return 0;
}*/

// Checking for balanced parenthesis (           only ( and )         )

/*#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string str){
    stack<char>s;
    for(char ch : str){
        if(ch == '(')
            s.push(ch);
        else if(ch == ')'){
            if(s.empty())
                return false;
            if(s.top() == '(')
                s.pop();
            else 
                return false;
        }
    }
    return s.empty();
}
int main(){
    cout << (isBalanced("(1 + 2)") ? "Balanced" : "Not Balanced");
    cout << endl;
    cout << (isBalanced("((1+2)") ? "Balanced" : "Not Balanced");
    cout << endl;
}*/

// Checking all the brackets

/*#include<iostream>
#include<stack>
using namespace std;
bool isBal(string str){
    stack<char>st;
    for(char ch : str){
        if(ch == '(' || ch == '{' || ch == '[' || ch == '<'){
            st.push(ch);
        }else if(ch == ')' || ch == '}' || ch == ']' || ch == '>'){
            if(st.empty())
                return false;
            char top = st.top();
            if((ch == ')' && top != '(') || 
               (ch == '}' && top != '{') || 
               (ch == ']' && top != '[') || 
               (ch == '>' && top != '<')){
                return false;
               }
        st.pop();
        }
    }
    return st.empty();
}

int main(){

    cout<<(isBal("{<(1+2)>}") ? "Balanced" : "Not Balanced");
    cout<<endl;
    cout<<(isBal("{(1+2]>}") ? "Balanced" : "Not Balanced");
    cout<<endl;
    
    return 0;
}*/

// Infix to postfix 

/*#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infix_to_postfix(string s){
    stack<char> st;
    string out = "";

    for(char ch : s){
        if(isalnum(ch)){
            out += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                out += st.top();
                st.pop();
            }
            st.pop(); 
        }
        else {
            while(!st.empty() && st.top() != '(' &&
                  precedence(st.top()) >= precedence(ch)) 
            {
                out += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        out += st.top();
        st.pop();
    }

    return out;
}
int main() {
    string exp = "(A+B)*C";
    cout << "Postfix: " << infix_to_postfix(exp) << endl;
    return 0;
}*/

