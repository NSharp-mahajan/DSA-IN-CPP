// Program for a linear search
// Taking user input for an array and performing linear search

#include <iostream>
using namespace std;

int SeqSearch(int A[], int key, int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int A[n]; 
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    int result = SeqSearch(A, key, n);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
