// check if the array is sorted or not 

#include <iostream>
#include <vector>
using namespace std;

bool isSorted(int n, vector<int> a) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (isSorted(n, a)) {
        cout << "✅ The array is sorted in non-decreasing order." << endl;
    } else {
        cout << "❌ The array is NOT sorted." << endl;
    }

    return 0;
}
