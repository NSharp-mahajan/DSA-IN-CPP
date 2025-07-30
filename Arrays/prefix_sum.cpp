#include<iostream>
#include<vector>
using namespace std;

vector<int> generate_prefix(const vector<int>& arr){
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; ++i){
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

int main(){
    int n;
    cout << "Enter the number of elements: "; 
    cin >> n; 
    
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    vector<int> prefix = generate_prefix(arr);
    cout << "Prefix sum: ";
    for(int val : prefix){
        cout << val << " ";
    }

    return 0;

}