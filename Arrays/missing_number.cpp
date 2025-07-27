// 📌 Problem: Find the Missing Number in an Array 
// 🔹 Given an array containing `n` distinct numbers in the range [0, n], find the one number that is missing.

// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    return total - sum;
}

int main() {
    int n;
    cout << "Enter number of elements (excluding the missing one): ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements from the range [0, " << n << "] (one missing): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int missing = findMissingNumber(nums);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
