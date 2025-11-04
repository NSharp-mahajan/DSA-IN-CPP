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
int len(Node* head){
    if(head == nullptr)
        return 0;
    Node* slow = head;
    Node* fast = head;
    bool cycle = false;
    Node* meet = nullptr;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cycle = true;
            meet = slow;
            break;
        }
    }
    if(!cycle)  
        return 0;
    
    int length = 1;
    Node* temp = meet->next;
    while(temp != meet){
        temp = temp->next;
        length++;
    }
    return length;
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
    head->next->next->next->next = head->next;
    
    cout << "List with cycle: ";
    cout << "First few nodes: " << head->data << " -> " << head->next->data << " -> " << head->next->next->data << " -> ... (cycle)" << endl;
    int len_cycle = len(head);
    cout << "Cycle Length: " << len_cycle << endl;

    Node* head_no_cycle = new Node(1);
    head_no_cycle->next = new Node(2);

    cout << "\nList without Cycle: ";
    printList(head_no_cycle);
    int no_len = len(head_no_cycle);
    cout << "Cycle Length: " << no_len << endl;
    
    return 0;
}