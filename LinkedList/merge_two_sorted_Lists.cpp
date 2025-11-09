#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next=nullptr;
    }
};

Node* merge_Lists(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        return head1 == NULL ? head2:head1;
    }
    if(head1->data<= head2->data){
        head1->next = merge_Lists(head1->next, head2);
        return head1;
    }else{
        head2->next = merge_Lists(head1,head2->next);
        return head2;
    }
    return nullptr;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!= nullptr){
        cout << temp->data;
        if(temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << "->NULL" << endl;
}

int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);
    Node* merged = merge_Lists(head1, head2);
    cout << "merged: ";
    printList(merged);
}
