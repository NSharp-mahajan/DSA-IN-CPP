#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> result(n, -1);
    stack<int> st; 
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i); 
    }
    
    return result;
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;
    
    if (T < 1 || T > 10) {
        cout << "Invalid number of test cases!" << endl;
        return 1;
    }
    while (T--) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;
        if (n < 1 || n > 100000) {
            cout << "Invalid array size!" << endl;
            return 1;
        }
        vector<int> arr(n);
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < 0 || arr[i] > 1000000000) {
                cout << "Invalid element value!" << endl;
                return 1;
            }
        }
        
        vector<int> result = nextSmallerElement(arr, n);
        
        cout << "Next Smaller Elements: ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}