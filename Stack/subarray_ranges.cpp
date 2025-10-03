// You are given an integer array nums. The range of a subarray of nums is the difference between the
// largest and smallest element in the subarray. Return the sum of all subarray ranges of nums.

// Brute force approach 

#include <iostream>
#include <vector>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        int minVal = nums[i], maxVal = nums[i];
        for (int j = i; j < n; j++) {
            minVal = min(minVal, nums[j]);
            maxVal = max(maxVal, nums[j]);
            total += (long long)(maxVal - minVal);
        }
    }
    return total;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    if (n < 1 || n > 1000) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] < -1000000000 || nums[i] > 1000000000) {
            cout << "Invalid element value!" << endl;
            return 1;
        }
    }
    long long result = subArrayRanges(nums);
    cout << "Sum of Subarray Ranges: " << result << endl;
    return 0;
}