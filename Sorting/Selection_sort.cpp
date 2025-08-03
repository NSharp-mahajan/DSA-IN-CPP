#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    selection_sort(arr);

    cout << "Sorted array: ";
    for(int val : arr){
        cout << val << " ";
    }

    return 0;
}
