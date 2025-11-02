// #include<iostream>
// using namespace std;

// Implementation of a node

/*class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
int main(){
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;
    return 0;

}*/

// Implementation of a singly linked list

/*class Node{
    public:
        int data;
        Node* next;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next=head;
    head = temp;
}

void insertAtTail(Node* tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp -> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

int main(){
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;
    
    Node* head = node1;
    Node* tail = node1;
    print(head);
    // insertAtHead(head,12);
    insertAtTail(tail,12);
    print(head);
    // insertAtHead(head,15);
    insertAtTail(tail,15);
    print(head);
    return 0;
}*/


// -------------------Deletion--------------------------

/*#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at tail (helper) - O(n) worst-case
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Print list (helper)
    void print() const {
        Node* temp = head;
        if (!temp) {
            cout << "List: [empty]\n";
            return;
        }
        cout << "List: ";
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Delete at head - O(1)
    void deleteAtHead() {
        if (!head) return;             
        Node* temp = head;             
        head = head->next;             
        delete temp;                  
    }

    // Delete at position (1-indexed). If pos out of range, do nothing.
    void deleteAtPosition(int pos) {
        if (pos <= 0) return;        
        if (!head) return;        

        if (pos == 1) {
            deleteAtHead();
            return;
        }

        Node* prev = head;
        for (int i = 1; i < pos - 1 && prev != nullptr; ++i) {
            prev = prev->next;
        }
        if (!prev || !prev->next) return;

        Node* toDelete = prev->next;
        prev->next = toDelete->next;   
        delete toDelete;               
    }

    void reverseLinkedList() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;  
            curr->next = prev;        
            prev = curr;              
            curr = next;              
        }
        head = prev;                  
    }

    void clearList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    ~LinkedList() {
        clearList();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList ll;
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    cout << "Initial "; ll.print();

    cout << "\nDeleting head...\n";
    ll.deleteAtHead();
    ll.print();

    cout << "\nDeleting at position 2...\n";
    ll.deleteAtPosition(2);
    ll.print(); 

    cout << "\nAttempt to delete at position 10 (out of range)...\n";
    ll.deleteAtPosition(10);
    ll.print(); 

    cout << "\nReversing list...\n";
    ll.reverseLinkedList();
    ll.print(); 

    return 0;
}*/


// ----------------- Doubly linked list -------------------- // 
// Insert at head, tail, Insert at any position, Delete a node(by position), print Forward, print reverse, Length of DLL

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
};
void printForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printBackward(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node*& head, Node*& tail, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Delete Node by Position
void deleteNode(Node*& head, Node*& tail, int pos) {
    if (head == NULL)
        return;
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while (cnt < pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr == NULL)
        return;

    if (curr->next == NULL)
        tail = prev;
    prev->next = curr->next;
    if (curr->next != NULL)
        curr->next->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtPosition(head, tail, 3, 25);

    cout << "DLL (Forward): ";
    printForward(head);
    cout << "DLL (Backward): ";
    printBackward(tail);
    deleteNode(head, tail, 3);
    cout << "After deletion (Forward): ";
    printForward(head);
    cout << "Length: " << getLength(head) << endl;
    return 0;
}
