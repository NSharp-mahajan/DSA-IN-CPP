// 📌 Problem: Sort an Array Using Merge Sort (Divide & Conquer Algorithm)
// 🔸 Given an array of integers, sort it in ascending order using merge sort.

// 💡 Approach (Divide & Conquer):
// 1️⃣ Divide the array into two halves recursively until size becomes 1.
// 2️⃣ Merge the sorted halves using two pointers technique.

// ⏱ Time Complexity: O(n log n)
// 📦 Space Complexity: O(n) – temporary array used for merging

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }

    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); ++k)
        nums[left + k] = temp[k];
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    mergeSort(nums, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : nums)
        cout << num << " ";

    cout << endl;
    return 0;
}

// ~ Written  by Natansh Mahajan
//   📧 : mahajannatansh@gmail.com 