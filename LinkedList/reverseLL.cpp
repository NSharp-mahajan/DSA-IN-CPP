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

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr!=nullptr){
        Node* temp = curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
void printList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next != nullptr)
            cout << " -> ";
            temp = temp->next;
    }
    cout << "-> Null" << endl;

}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next=new Node(5);

    cout << "Original Linked list: ";
    printList(head);
    head=reverse(head);
    cout << "reverse list: ";
    printList(head);
    return 0;
}