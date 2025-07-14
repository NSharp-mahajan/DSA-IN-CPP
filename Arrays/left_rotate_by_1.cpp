// 📌 Problem: Left Rotate Array by 1 Position
// 🔸 Move the first element to the end and shift all others left

#include<iostream>
#include<vector>
using namespace std;

void left_rotate_by_1(vector<int>& arr){
    if(arr.empty()) return;

    int first = arr[0];
    for(int i = 0; i < arr.size() - 1; i++){
        arr[i - 1] = arr[i];
    };
    arr[arr.size() - 1] = first;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    left_rotate_by_1(arr);
    cout << "Output: ";

    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
