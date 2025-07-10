// 📌 Problem: Find the Second Largest and Second Smallest Element
// 🔸 You are given an array ‘a’ of ‘n’ unique non-negative integers.
// 🔸 Return an array of size 2 containing:
//     [second largest element, second smallest element]

// 💡 Approach:
// 🔹 Traverse the array once to find:
//     → Largest & Second Largest
//     → Smallest & Second Smallest
// 🔹 Use comparisons in a single loop to maintain O(n) time

// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Largest & Second Largest
        if (a[i] > largest) {
            secondLargest = largest;
            largest = a[i];
        } else if (a[i] > secondLargest) {
            secondLargest = a[i];
        }

        // Smallest & Second Smallest
        if (a[i] < smallest) {
            secondSmallest = smallest;
            smallest = a[i];
        } else if (a[i] < secondSmallest) {
            secondSmallest = a[i];
        }
    }

    return {secondLargest, secondSmallest};
}

int main() {
    vector<int> arr = {3, 4, 5, 2};
    int n = arr.size();

    vector<int> result = getSecondOrderElements(n, arr);

    cout << "Second Largest: " << result[0] << endl;
    cout << "Second Smallest: " << result[1] << endl;

    return 0;
}
