// Brute Force Approach

/*#include<iostream>
#include<vector>
using namespace std;

vector<int> findNextGreater(vector<int>& arr, int n){
    vector<int> nextGreater(n, -1);
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                nextGreater[i] = arr[j];
                break;
            }
        }
    }
    return nextGreater;
}

int main(){
    int n; 
    cout << "Enter size of array: ";
    cin >> n;
    if(n <= 0){
        cout << "Invalid array size ~" << endl;
        return 1;
    }
    vector<int> arr(n);
    cout << "Enter" << n << "elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> result = findNextGreater(arr, n);
    cout << "NExt Greater Elements: ";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}*/

// Optimized Code

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> result(n1, -1); 
    unordered_map<int, int> nge_map; 
    stack<int> st;

    for (int i = 0; i < n2; i++) {
        while (!st.empty() && st.top() < nums2[i]) {
            nge_map[st.top()] = nums2[i]; 
            st.pop();
        }
        st.push(nums2[i]); 
    }
    for (int i = 0; i < n1; i++) {
        if (nge_map.find(nums1[i]) != nge_map.end()) {
            result[i] = nge_map[nums1[i]]; // Get NGE from map
        }
    }
    
    return result;
}

int main() {
    int n1, n2;
    cout << "Enter the size of nums1: ";
    cin >> n1;
    if (n1 <= 0) {
        cout << "Invalid size for nums1!" << endl;
        return 1;
    }
    vector<int> nums1(n1);
    cout << "Enter " << n1 << " elements for nums1: ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }
    
    cout << "Enter the size of nums2: ";
    cin >> n2;
    if (n2 <= 0 || n2 < n1) {
        cout << "Invalid size for nums2!" << endl;
        return 1;
    }
    vector<int> nums2(n2);
    cout << "Enter " << n2 << " elements for nums2: ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }
    vector<int> result = nextGreaterElement(nums1, nums2);
    cout << "Next Greater Elements for nums1: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}