// Find the sum of subarray minimums that means finding the sum of minimum elements of all contiguous subarrays of a given array arr of integers,
// with the result returned modulo $10^9 + 7$. For example, for arr = [3, 1, 2, 4], we consider all subarrays, find their minimums, and sum them up.

// Brute force approach

/*#include<iostream>
#include<vector>
using namespace std;

int subMins(vector<int>&arr){
    const int mod = 1000000007;
    int n = arr.size();
    long long total = 0;

    for(int i = 0; i < n; i++){
        int minVal = arr[i];
        for(int j = i; j < n; j++){
            minVal = min(minVal, arr[j]);
            total = (total + minVal) % mod;
        }
    }
    return total;
}
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    if(n<1 || n > 30000){
        cout << "Invalid size" << endl;
        return 1;
    }
    vector<int> arr(n);
    cout << "Enter " << n << "elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 1 || arr[i] > 30000){
            cout << "Invalid element value: " << endl;
            return 1;

        }
    }
    int result = subMins(arr);
    cout << "Sum of subarray Minimums: " << result << endl;
    return 0;
}*/