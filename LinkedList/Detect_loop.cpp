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
bool floyd(Node* head){
    if(head == nullptr)
        return false;
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            return true;
    }
    return false;
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
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next;  // Cycle: -4 -> 2

    cout << "List with cycle: ";
    cout << "First few nodes: " << head->data << " -> " << head->next->data << " -> " << head->next->next->data << " -> ... (cycle)" << endl;
    bool has_cycle = floyd(head);
    cout << "Has Cycle: " << (has_cycle ? "true" : "false") << endl;
    Node* head_no_cycle = new Node(1);
    head_no_cycle->next = new Node(2);
    cout << "\nList without Cycle: ";
    printList(head_no_cycle);
    bool no_cycle = floyd(head_no_cycle);
    cout << "Has Cycle: " << (no_cycle ? "true" : "false") << endl;
    return 0;
}