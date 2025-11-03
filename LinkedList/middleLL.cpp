#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* middle(Node* head){
    if(!head == !NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast ->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void printList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next!=nullptr)
            cout << "->";
            temp = temp->next;
    }
    cout << "-> NULL" << endl;
}
int main(){
    Node* head = new Node(1);
    head->next= new Node(2);
    head->next->next=new Node(3);
    head->next->next->next = new Node(5);

    cout << "Original LL ";
    printList(head);
    Node* mid = middle(head);
    cout << "Middle node value: " << mid->data << endl;
}