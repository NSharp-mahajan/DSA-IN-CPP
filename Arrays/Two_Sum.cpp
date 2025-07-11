// 📌 Problem: Two Sum
// 🔸 Given an array of integers `nums` and an integer `target`, 
//     return the indices of the two numbers such that they add up to `target`.

// 💡 Approach:
// 🔹 Brute-force approach using two nested loops.
// 🔹 For every index i, check if target - nums[i] exists ahead in the array.

// ⏱ Time Complexity: O(n^2)
// 📦 Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] == target - nums[i]) {
                return {i, j};
            }
        }
    }
    return {}; // in case no solution is found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices of numbers that add up to " << target << " are: ";
    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}
