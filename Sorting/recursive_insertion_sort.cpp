// 📌 Problem: Sort an Array Using Recursive Insertion Sort
// 🔸 Given an unsorted array, sort it using recursion and insertion sort logic.


// ⏱ Time Complexity: O(n^2)
// 📦 Space Complexity: O(n) due to recursion stack

#include <iostream>
#include <vector>
using namespace std;

void recursiveInsertionSort(vector<int>& nums, int i) {
    int n = nums.size();
    if (i == n) return;

    int j = i;
    while (j > 0 && nums[j - 1] > nums[j]) {
        swap(nums[j], nums[j - 1]);
        j--;
    }

    recursiveInsertionSort(nums, i + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    recursiveInsertionSort(nums, 1);

    cout << "\nSorted array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}

// ~ Written by Natansh Mahajan

