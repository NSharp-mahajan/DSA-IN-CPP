#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next_temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_temp;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* second_half = reverseList(slow->next);
    
    ListNode* first_half = head;
    ListNode* rev_second = second_half;
    while (first_half != nullptr && rev_second != nullptr) {
        if (first_half->val != rev_second->val) {
            
            slow->next = reverseList(second_half);
            return false;
        }
        first_half = first_half->next;
        rev_second = rev_second->next;
    }
    slow->next = reverseList(second_half);
    return true;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> Null" << endl;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    cout << "List: ";
    printList(head);
    cout << "Is Palindrome: " << (isPalindrome(head) ? "true" : "false") << endl;
    head = new ListNode(1, new ListNode(2));
    cout << "\nList: ";
    printList(head);
    cout << "Is Palindrome: " << (isPalindrome(head) ? "true" : "false") << endl;
    
    head = new ListNode(1, new ListNode(2, new ListNode(1)));
    cout << "\nList: ";
    printList(head);
    cout << "Is Palindrome: " << (isPalindrome(head) ? "true" : "false") << endl;
    
    head = new ListNode(1);
    cout << "\nList: ";
    printList(head);
    cout << "Is Palindrome: " << (isPalindrome(head) ? "true" : "false") << endl;
    head = nullptr;
    cout << "\nEmpty: ";
    cout << "Is Palindrome: " << (isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}