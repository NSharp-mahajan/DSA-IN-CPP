// 📌 Problem: Remove Duplicates from Sorted Array (LeetCode 26)
// 🔹 Given a sorted array, remove the duplicates in-place and return the new length.

#include<iostream>
#include<vector>
using namespace std;

int remove_duplicates(vector<int>& nums){
    int i = 0; 
    for(int j = 1; j < nums.size(); j++){
        if(nums[i] != nums[j]){
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int>nums(n);
    cout << "Enter the elements(Sorted): ";
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    int newLen = remove_duplicates(nums);
    cout << "Array after removing duplicates: ";
    for(int i = 0; i<newLen; i++){
        cout << nums[i] << " ";
    }
    return 0;
}