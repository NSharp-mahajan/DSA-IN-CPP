 // Bubble Sort

#include<iostream>
using namespace std;

void Bubble_Sort(int arr[], int n){
    for(int i = n - 1; i >= 1; i--){
        for(int j = 0; j <= i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter" << n << "Elements";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Bubble_Sort(arr,n);
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}