// Push Front - Insert at beginning

/*#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};
int main(){
    List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.printLL();
}*/

// Push Back (Insert at End)

/*#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
};
class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head = tail = NULL;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main(){
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.printLL();
}*/

// Pop Front (Delete First Node)

/*#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front(){
        if(head == NULL){
            cout << "LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};
int main(){
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    cout << "Before pop_front: ";
    l.printLL();
    l.pop_front();
    cout << "After pop_Front: ";
    l.printLL();
}*/

// Pop Back (Delete Last Node)

/*#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_back() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        if (head == tail) { // only one node
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    cout << "Before pop_back: ";
    l.printLL();
    l.pop_back();
    cout << "After pop_back: ";
    l.printLL();
}*/

// Insert a specific Position 

/*#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insert(int val, int pos){
        if(pos == 0){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1 && temp != NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL)return;
        Node* newNode = new Node(val);
        newNode->next = temp-> next;
        temp->next = newNode;
    }

    void printLL(){
        Node* temp = head;
        while(temp!= NULL){
            cout << temp-> data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    List l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(4);
    cout << "Before Insert: ";
    l.printLL();
    l.insert(2,1);
    cout << "After Insert: ";
    l.printLL();
}*/

// Reverse a list

/*#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode;
        tail = head;
        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    cout << "Before reverse: ";
    l.printLL();

    l.reverse();

    cout << "After reverse: ";
    l.printLL();
}*/

// Search

/*#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    l.printLL();
}*/