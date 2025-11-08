#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* delete_mid(Node* head){  // Fixed: Return Node* (not int)
    if(head == nullptr)
        return nullptr;
    
    Node* prev = nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != nullptr){
        prev->next = slow->next;
    }else{
        head = slow->next;
    }
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        if(temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> Null" << endl;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original (odd): ";
    printList(head);
    head = delete_mid(head);
    cout << "After delete mid: ";
    printList(head);
    
    cout << "\nOriginal (single): ";
    head = new Node(1);
    printList(head);
    head = delete_mid(head);
    cout << "After delete mid: ";
    printList(head);
    
    cout << "\nOriginal (even): ";
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    printList(head);
    head = delete_mid(head);
    cout << "After delete mid: ";
    printList(head);
    
    return 0;
}