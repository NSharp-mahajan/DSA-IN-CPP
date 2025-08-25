// Brute Force Approach

// Online C++ compiler to run C++ program online
#include <iostream>
#include<climits>
using namespace std;

int kadane(int arr[], int n){
    int max_sum = INT_MIN;
    for(int i = 0; i<n;i++){
        int sum=0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum > max_sum){
                max_sum = sum;
            }
        }
    }
    return max_sum;
}
int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = kadane(arr, n);
    cout << "The maximum subarray sum (brute force) is: " << result << endl;
    return 0;
}