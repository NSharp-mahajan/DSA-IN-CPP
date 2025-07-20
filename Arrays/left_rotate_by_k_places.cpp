// ### 🔁 Left Rotate an Array by K Positions

// 📌 **Problem Statement:**
// Given an array of integers and a number `k`, rotate the array to the left by `k` positions.

// ⏱ Time Complexity: O(n)  
// 📦 Space Complexity:O(k)


#include<iostream>
using namespace std;

void left_rotate_k(int arr[], int n, int d){
    d = d % n;  
    int temp[d];

    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }
    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }

    for(int i = n - d; i < n; i++){
        arr[i] = temp[i - (n - d)];
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];  
    }
    int d;
    cout << "Enter the number of rotations: ";
    cin >> d;

    left_rotate_k(arr, n, d);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
