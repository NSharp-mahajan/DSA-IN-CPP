// Insertion Sort

#include <iostream>
using namespace std;

void Insertion_sort(int arr[], int n){
   for(int i = 0; i <= n - 1; i++){
    int j = i;
    while(j > 0 && arr[j - 1] > arr[j]){
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }
   }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    Insertion_sort(arr, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
