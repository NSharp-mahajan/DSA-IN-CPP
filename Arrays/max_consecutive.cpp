// 📌 Problem: Max Consecutive Ones (LeetCode 485)
// 🔹 Given a binary array `nums`, return the maximum number of consecutive 1s in the array.

// 💡 Approach:
// - Traverse the array while keeping count of continuous 1s.
// - If a 0 is encountered, reset the count.
// - Track the maximum count encountered so far.

// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)

#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutive(const vector<int>& nums){
    int maxi = 0; 
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            count++;
            maxi = max(maxi, count);
        }else{
            count = 0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int result = findMaxConsecutive(nums);
    cout << "Maximum consecutive is: " << result << endl;

    return 0;
}