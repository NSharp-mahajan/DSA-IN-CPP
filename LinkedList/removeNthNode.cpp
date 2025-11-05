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

Node* removeNthFromEnd(Node* head, int n){
    Node* dummy = new Node(0);  
    dummy->next = head;
    Node* slow = dummy;
    Node* fast = dummy;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    Node* newHead = dummy->next;  
    delete dummy;  
    return newHead;
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

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, 2);
    cout << "After removing 2nd from end: ";
    printList(head);

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "\nOriginal (for head test): ";
    printList(head);

    head = removeNthFromEnd(head, 5);
    cout << "After removing 5th from end (head): ";
    printList(head);
    return 0;
}