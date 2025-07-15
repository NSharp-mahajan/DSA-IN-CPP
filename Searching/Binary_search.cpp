// 📌 Problem: Binary Search (Iterative)
// 🔸 Search for a target in a sorted array using Binary Search

// ⏱ Time & Space Complexity
// Time: O(log n)
// Space: O(1) for iterative, O(log n) for recursive due to stack calls

#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main(){
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int>arr(n);
    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target to search: ";
    cin >> target;

    int result = binary_search(arr,target);
    if(result != -1){
        cout << "Target found at index: " << result << endl;
    }else{
        cout << "Target not found!" << endl;
    }
    return 0;

}