#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* merge(Node* l1, Node* l2){
    Node* temp = new Node(0);  // Dummy head
    Node* tail = temp;  // Fixed: tail = temp (not dummy)
    
    while(l1 != nullptr && l2 != nullptr){
        if(l1->data <= l2->data){
            tail->next = l1;
            l1 = l1->next;
        }else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1 != nullptr){
        tail->next = l1;
    }else{
        tail->next = l2;
    }

    Node* merged_head = temp->next;
    delete temp;  // Fixed: delete temp (not next)
    return merged_head;
}

Node* sortList(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* right = slow->next;
    slow->next = nullptr;

    Node* left = sortList(head);
    Node* right_sorted = sortList(right);
    return merge(left, right_sorted);
}

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        if(temp->next != nullptr)
            cout << " -> ";  // Polished: Space for readability
        temp = temp->next;
    }
    cout << " -> Null" << endl;  // Polished: Consistent style
}

int main(){
    // Test 1: [4,2,1,3] → [1,2,3,4]
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    cout << "Unsorted: ";
    printList(head);
    head = sortList(head);
    cout << "Sorted: ";
    printList(head);

    // Test 2: Single [1] → [1]
    cout << "\nSingle: ";
    head = new Node(1);
    printList(head);
    head = sortList(head);
    printList(head);

    // Test 3: Negatives/mix [-1,5,3,4,0] → [-1,0,3,4,5]
    cout << "\nMix: ";
    head = new Node(-1);
    head->next = new Node(5);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(0);
    printList(head);
    head = sortList(head);
    printList(head);

    return 0;
}