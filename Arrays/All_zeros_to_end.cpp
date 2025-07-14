// 📌 Problem: Move All Zeros to the End
// 🔸 Rearrange the array so all 0s are at the end while maintaining order of non-zero elements


#include<iostream>
#include<vector>
using namespace std;

void move_zeros(vector<int>& arr){
    int j = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
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
    move_zeros(arr);
    cout << "Output: ";

    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}