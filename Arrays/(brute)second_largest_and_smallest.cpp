#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in array: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for(int i=0; i < n; i++){
        if(arr[i] > largest){
            secondLargest = largest; 
            largest = arr[i];
        }else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }

        if(arr[i] < smallest){
            secondSmallest = smallest;
            smallest = arr[i];
        }else if(arr[i] < secondSmallest && arr[i] != smallest){
            secondSmallest = arr[i];
        }
    }
    if(secondLargest == INT_MIN){
        cout << "No second largest element \n";
    }else{
        cout << "Second largest: " << secondLargest << endl;
    }

    if(secondSmallest == INT_MAX){
        cout << "No second smallest element \n";
    }else{
        cout << "Second Smallest: " << secondSmallest << endl;
    }
    return 0;
}