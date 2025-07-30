#include <iostream>
using namespace std;

void deleteElement(int a[], int T, int n) {
    int index = -1;

    // Find the index of the element to delete
    for (int i = 0; i < T; i++) {
        if (a[i] == n) {
            index = i;
            break;
        }
    }

    // If element was found, shift all elements after it to the left
    if (index != -1) {
        for (int i = index; i < T - 1; i++) {
            a[i] = a[i + 1];
        }
        T--; // Decrease size after deletion
    }

    // Print the final array
    for (int i = 0; i < T; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int T;
    cin >> T;

    int a[T];
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }

    int n;
    cin >> n;

    deleteElement(a, T, n);

    return 0;
}
