// 🔁 Problem: Reverse the array from index m+1 to the end
// 📌 Approach: Use two-pointer technique to reverse elements from m+1 to end
// ⏱️ Time Complexity: O(n - m)
// 📦 Space Complexity: O(1)
// Direct Hint : Given the array {1,2,3,4,5,6} --> convert it into {1,2,3,4,6,5}

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr, int m) {
    int start = m + 1;
    int end = arr.size() - 1;

    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int m = 2;

    cout << "Original Array: ";
    for(int num : arr) {
        cout << num << " ";
    }

    reverseArray(arr, m);

    cout << "\nArray after reversing from index " << m+1 << ": ";
    for(int num : arr) {
        cout << num << " ";
    }

    return 0;
}
