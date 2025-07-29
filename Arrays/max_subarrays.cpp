// 📌 Problem: Maximum Subarray (LeetCode 53)
// 🔹 Given an integer array `nums`, find the contiguous subarray with the largest sum and return its sum.

// ⏱ Time Complexity: O(n) — one pass
// 📦 Space Complexity: O(1) — no extra space used

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxSubArray(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}


#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  for(int j=n-1;j>=0;j--)
  {
    cout<<arr[j]<<" ";
  }
  cout<<endl;
}